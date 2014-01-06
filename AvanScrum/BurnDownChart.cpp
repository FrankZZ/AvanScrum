#include "BurnDownChart.h"

BurnDownChart::BurnDownChart(QCustomPlot* newPlotWidget)
{
	// store the pointer to the plot widget
	plotWidget = newPlotWidget;
	// change the locale to Dutch/Netherlands in order 
	// to display the date and time in the correct format
	plotWidget->setLocale(QLocale(QLocale::Dutch, QLocale::Netherlands));
	// add the two graphs that are always present in a burndown chart
	plotWidget->addGraph();
	plotWidget->addGraph();
	// draw the second line with a red pen (the first is blue because of a default value)
	QColor colourRed (0,255,0);
	QPen redPen(colourRed);
	plotWidget->graph(1)->setPen(redPen);
	// configure bottom axis to show date and time instead of number
	plotWidget->xAxis->setTickLabelType(QCPAxis::ltDateTime);
	plotWidget->xAxis->setDateTimeFormat("dd-MM");
	// set a fixed tick-step to one tick per 5 days (one work week)
	plotWidget->xAxis->setAutoTickStep(false);
	plotWidget->xAxis->setTickStep(60*60*24*7); // 7 days in seconds
	plotWidget->xAxis->setSubTickCount(6);
	// set a more compact font size for bottom and left axis tick labels
	plotWidget->xAxis->setTickLabelFont(QFont(QFont().family(), 6));
	plotWidget->yAxis->setTickLabelFont(QFont(QFont().family(), 6));
	// set the correct labels for each of the axis
	plotWidget->xAxis->setLabel("datum");
	plotWidget->yAxis->setLabel("uren");
	// set axis ranges to show all data
	plotWidget->xAxis->setTickLabelType(QCPAxis::ltDateTime);
	/* default values commented out in order to test/demonstrate the updateGraphView function
	double now = QDateTime::currentDateTime().toTime_t();
	plotWidget->xAxis->setRange(now, now+(60*60*24*14));
	plotWidget->yAxis->setRange(0, 80);*/
	// redraw the plot so that all of the adjustments become visible
	plotWidget->replot();

	//initialise workItemSorter
	workItemSorter = new WorkItemSorter();
}

BurnDownChart::~BurnDownChart()
{
	delete(workItemSorter);
}

void BurnDownChart::test()
{
	QVector<double> date, estimatedHours, realHours;
	double now = QDateTime::currentDateTime().toTime_t();
	double day = (60*60*24);
	for (int i = 0; i < 14; i++)
	{
		int im = 0;
		if (i !=0)
		{
			im = 2-(i*0.2);
		}
		date.push_back(now + i*day);
		estimatedHours.push_front(i*6);
		realHours.push_front((i+im)*6);
	}
	updateGraphView(date, estimatedHours, realHours);
}

void BurnDownChart::updateGraphView(Sprint* sprint)
{
	//make the graph legal by default
	setIllegalGraph(true);

	//create the essential containers
	QVector<double> date, realHours, estimatedHours;

	try
	{
		//haal de huidige sbi's op
		std::vector<WorkItem*> workItems = sprint->getWorkItemArray();
		workItemSorter->sort(workItems);
		std::vector<SprintBacklogItem*> sprintBacklogItems = workItemSorter->getSprintBacklogItems();

		//startdate sprint (estimated)
		double sprintStartDate = getDoubleDate(sprint, true);

		//enddate project (estimated)
		double sprintEndDate = getDoubleDate(sprint, false);

		//calculate difference between first & last day
		double nrOfDaysSprintInSeconds = sprintEndDate - sprintStartDate;
		int nrOfDaysSprint = nrOfDaysSprintInSeconds/(60*60*24)+1;

		//the graph is not suited for sprints of more then 20 days
		//make it invisible if the sprint takes longer then 20 days
		//(assignment states each sprint is always 14 days)
		if(nrOfDaysSprint > 21)
			throw "Exception; the sprint is longer than twenty days (BurnDownChart)";

		//estimatedHours
		double estimatedTotalSprintHours = 0;
		for(int i = 0; i < sprintBacklogItems.size(); i++)
		{
			//sum the estimated hours of all sprint backlog items
			estimatedTotalSprintHours += sprintBacklogItems.at(i)->getBaselineWork();
		}

		//it's useless to show a burndown graph when there is no work
		if(estimatedTotalSprintHours <= 0)
			throw "Exception; there are no estimated hours (BurnDownChart)";

		//calculate the estimated decrease in hours for every day
		double estimatedDailyDecrease = estimatedTotalSprintHours/(double)nrOfDaysSprint;

		//create containers to store data for each day of the sprint
		for (int i = 0; i < nrOfDaysSprint; i++)
		{
			//store the actual dates
			double tempDate = sprintStartDate + ((60*60*24)*i);
			date.push_back(tempDate);

			//calculate & store the estimated hours
			estimatedHours.push_back(estimatedTotalSprintHours - (estimatedDailyDecrease*(i+1)));

			//realHours will be a straight line with no work done
			//we will change the variables in this container later
			realHours.push_back(estimatedTotalSprintHours);
		}

		//calculate & store the real hours
		for(int i = 0; i < sprintBacklogItems.size(); i++)
		{
			//get estimated ammount of work for this sbi
			double estimatedHoursSbi = sprintBacklogItems.at(i)->getBaselineWork();

			//get a list with the history for this sbi
			std::vector<RemainingWorkHistory*> remainingWorkHistorySbi = sprintBacklogItems.at(i)->getRemainingWorkHistoryArray();

			//update the previously filled container (real hours)
			for(int j = 0; j < remainingWorkHistorySbi.size() && remainingWorkHistorySbi.at(j) != NULL; j++)
			{
				//get the date of a mutation in the history of the sprint
				QDate historyDate = QDate(remainingWorkHistorySbi.at(j)->getYear(), remainingWorkHistorySbi.at(j)->getMonth(), remainingWorkHistorySbi.at(j)->getDay());
				QDateTime historyDateTime = QDateTime(historyDate);
				double historyDateDouble = historyDateTime.toTime_t();

				//calculate the difference between the estimated ammount of hours and the realised ammount of hours
				double hoursWorkedDifference = estimatedHoursSbi - remainingWorkHistorySbi.at(j)->getRemainingWork();

				//see if the container has a date that matches the mutation date
				if(!date.contains(historyDateDouble))
				{
					throw "Exception: Date not found (in BurnDownChart)";
				}
				else
				{
					//if it does then lower the ammount of hours on that date with the difference in hours
					for(int k = 0; k < date.size(); k++)
					{
						//fill the real hours
						if(date.at(k) == historyDateDouble)
						{
							realHours.replace(k, realHours.at(k)-hoursWorkedDifference);
						}
						else if(date.at(k) > historyDateDouble)
						{
							realHours.replace(k, realHours.at(k-1));
						}
					}
				}
			}
		}
	}
	catch(char const* e)
	{
		std::cout << e << endl;
		setIllegalGraph(false);
	}
	updateGraphView(date, estimatedHours, realHours);
}

double BurnDownChart::getDoubleDate(Sprint* sprint, bool isStartDate)
{
	QDate qDate;
	if(isStartDate == true)
		qDate = QDate(sprint->getBeginYear(), sprint->getBeginMonth(), sprint->getBeginDay());
	else
		qDate = QDate(sprint->getEndYear(), sprint->getEndMonth(), sprint->getEndDay());

	QDateTime qDateTime = QDateTime(qDate);
	return qDateTime.toTime_t();
}

void BurnDownChart::updateGraphView(
	QVector<double> date, 
	QVector<double> estimatedHours, 
	QVector<double> realHours)
{
	bool sizeIsSuspicious = true;
	bool firstValueIsSupicious = true;

	//check sizes and first values for bogus data
	if(date.size() != 0 &&
		estimatedHours.size() != 0 &&
		realHours.size() != 0)
	{
		sizeIsSuspicious = false;

		if(date.at(0) != NULL &&
			estimatedHours.at(0) != NULL &&
			realHours.at(0) != NULL)
			firstValueIsSupicious = false;
	}

	//update the graph
	if(sizeIsSuspicious == false && firstValueIsSupicious == false)
	{
		plotWidget->graph(0)->setData(date, estimatedHours);
		plotWidget->graph(1)->setData(date, realHours);
		updateAxisRange(date, estimatedHours, realHours);

		// redraw the plot so that all of the adjustments become visible
		plotWidget->replot();
	}
	else
		setIllegalGraph(false);
}

void BurnDownChart::updateAxisRange(
	QVector<double> date, 
	QVector<double> estimatedHours, 
	QVector<double> realHours)
{
	// date range for x-axis
	double firstDate, lastDate = 0;
	firstDate = date.first();
	lastDate = date.last();

	//hours left range
	double lowestAmmountOfHours, highestAmmountOfHours = 0;

	if (realHours.first() > estimatedHours.first())
		highestAmmountOfHours = realHours.first();
	else
		highestAmmountOfHours = estimatedHours.first();

	// set axis ranges to show all data
	plotWidget->xAxis->setRange(firstDate, lastDate);
	plotWidget->yAxis->setRange(lowestAmmountOfHours, highestAmmountOfHours);
}

void BurnDownChart::setIllegalGraph(bool isLegal)
{
	if (isLegal == true)
		plotWidget->setVisible(true);
	else
		plotWidget->setVisible(false);
}
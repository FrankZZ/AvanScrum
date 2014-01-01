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
	QVector<double> estimatedDate, estimatedHours, realDate, realHours;
	double now = QDateTime::currentDateTime().toTime_t();
	double day = (60*60*24);
	for (int i = 0; i < 14; i++)
	{
		int im = 0;
		if (i !=0)
		{
			im = 2-(i*0.2);
		}
		estimatedDate.push_back(now + i*day);
		estimatedHours.push_front(i*6);
		realDate.push_back(now + i*day);
		realHours.push_front((i+im)*6);
	}
	updateGraphView(estimatedDate, estimatedHours, realDate, realHours);
}

void BurnDownChart::updateEstimatedBurndownData(double firstDate, double endDate, double hours)
{
	clearEstimatedBurnDownData();
	estimatedDate.push_back(firstDate);
	estimatedDate.push_back(endDate);
	plotWidget->xAxis->setRange(firstDate, endDate);
	estimatedHours.push_back(hours);
	estimatedHours.push_back(0.0);
	if(hours != 0.0)
		plotWidget->yAxis->setRange(hours, 0.0);
	else
		plotWidget->yAxis->setRange(hours, 40.0);
	plotWidget->graph(0)->setData(estimatedDate, estimatedHours);
	plotWidget->replot();
}

void BurnDownChart::clearEstimatedBurnDownData()
{
	estimatedDate.clear();
	estimatedHours.clear();
}

void BurnDownChart::updateRealisedBurnDownData(double firstDate, double endDate, double hours)
{

}

void BurnDownChart::legacy()
{
	//haal de huidige sprint op
	/*QVector<double> estimatedDate, estimatedHours, realDate, realHours;
	Sprint* sp = sprintVector.at(index);

	//haal de huidige sbi's op
	std::vector<WorkItem*> workItems = sp->getWorkItemArray();
	workItemSorter->sort(workItems);
	std::vector<SprintBacklogItem*> sprintBacklogItems = wis->getSprintBacklogItems();

	//haal de verwachte- en gerealiseerde tijd van iedere sprint op
	int expectedSprintTime = 0;
	for(int i = 0; i < sprintBacklogItems.size(); i++)
	{
		expectedSprintTime += sprintBacklogItems.at(i)->getBaselineWork();
	}

	//startdate sprint (estimated)
	QDate beginDate = QDate(sp->getBeginYear(), sp->getBeginMonth(), sp->getBeginDay());
	QDateTime beginDateTime = QDateTime(beginDate);
	double sprintStartDate = beginDateTime.toTime_t();
	realDate.push_back(sprintStartDate);

	//enddate project (estimated)
	QDate endDate = QDate(sp->getEndYear(), sp->getEndMonth(), sp->getEndDay()+1);
	QDateTime endDateTime = QDateTime(endDate);
	double projectEndDate = endDateTime.toTime_t();
	realDate.push_back(projectEndDate);

	//estimatedHours
	int estimatedHours1 = 0;
	for(int i = 0; i < sprintBacklogItems.size(); i++)
	{
		estimatedHours1 += sprintBacklogItems.at(i)->getBaselineWork();
	}

	//realhours

	estimatedHours.push_back(estimatedHours1);
	estimatedHours.push_back(0.0);
	realHours.push_back(estimatedHours1);
	realHours.push_back(0.0);*/

	//bdc->updateGraphView(estimatedDate, estimatedHours, realDate, realHours);
}

void BurnDownChart::updateGraphView(Sprint* sprint)
{
	//haal de huidige sbi's op
	std::vector<WorkItem*> workItems = sprint->getWorkItemArray();
	workItemSorter->sort(workItems);
	std::vector<SprintBacklogItem*> sprintBacklogItems = workItemSorter->getSprintBacklogItems();

	//startdate sprint (estimated)
	QDate beginDate = QDate(sprint->getBeginYear(), sprint->getBeginMonth(), sprint->getBeginDay());
	QDateTime beginDateTime = QDateTime(beginDate);
	double sprintStartDate = beginDateTime.toTime_t();

	//enddate project (estimated)
	QDate endDate = QDate(sprint->getEndYear(), sprint->getEndMonth(), sprint->getEndDay());
	QDateTime endDateTime = QDateTime(endDate);
	double sprintEndDate = endDateTime.toTime_t();

	//estimatedHours
	int estimatedHours = 0;
	for(int i = 0; i < sprintBacklogItems.size(); i++)
	{
		estimatedHours += sprintBacklogItems.at(i)->getBaselineWork();
	}
	updateEstimatedBurndownData(sprintStartDate, sprintEndDate, estimatedHours);
}

void BurnDownChart::updateGraphView(
	QVector<double> estimatedDate, 
	QVector<double> estimatedHours, 
	QVector<double> realDate, 
	QVector<double> realHours)
{
	plotWidget->graph(0)->setData(estimatedDate, estimatedHours);
	plotWidget->graph(1)->setData(realDate, realHours);

	updateAxisRange(estimatedDate, estimatedHours, realDate, realHours);

	// redraw the plot so that all of the adjustments become visible
	plotWidget->replot();
}

void BurnDownChart::updateAxisRange(
	QVector<double> estimatedDate, 
	QVector<double> estimatedHours, 
	QVector<double> realDate, 
	QVector<double> realHours)
{
	// date range for x-axis
	double firstDate, lastDate = 0;
	if (realDate.first() < estimatedDate.first())
		firstDate = realDate.first();
	else
		firstDate = estimatedDate.first();

	if (realDate.last() > estimatedDate.last())
		lastDate = realDate.last();
	else
		lastDate = estimatedDate.last();

	//hours left range
	double lowestAmmountOfHours, highestAmmountOfHours = 0;
	if (realHours.first() < estimatedHours.first())
		lowestAmmountOfHours = realHours.first();
	else
		lowestAmmountOfHours = estimatedHours.first();

	if (realHours.last() > estimatedHours.last())
		highestAmmountOfHours = realHours.last();
	else
		highestAmmountOfHours = estimatedHours.last();
	
	// set axis ranges to show all data
	plotWidget->xAxis->setRange(firstDate, lastDate);
	plotWidget->yAxis->setRange(lowestAmmountOfHours, highestAmmountOfHours);
}
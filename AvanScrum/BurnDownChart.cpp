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
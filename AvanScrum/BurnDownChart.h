#ifndef BurnDownChart_h
#define BurnDownChart_h

#include "AvanScrum.h"
#include "WorkItemSorter.h"
#include <iostream>
#include <string>
#include "TFS\Sprint.h"
#include "TFS\RemainingWorkHistory.h"

class BurnDownChart
{
private: 
	QCustomPlot* plotWidget;
	WorkItemSorter* workItemSorter;
	//QVector<double> estimatedDate, estimatedHours, realDate, realHours;

public: 
	BurnDownChart(QCustomPlot*);
	~BurnDownChart();
	void test();
	double getDoubleDate(Sprint*, bool isStartDate);
	void updateGraphView(QVector<double>, QVector<double>, QVector<double>);
	void updateAxisRange(QVector<double>, QVector<double>, QVector<double>);
	void updateGraphView(Sprint*);
	void setIllegalGraph(bool isLegal);
};

#endif
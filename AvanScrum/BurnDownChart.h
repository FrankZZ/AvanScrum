#ifndef BurnDownChart_h
#define BurnDownChart_h

#include "AvanScrum.h"
#include "WorkItemSorter.h"
#include "TFS\Sprint.h"

class BurnDownChart
{
private: 
	QCustomPlot* plotWidget;
	WorkItemSorter* workItemSorter;
	QVector<double> estimatedDate, estimatedHours, realDate, realHours;

public: 
	BurnDownChart(QCustomPlot*);
	~BurnDownChart();
	void test();
	void updateGraphView(QVector<double>, QVector<double>, QVector<double>, QVector<double>);
	void updateAxisRange(QVector<double>, QVector<double>, QVector<double>, QVector<double>);
	void updateGraphView(Sprint*);
	void updateEstimatedBurndownData(double, double, double);
	void clearEstimatedBurnDownData();
	void updateRealisedBurnDownData(double, double, double);
	void legacy();
};

#endif
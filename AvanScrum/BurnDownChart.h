#include "AvanScrum.h"

class BurnDownChart
{
public:


private: 
	QCustomPlot* plotWidget;

private:


public: 
	BurnDownChart(QCustomPlot*);
	~BurnDownChart();
	void test();
	void updateGraphView(QVector<double>, QVector<double>, QVector<double>, QVector<double>);
	void updateAxisRange(QVector<double>, QVector<double>, QVector<double>, QVector<double>);
};
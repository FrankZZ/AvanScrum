#include "BurnDownChart.h"

BurnDownChart::BurnDownChart(QCustomPlot* newPlotWidget)
{
	plotWidget = newPlotWidget;
	plotWidget->addGraph();
	plotWidget->addGraph();
	plotWidget->xAxis->setLabel("sprints");
	plotWidget->yAxis->setLabel("uren");
	plotWidget->xAxis->setRange(0, 10);
	plotWidget->yAxis->setRange(0, 10);
	QColor colourRed (255,0,0);
	QPen redPen(colourRed);
	plotWidget->graph(1)->setPen(redPen);
	plotWidget->replot();
}

void BurnDownChart::test()
{
	QVector<double> estimatedX, estimatedY, realisedX, realisedY;
	for (int i = 0; i < 10; i++)
	{
		int im = 0;
		if (i !=0)
		{
			im = 2-(i*0.2);
		}
		estimatedX.push_back(i);
		estimatedY.push_front(i);
		realisedX.push_back(i);
		realisedY.push_front(i+im);
	}
	updateGraphView(estimatedX, estimatedY, realisedX, realisedY);
}

void BurnDownChart::updateGraphView(QVector<double> estimatedX, QVector<double> estimatedY, QVector<double> realisedX, QVector<double> realisedY)
{
	plotWidget->graph(0)->setData(estimatedX, estimatedY);
	plotWidget->graph(1)->setData(realisedX, realisedY);
	plotWidget->replot();
}
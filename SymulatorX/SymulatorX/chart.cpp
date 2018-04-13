#include "chart.h"

Chart::Chart(QCustomPlot *ptr, unsigned int graphNum)
{
    graphNumber=graphNum;
    customPlot=ptr;
    customPlot->addGraph();  // blue line
    customPlot->graph(graphNumber)->setPen(QPen(QColor(40, 110, 255*graphNumber)));

}
Chart::Chart(unsigned int graphsNumber)
{
    customPlot = new QCustomPlot();
    customPlot->addGraph();  // blue line
    customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
    for (int i=1; i<graphsNumber;i++)
    {
        customPlot->addGraph();  // red line
        customPlot->graph(i)->setPen(QPen());
    }
    customPlot->axisRect()->setupFullAxesBox();
}

void Chart::draw (double wartsc)
{
    // add data to lines:
    customPlot->graph(graphNumber)->addData(time, wartsc);
    //customPlot->graph(1)->addData(key, w);
    // rescale value (vertical) axis to fit the current data:
    customPlot->graph(graphNumber)->rescaleValueAxis(false,true);
    //customPlot->graph(1)->rescaleValueAxis();

    // scroll x axis with 500 range
    customPlot->xAxis->setRange(time, 500, Qt::AlignRight);
    customPlot->replot();
    time++;
}
void Chart::draw (std::vector<double> wartsc)
{
    // add data to lines:
        customPlot->graph(graphNumber)->addData(time, wartsc[graphNumber]);
        //customPlot->graph(graphNumber)->rescaleValueAxis(false,true);
        customPlot->yAxis->rescale(true);

    // scroll x axis with 500 range
    customPlot->xAxis->setRange(time, 500, Qt::AlignRight);
    customPlot->replot();
    time++;
}
void Chart::update (double wartosc)
{
    draw(wartosc);
}
void Chart::update (std::vector<double> wartosc)
{
    draw(wartosc);
}
QCustomPlot* Chart::getHandle()
{
    return customPlot;
}

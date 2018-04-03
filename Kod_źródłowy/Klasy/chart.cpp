#include "chart.h"

Chart::Chart()
{
    customPlot = new QCustomPlot();
    customPlot->addGraph();  // blue line
    customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
    customPlot->addGraph();  // red line
    customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));
    customPlot->axisRect()->setupFullAxesBox();
}

void Chart::draw (double wartsc)
{
    // add data to lines:
    customPlot->graph(0)->addData(time, wartsc);
    //customPlot->graph(1)->addData(key, w);
    // rescale value (vertical) axis to fit the current data:
    customPlot->graph(0)->rescaleValueAxis(false,true);
    //customPlot->graph(1)->rescaleValueAxis();

    // scroll x axis with 500 range
    customPlot->xAxis->setRange(time, 500, Qt::AlignRight);
    customPlot->replot();
    time++;
}
void Chart::update (double wartosc)
{
    draw(wartosc);
}
QCustomPlot* Chart::getHandle()
{
    return customPlot;
}

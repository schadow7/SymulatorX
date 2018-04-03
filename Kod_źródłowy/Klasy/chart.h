#ifndef CHART2_H
#define CHART2_H
#include "observer.h"
#include "qcustomplot.h"

class Chart :public Observer
{
    QCustomPlot *customPlot;
    unsigned int time=0;
public:
    Chart();
    virtual void update (double wartosc);
    void draw(double wartosc);
    QCustomPlot* getHandle();
};

#endif // CHART2_H

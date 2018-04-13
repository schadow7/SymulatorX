#ifndef CHART2_H
#define CHART2_H
#include "observer.h"
#include "qcustomplot.h"

//*Klasa pojedyńczego wykresu. Powiadamiana wzorcem obserwator*//
class Chart :public Observer
{
    QCustomPlot *customPlot;
    unsigned int graphNumber;
    unsigned int time=0;
public:
    /** graphsNumber- liczba przebiegów na wykresie.*/
    Chart(QCustomPlot *ptr,unsigned int graphNumber=0);
    Chart(unsigned int graphNumber=0);
    virtual void update (double wartosc);
    virtual void update (std::vector<double> wartosc);
    void draw(double wartosc);
    void draw(std::vector<double> wartosc);
    QCustomPlot* getHandle();
};

#endif // CHART2_H


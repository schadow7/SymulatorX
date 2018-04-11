#ifndef CHART2_H
#define CHART2_H
#include "observer.h"
#include "qcustomplot.h"

//*Klasa pojedyńczego wykresu. Powiadamiana wzorcem obserwator*//
class Chart :public Observer
{
    QCustomPlot *customPlot;
    unsigned int time=0;
public:
    /** graphsNumber- liczba przebiegów na wykresie.*/
    Chart(unsigned int graphsNumber=1);
    virtual void update (double wartosc);
    virtual void update (std::vector<double> wartosc);
    void draw(double wartosc);
    void draw(std::vector<double> wartosc);
    QCustomPlot* getHandle();
};

#endif // CHART2_H


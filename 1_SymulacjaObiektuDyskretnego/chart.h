#ifndef WYKRES_H
#define WYKRES_H

#include <QtCharts>
#include <QMainWindow>
#include "observer.h"

class Chart : public Observer {
    QChart *m_chart;
    QLineSeries *m_series;
    double time;
    QString m_title;
    QChartView *chartView;
    QValueAxis *axX;
    QValueAxis *axY;
    unsigned int m_range=500,axMin=0,axMax=m_range;
public:

    Chart(QString m_title);
    Chart();
    ~Chart();
    QChartView* getHandle();
    virtual void update (double wartosc);
    void draw(double wartosc);
QValueAxis* axisX();
QValueAxis* axisY();
};

#endif // WYKRES_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <chart.h>
#include <proces.h>
#include <QTimer>
#include<vector>
#include <polymonial.h>
#include"objectdiscrete.h"

using namespace QtCharts;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected slots:
   void run();
   void setTimerInterval(int);
private:
    Ui::MainWindow *ui;

    void setPlot();
    QGridLayout *setLayout();
    int tempo=100;
    QGridLayout *main_layout;
    QWidget *window;
    QWidget *w1;
    Chart *wyk1, *wyk2;
    proces *sinus, *csinus;
    QChartView* chart_handle;
    QTimer *timer;
    double Wzadana=0;
    QChartView *view_wykrestestowy;
    QSlider *speedSlider;
    QTimer* setTimer();
    QSlider* setSpeedSlider();
    ObjectDiscrete *obiektTestowy;
};

#endif // MAINWINDOW_H

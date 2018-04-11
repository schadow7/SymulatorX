#ifndef SIMULATIONTAB_H
#define SIMULATIONTAB_H

#include <QWidget>
#include "chart.h"
class QPushButton;
class QSlider;
class QSpinBox;

class SimulationTab : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationTab(QWidget *parent = nullptr);
    ~SimulationTab();
    Chart* getChartHandle(int);

signals:
    int sliderChange(int);
    void clickedStart();
    void setVariable(int);
public slots:

private:
    void createLayout();
    QPushButton *m_button_start;
    Chart * m_chart_top;
    Chart * m_chart_bottom;
    QSlider *m_speed_slider;
    QSpinBox *m_setpoint_spinbox;

};

#endif // SIMULATIONTAB_H

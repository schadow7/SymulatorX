#ifndef SIMULATIONTAB_H
#define SIMULATIONTAB_H

#include <QWidget>
#include "chart.h"
class QPushButton;
class QSlider;
class QSpinBox;
/**
 * @brief Klasa zakładki symulacji dostarczająca interfejs graficzny do symulacji pętli regulacji dla klasy Simulator
 */
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
    void rectGeneratorParam(double, unsigned int, unsigned int);
    void rectGeneratorState(bool);
    void sinGeneratorParam(double,unsigned int);
    void sinGeneratorState(bool);
    void triangGeneratorParam(double,unsigned int);
    void triangGeneratorState(bool);
    void randGeneratorParam(double);
    void randGeneratorState(bool);
    void regulatorPParam(double);
public slots:
private slots:
    void rectGeneratorChange();
    void rectGenerator(bool);
    void sinGeneratorChange();
    void sinGenerator(bool);
    void triangGeneratorChange();
    void triangGenerator(bool);
    void randGeneratorChange();
    void randGenerator(bool);
    void regulatorChange();
private:
    void createLayout();
    QPushButton *m_button_start;
    Chart * m_chart_top0, *m_chart_top1;
    Chart * m_chart_bottom0,*m_chart_bottom1;
    QSlider *m_speed_slider;
    QSpinBox *m_setpoint_spinbox;
    QCheckBox * m_check_rect,*m_check_sin,*m_check_triang,*m_check_rand;
    QLabel * m_label_amp_rect, *m_label_per_rect,*m_label_gam_rect;
    QLabel * m_label_amp_sin,*m_label_per_sin;
    QLabel * m_label_var_rand;
    QLabel * m_label_amp_triang,*m_label_per_triang;
    QDoubleSpinBox * m_amplitude_rect,*m_amplitude_sin,*m_amplitude_triang,*m_var_rand;
    QDoubleSpinBox *m_P_param;
    QSpinBox * m_period_rect,*m_period_sin,*m_period_triang;
    QSpinBox * m_gamma_rect;


};

#endif // SIMULATIONTAB_H

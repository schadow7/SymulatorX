#include "simulationtab.h"
#include <QtWidgets>

SimulationTab::SimulationTab(QWidget *parent) : QWidget(parent)
{
createLayout();

//connect(m_speed_slider, QOverload<int>::of(&QSlider::valueChanged), [=](int i){ setTimerInterval(i); });
connect(m_speed_slider,SIGNAL(valueChanged(int)),this,SIGNAL(sliderChange(int)));
connect(m_button_start,SIGNAL(clicked()),this,SIGNAL(clickedStart()));
connect(m_setpoint_spinbox,SIGNAL(valueChanged(int)),this,SIGNAL(setVariable(int)));

connect(m_check_rect,SIGNAL(toggled(bool)),this,SLOT(rectGenerator(bool)));
connect(m_amplitude_rect,SIGNAL(valueChanged(double)),this,SLOT(rectGeneratorChange()));
connect(m_period_rect,SIGNAL(valueChanged(int)),this,SLOT(rectGeneratorChange()));
connect(m_gamma_rect,SIGNAL(valueChanged(int)),this,SLOT(rectGeneratorChange()));

connect(m_check_sin,SIGNAL(toggled(bool)),this,SLOT(sinGenerator(bool)));
connect(m_amplitude_sin,SIGNAL(valueChanged(double)),this,SLOT(sinGeneratorChange()));
connect(m_period_sin,SIGNAL(valueChanged(int)),this,SLOT(sinGeneratorChange()));

connect(m_check_triang,SIGNAL(toggled(bool)),this,SLOT(triangGenerator(bool)));
connect(m_amplitude_triang,SIGNAL(valueChanged(double)),this,SLOT(triangGeneratorChange()));
connect(m_period_triang,SIGNAL(valueChanged(int)),this,SLOT(triangGeneratorChange()));

connect(m_check_rand,SIGNAL(toggled(bool)),this,SLOT(randGenerator(bool)));
connect(m_var_rand,SIGNAL(valueChanged(double)),this,SLOT(randGeneratorChange()));

connect(m_P_param,SIGNAL(valueChanged(double)),this,SLOT(regulatorChange()));


}
SimulationTab::~SimulationTab()
{
    delete m_chart_top0;
    delete m_chart_top1;
    delete m_chart_bottom0;
    delete m_chart_bottom1;
}

void SimulationTab::createLayout()
{
    QGridLayout * layout = new QGridLayout;

    m_button_start= new QPushButton("Start");
    QCustomPlot *chart1=new QCustomPlot;
    m_chart_top0=new Chart(chart1,0);
    m_chart_top1=new Chart(chart1,1);
    QCustomPlot *chart2=new QCustomPlot;
    m_chart_bottom0=new Chart(chart2,0);
    m_chart_bottom1=new Chart(chart2,1);
    m_speed_slider= new QSlider(Qt::Horizontal);
    m_setpoint_spinbox=new QSpinBox();
    //Parametry regulatora
    m_P_param= new QDoubleSpinBox();
    //Sekcja generatora prostokątnego
    m_check_rect=new QCheckBox("Rectangular",this);
    m_amplitude_rect=new QDoubleSpinBox(this);
    m_period_rect=new QSpinBox(this);
    m_gamma_rect=new QSpinBox(this);
    m_label_amp_rect=new QLabel("Amplitude:",this);
    m_label_per_rect=new QLabel("Period:",this);
    m_label_gam_rect=new QLabel("Gamma:",this);
    //Generator sinusoidalny
    m_check_sin=new QCheckBox("Sinusoid",this);
    m_amplitude_sin=new QDoubleSpinBox(this);
    m_period_sin=new QSpinBox(this);
    m_label_amp_sin=new QLabel("Amplitude:",this);
    m_label_per_sin=new QLabel("Period:",this);
    //Generator trójkątny
    m_check_triang=new QCheckBox("Triangle",this);
    m_amplitude_triang=new QDoubleSpinBox(this);
    m_period_triang=new QSpinBox(this);
    m_label_amp_triang=new QLabel("Amplitude:",this);
    m_label_per_triang=new QLabel("Period:",this);
    //Generator białego szumu
    m_check_rand=new QCheckBox("Noise",this);
    m_var_rand=new QDoubleSpinBox(this);
    m_label_var_rand=new QLabel("Variance:",this);

    layout->addWidget(m_chart_top0->getHandle(),0,3,8,6);
    m_chart_top0->getHandle()->setMinimumSize(600, 200);
    layout->addWidget(m_chart_bottom0->getHandle(),8,3,8,6);
    m_chart_bottom0->getHandle()->setMinimumSize(600, 200);

    //Wartosc zadana
    layout->addWidget(new QLabel(tr("Set point:")), 0,1,1,1,Qt::AlignLeft);
    layout->addWidget(m_setpoint_spinbox,0,2,1,1,Qt::AlignRight);

    //Generator prostokątny
    layout->addWidget(m_check_rect,1,1,1,2,Qt::AlignHCenter);
    layout->addWidget(m_label_amp_rect,2,1,1,1,Qt::AlignLeft);
    m_label_amp_rect->setVisible(false);
    layout->addWidget(m_amplitude_rect,2,2,1,1,Qt::AlignRight);
    m_amplitude_rect->setSingleStep(0.1);
    m_amplitude_rect->setDecimals(2);
    m_amplitude_rect->setMaximum(9999);
    m_amplitude_rect->setMinimum(-9999);
    m_amplitude_rect->setVisible(false);
    layout->addWidget(m_label_per_rect,3,1,1,1,Qt::AlignLeft);
    m_label_per_rect->setVisible(false);
    layout->addWidget(m_period_rect,3,2,1,1,Qt::AlignRight);
    m_period_rect->setSingleStep(1);
    m_period_rect->setMaximum(9999);
    m_period_rect->setMinimum(2);
    m_period_rect->setVisible(false);
    layout->addWidget(m_label_gam_rect,4,1,1,1,Qt::AlignLeft);
    m_label_gam_rect->setVisible(false);
    layout->addWidget(m_gamma_rect,4,2,1,1,Qt::AlignRight);
    m_gamma_rect->setSingleStep(1);
    m_gamma_rect->setMaximum(100);
    m_gamma_rect->setMinimum(0);
    m_gamma_rect->setVisible(false);

    //Generator sinusoidalny
    layout->addWidget(m_check_sin,5,1,1,2,Qt::AlignHCenter);
    layout->addWidget(m_label_amp_sin,6,1,1,1,Qt::AlignLeft);
    m_label_amp_sin->setVisible(false);
    layout->addWidget(m_amplitude_sin,6,2,1,1,Qt::AlignRight);
    m_amplitude_sin->setSingleStep(0.1);
    m_amplitude_sin->setDecimals(2);
    m_amplitude_sin->setMaximum(9999);
    m_amplitude_sin->setMinimum(-9999);
    m_amplitude_sin->setVisible(false);
    layout->addWidget(m_label_per_sin,7,1,1,1,Qt::AlignLeft);
    m_label_per_sin->setVisible(false);
    layout->addWidget(m_period_sin,7,2,1,1,Qt::AlignRight);
    m_period_sin->setSingleStep(1);
    m_period_sin->setMaximum(9999);
    m_period_sin->setMinimum(1);
    m_period_sin->setVisible(false);

    //Generator sinusoidalny
    layout->addWidget(m_check_triang,8,1,1,2,Qt::AlignHCenter);
    layout->addWidget(m_label_amp_triang,9,1,1,1,Qt::AlignLeft);
    m_label_amp_triang->setVisible(false);
    layout->addWidget(m_amplitude_triang,9,2,1,1,Qt::AlignRight);
    m_amplitude_triang->setSingleStep(0.1);
    m_amplitude_triang->setDecimals(2);
    m_amplitude_triang->setMaximum(9999);
    m_amplitude_triang->setMinimum(-9999);
    m_amplitude_triang->setVisible(false);
    layout->addWidget(m_label_per_triang,10,1,1,1,Qt::AlignLeft);
    m_label_per_triang->setVisible(false);
    layout->addWidget(m_period_triang,10,2,1,1,Qt::AlignRight);
    m_period_triang->setSingleStep(4);
    m_period_triang->setMaximum(9999);
    m_period_triang->setMinimum(4);
    m_period_triang->setVisible(false);

    //Generator białego szumu
    layout->addWidget(m_check_rand,11,1,1,2,Qt::AlignHCenter);
    layout->addWidget(m_label_var_rand,12,1,1,1,Qt::AlignLeft);
    m_label_var_rand->setVisible(false);
    layout->addWidget(m_var_rand,12,2,1,1,Qt::AlignRight);
    m_var_rand->setSingleStep(0.01);
    m_var_rand->setDecimals(2);
    m_var_rand->setMaximum(999);
    m_var_rand->setMinimum(0.0);
    m_var_rand->setValue(0.0);
    m_var_rand->setVisible(false);

    //Parametry regulatora
    layout->addWidget(new QLabel(tr("P:")), 13,1,1,1,Qt::AlignLeft);
    layout->addWidget(m_P_param,13,2);

    //slider tempa symulacji
    m_speed_slider->setRange(0,1000);
    m_speed_slider->setValue(100);
    layout->addWidget(m_speed_slider,16,5);

    //Przycisk START
    layout->addWidget(m_button_start,16,2);

    setLayout(layout);
}
Chart* SimulationTab::getChartHandle(int id)
{
if (id==0) return m_chart_top0;
if (id==1) return m_chart_top1;
if (id==2) return m_chart_bottom0;
if (id==3) return m_chart_bottom1;
else return nullptr;
}

void SimulationTab::rectGenerator(bool p)
{
        m_amplitude_rect->setVisible(p);
        m_period_rect->setVisible(p);
        m_gamma_rect->setVisible(p);
        m_label_amp_rect->setVisible(p);
        m_label_per_rect->setVisible(p);
        m_label_gam_rect->setVisible(p);
        emit rectGeneratorState(p);
}

void SimulationTab::rectGeneratorChange()
{
    emit rectGeneratorParam(m_amplitude_rect->value(),m_period_rect->value(),m_gamma_rect->value());
}

void SimulationTab::sinGenerator(bool p)
{
        m_amplitude_sin->setVisible(p);
        m_period_sin->setVisible(p);
        m_label_amp_sin->setVisible(p);
        m_label_per_sin->setVisible(p);
        emit sinGeneratorState(p);
}

void SimulationTab::sinGeneratorChange()
{
    emit sinGeneratorParam(m_amplitude_sin->value(),m_period_sin->value());
}

void SimulationTab::triangGenerator(bool p)
{
    m_amplitude_triang->setVisible(p);
    m_period_triang->setVisible(p);
    m_label_amp_triang->setVisible(p);
    m_label_per_triang->setVisible(p);
    emit triangGeneratorState(p);
}

void SimulationTab::triangGeneratorChange()
{
    emit triangGeneratorParam(m_amplitude_triang->value(),m_period_triang->value());
}


void SimulationTab::randGenerator(bool p)
{
    m_var_rand->setVisible(p);
    m_label_var_rand->setVisible(p);
    emit randGeneratorState(p);
}

void SimulationTab::randGeneratorChange()
{
    emit randGeneratorParam(m_var_rand->value());
}
void SimulationTab::regulatorChange()
{
    emit regulatorPParam(m_P_param->value());
}

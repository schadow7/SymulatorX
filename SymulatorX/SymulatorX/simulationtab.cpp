#include "simulationtab.h"
#include <QtWidgets>

SimulationTab::SimulationTab(QWidget *parent) : QWidget(parent)
{
createLayout();

//connect(m_speed_slider, QOverload<int>::of(&QSlider::valueChanged), [=](int i){ setTimerInterval(i); });
connect(m_speed_slider,SIGNAL(valueChanged(int)),this,SIGNAL(sliderChange(int)));
connect(m_button_start,SIGNAL(clicked()),this,SIGNAL(clickedStart()));
connect(m_setpoint_spinbox,SIGNAL(valueChanged(int)),this,SIGNAL(setVariable(int)));
}
SimulationTab::~SimulationTab()
{
    delete m_chart_top;
    delete m_chart_bottom;
}

void SimulationTab::createLayout()
{
    QGridLayout * layout = new QGridLayout;

    m_button_start= new QPushButton("Start");
    m_chart_top=new Chart(2);
    m_chart_bottom=new Chart(1);
    m_speed_slider= new QSlider(Qt::Horizontal);
    m_setpoint_spinbox=new QSpinBox();
    //layout->setColumnStretch(1,3);

    layout->addWidget(m_chart_top->getHandle(),0,2,4,6);
    m_chart_top->getHandle()->setMinimumSize(600, 200);
    layout->addWidget(m_chart_bottom->getHandle(),4,2,4,6);
    m_chart_bottom->getHandle()->setMinimumSize(600, 200);

    //Wartosc zadana
    layout->addWidget(new QLabel(tr("<center>Set point</center>")), 0,1,1,1,Qt::AlignCenter);
    layout->addWidget(m_setpoint_spinbox,1,1,1,1,Qt::AlignTop);

    //slider tempa symulacji
    m_speed_slider->setRange(0,1000);
    m_speed_slider->setValue(100);
    layout->addWidget(m_speed_slider,8,5);

    //Przycisk START
    layout->addWidget(m_button_start,8,1);



    setLayout(layout);
}
Chart* SimulationTab::getChartHandle(int id)
{
if (id==1) return m_chart_top;
if (id==2) return m_chart_bottom;
else return nullptr;
}

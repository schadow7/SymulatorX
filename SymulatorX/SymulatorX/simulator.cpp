#include "simulator.h"
#include "configurationtab.h"
#include "simulationtab.h"
#include "controlloop.h"
#include "objectdiscrete.h"
#include "regulatorpid.h"
#include <exception>
#include <string>
#include <QtWidgets>

using namespace std;

Simulator::Simulator(QWidget *parent) : QTabWidget(parent)
{
    //Nie ustawiany jest parrent, bo przy addTab jest automatycznie ustawiany
    m_current_target=OBJECT;
    ObjectSISO* ptr=new ObjectDiscrete;
    Regulator *ptr2=new RegulatorPID;
    m_loop=new ControlLoop(ptr,ptr2);

    m_simTab=new SimulationTab();
    m_confTab=new ConfigurationTab();

    addTab(m_simTab,tr("Simulation"));
    addTab(m_confTab,tr("Configuration"));

    connect(m_confTab,SIGNAL(clickedObject()),this, SLOT(showConfiguration()));
    connect(m_confTab,SIGNAL(clickedLoad()),this,SLOT(load()));
    connect(m_confTab,SIGNAL(clickedSave()),this,SLOT(save()));

    timer=setTimer();
    m_loop->setChart(m_simTab->getChartHandle(1));
    m_loop->setChartGenerator(m_simTab->getChartHandle(2));
    connect(m_simTab,SIGNAL(clickedStart()),this,SLOT(start()));
    connect(m_simTab,SIGNAL(sliderChange(int)),this,SLOT(setTimerInterval(int)));
    connect(m_simTab,SIGNAL(setVariable(int)),this,SLOT(setSetPoint(int)));
}

Simulator::~Simulator()
{
    delete m_loop;
}

void Simulator::showConfiguration()
{
        m_current_target=OBJECT;
        string str=m_loop->show();
        m_confTab->showConfiguration(str);
}

void Simulator::load()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Configuration"), "",
            tr("Configuration file (*.txt);"));
    try
    {
        string name=fileName.toStdString();
        if(m_current_target==OBJECT)
        {
            m_loop->loadObjectConfiguration(name);
            m_confTab->showConfiguration(m_loop->show());
        }
    }
    catch(exception &e)
    {
        QMessageBox::warning(this,tr("Exception"),QString(e.what()));
    }
}

void Simulator::save()
{
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Configuration"), "",
            tr("Configuration file (*.txt);"));
    try
    {
        string name=fileName.toStdString();
        if(m_current_target==OBJECT)
        {
            m_loop->saveObjectConfiguration(name);
        }
    }
    catch(exception &e)
    {
        QMessageBox::warning(this,tr("Exception"),QString(e.what()));
    }
}
void Simulator::run()
{
    m_loop->simLoop(m_set_point);
}
QTimer* Simulator::setTimer()
{
    QTimer* wsk;
    wsk = new QTimer;
    wsk->setInterval(100);  //100ms
    connect(wsk, SIGNAL(timeout()), this, SLOT(run()));
    return wsk;
}
void Simulator::start()
{
    if(m_loop->checkObjectConfiguration())
    {
        if (timer->isActive()) timer->stop();
        else timer->start();
        qDebug()<<"click"<<timer->isActive();
    }
    else
    {
        QMessageBox::information(this,tr("Invalid configuration"),tr("Invalid configuration, please check configuration."));
    }
}
void Simulator::setTimerInterval(int tempo)
{
    timer->setInterval(tempo);
    qDebug() <<"timer interval:"<< timer->interval();
}
void Simulator::setSetPoint(int setpoint)
{
    m_set_point=setpoint;
    qDebug() <<"set point:"<< m_set_point;
}

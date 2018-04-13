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

    connect(m_confTab,SIGNAL(clickedObject()),this, SLOT(showObjectConfiguration()));
    connect(m_confTab,SIGNAL(clickedRegulator()),this, SLOT(showRegulatorConfiguration()));
    connect(m_confTab,SIGNAL(clickedLoad()),this,SLOT(load()));
    connect(m_confTab,SIGNAL(clickedSave()),this,SLOT(save()));

    timer=setTimer();
    m_loop->setChartY(m_simTab->getChartHandle(0));
    m_loop->setChartU(m_simTab->getChartHandle(3));
    m_loop->setChartGenerator(m_simTab->getChartHandle(1));

    m_loop->addGeneratorRect();
    m_loop->addGeneratorSin();
    m_loop->addGeneratorTriang();
    m_loop->addGeneratorRand();

    connect(m_simTab,SIGNAL(clickedStart()),this,SLOT(start()));
    connect(m_simTab,SIGNAL(sliderChange(int)),this,SLOT(setTimerInterval(int)));
    connect(m_simTab,SIGNAL(setVariable(int)),this,SLOT(setSetPoint(int)));

    connect(m_simTab,SIGNAL(rectGeneratorState(bool)),this,SLOT(setGeneratorRectState(bool)));
    connect(m_simTab,SIGNAL(rectGeneratorParam(double,uint,uint)),this,SLOT(setGeneratorRectParam(double,uint,uint)));

    connect(m_simTab,SIGNAL(sinGeneratorState(bool)),this,SLOT(setGeneratorSinState(bool)));
    connect(m_simTab,SIGNAL(sinGeneratorParam(double,uint)),this,SLOT(setGeneratorSinParam(double,uint)));

    connect(m_simTab,SIGNAL(triangGeneratorState(bool)),this,SLOT(setGeneratorTriangState(bool)));
    connect(m_simTab,SIGNAL(triangGeneratorParam(double,uint)),this,SLOT(setGeneratorTriangParam(double,uint)));

    connect(m_simTab,SIGNAL(randGeneratorState(bool)),this,SLOT(setGeneratorRandState(bool)));
    connect(m_simTab,SIGNAL(randGeneratorParam(double)),this,SLOT(setGeneratorRandParam(double)));

    connect(m_simTab,SIGNAL(regulatorPParam(double)),this,SLOT(setRegulatorPParam(double)));
}

Simulator::~Simulator()
{
    delete m_loop;
}

void Simulator::showObjectConfiguration()
{
        m_current_target=OBJECT;
        string str=m_loop->show(m_current_target);
        m_confTab->showConfiguration(str);
}
void Simulator::showRegulatorConfiguration()
{
        m_current_target=REGULATOR;
        string str=m_loop->show(m_current_target);
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
            m_confTab->showConfiguration(m_loop->show(m_current_target));
        }
        else if(m_current_target==REGULATOR)
        {
            m_loop->loadRegulatorConfiguration(name);
            m_confTab->showConfiguration(m_loop->show(m_current_target));

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
        else if(m_current_target==REGULATOR)
        {
            m_loop->saveRegulatorConfiguration(name);
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
    }
    else
    {
        QMessageBox::information(this,tr("Invalid configuration"),tr("Invalid configuration, please check configuration."));
    }
}
void Simulator::setTimerInterval(int tempo)
{
    timer->setInterval(tempo);
}
void Simulator::setSetPoint(int setpoint)
{
    m_loop->setGeneratorOffset(setpoint);
}

void Simulator::setGeneratorRectState(bool p)
{
    if(p==false)
        m_loop->setGeneratorRectParam(0,2,50);
}

void Simulator::setGeneratorRectParam(double amp, unsigned int per, unsigned int gam)
{
    m_loop->setGeneratorRectParam(amp,per,gam);
}

void Simulator::setGeneratorSinState(bool p)
{
    if(p==false)
        m_loop->setGeneratorSinParam(0,2);
}

void Simulator::setGeneratorSinParam(double amp, unsigned int per)
{
    m_loop->setGeneratorSinParam(amp,per);
}

void Simulator::setGeneratorTriangState(bool p)
{
    if(p==false)
        m_loop->setGeneratorTriangParam(0,4);
}

void Simulator::setGeneratorTriangParam(double amp, unsigned int per)
{
    m_loop->setGeneratorTriangParam(amp,per);
}

void Simulator::setGeneratorRandState(bool p)
{
    if(p==false)
        m_loop->setGeneratorRandParam(0);
}

void Simulator::setGeneratorRandParam(double var)
{
    m_loop->setGeneratorRandParam(var);
}

void Simulator::setRegulatorPParam(double var)
{
    m_loop->setRegulatorParameters({var});
}

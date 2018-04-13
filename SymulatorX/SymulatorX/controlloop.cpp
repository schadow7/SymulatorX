#include "controlloop.h"
#include "objectsiso.h"
#include "regulator.h"

using namespace std;

ControlLoop::ControlLoop()
{

}


ControlLoop::ControlLoop(ObjectSISO*object, Regulator * regulator)
{
    m_object=object;
    m_regulator=regulator;
    m_object->registerObserver(m_regulator);
}

ControlLoop::~ControlLoop()
{
    delete m_object;
    delete m_regulator;
}


string ControlLoop::show(int target)
{
    if(target==0 && m_object!=NULL)
        return m_object->show();
    else if(target==1 && m_regulator!=NULL)
        return m_regulator->show();
    else
        return "Empty object\n";
}

void ControlLoop::loadObjectConfiguration(string name)
{
    if(m_object!=NULL)
        m_object->readConfig(name);
}
void ControlLoop::loadRegulatorConfiguration(string name)
{
    if(m_regulator!=NULL)
        m_regulator->readConfig(name);
}

void ControlLoop::saveObjectConfiguration(string name)
{
    if(m_object!=NULL)
        m_object->saveConfig(name);
}
void ControlLoop::saveRegulatorConfiguration(string name)
{
    if(m_regulator!=NULL)
        m_regulator->saveConfig(name);
}
void ControlLoop::setChartY(Observer* wsk)
{
 m_object->Subject::registerObserver(wsk);
}
void ControlLoop::setChartU(Observer* wsk)
{
 m_object->Subject::registerObserver(wsk);
}
void ControlLoop::setChartGenerator(Observer* ptr)
{
    m_regulator->setChartGenerator(ptr);
}
double ControlLoop::simLoop(double val)
{
    m_regulator->setSetPoint(val);
    //m_regulator->gen();
    return m_object->sim(m_regulator->getControlValue());
}

bool ControlLoop::checkObjectConfiguration()
{
    return m_object->checkConfiguration();
}

void ControlLoop::setObject(ObjectSISO *object)
{
    m_object=object;
}

void ControlLoop::setGeneratorOffset(double val)
{
    m_regulator->setGeneratorOffset(val);
}

void ControlLoop::setGeneratorRectParam(double amplitude, unsigned int period, unsigned int gamma)
{
    m_regulator->setGeneratorRectParam(amplitude,period,gamma);
}

void ControlLoop::addGeneratorRect()
{
    m_regulator->addGeneratorRect();;
}

void ControlLoop::removeGeneratorRect()
{
    m_regulator->removeGeneratorRect();
}

void ControlLoop::addGeneratorSin()
{
    m_regulator->addGeneratorSin();
}

void ControlLoop::setGeneratorSinParam(double amplitude, unsigned int period)
{
    m_regulator->setGeneratorSinParam(amplitude,period);
}

void ControlLoop::addGeneratorTriang()
{
    m_regulator->addGeneratorTriang();
}

void ControlLoop::setGeneratorTriangParam(double amplitude, unsigned int period)
{
    m_regulator->setGeneratorTriangParam(amplitude,period);
}

void ControlLoop::addGeneratorRand()
{
    m_regulator->addGeneratorRand();
}

void ControlLoop::setGeneratorRandParam(double var)
{
    m_regulator->setGeneratorRandParam(var);
}
void ControlLoop::setRegulatorParameters(double param)
{
    m_regulator->setParameters({param});
}


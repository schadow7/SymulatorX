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
}

ControlLoop::~ControlLoop()
{
    delete m_object;
}


string ControlLoop::show()
{
    if(m_object!=NULL)
        return m_object->show();
    else
        return "Empty object\n";
}

void ControlLoop::loadObjectConfiguration(string name)
{
    if(m_object!=NULL)
        m_object->readConfig(name);
}

void ControlLoop::saveObjectConfiguration(string name)
{
    if(m_object!=NULL)
        m_object->saveConfig(name);
}
void ControlLoop::setChart(Observer* wsk)
{
 m_object->Subject::registerObserver(wsk);
}
void ControlLoop::setChartGenerator(Observer* ptr)
{
    m_regulator->setChartGenerator(ptr);
}
double ControlLoop::simLoop(double val)
{
    m_regulator->gen();
    return m_object->sim(val);
}

bool ControlLoop::checkObjectConfiguration()
{
    return m_object->checkConfiguration();
}

void ControlLoop::setObject(ObjectSISO *object)
{
    m_object=object;
}

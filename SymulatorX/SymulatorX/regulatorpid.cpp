#include "regulatorpid.h"

using namespace std;

RegulatorPID::RegulatorPID()
{
    m_generator=new Generator;
}

RegulatorPID::~RegulatorPID()
{

}

void RegulatorPID::setChartGenerator(Observer * ptr)
{
    m_generator->registerObserver(ptr);
}

void RegulatorPID::setOffset(double val)
{
    m_generator->setOffset(val);
}

double RegulatorPID::sim(double )
{

}
//Testowa metoda
double RegulatorPID::gen()
{
    return m_generator->gen();
}

void RegulatorPID::update(double)
{

}

void RegulatorPID::update(std::vector<double>)
{

}

void RegulatorPID::readConfig(std::string)
{

}

void RegulatorPID::saveConfig(std::string)
{

}

string RegulatorPID::show()
{

}

bool RegulatorPID::checkConfiguration()
{

}

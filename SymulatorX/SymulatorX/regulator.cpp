#include "regulator.h"

using namespace std;

Regulator::Regulator()
{
        m_generator=new Generator;
}

Regulator::~Regulator()
{
    delete m_generator;
}

double Regulator::getObjectOutput(){
    return m_object_output;
}
double Regulator::getOffset(){
    return m_control_value-m_object_output;
}
void Regulator::update(double output){
    m_object_output=output;
    m_control_value=sim(m_object_output);
}
void Regulator::update(vector<double> output){
    m_object_output=output[0];
    m_control_value=sim(m_object_output);
}
void Regulator::setSetPoint(double value){
    m_set_point=value;
}
double Regulator::getSetPoint(){
    return m_set_point;
}
double Regulator::getControlValue(){
    return m_control_value;
}

void Regulator::setChartGenerator(Observer * ptr)
{
    m_generator->registerObserver(ptr);
}

void Regulator::setGeneratorOffset(double val)
{
    m_generator->setOffset(val);
}

void Regulator::addGeneratorRect()
{
    m_generator->addRect();
}

void Regulator::removeGeneratorRect()
{
    m_generator->removeRect();
}
void Regulator::setGeneratorRectParam(double amplitude, unsigned int period, unsigned int gamma)
{
    m_generator->setRectParam(amplitude,period,gamma);
}

void Regulator::addGeneratorSin()
{
    m_generator->addSin();
}

void Regulator::setGeneratorSinParam(double amplitude, unsigned int period)
{
    m_generator->setSinParam(amplitude,period);
}

void Regulator::addGeneratorTriang()
{
    m_generator->addTriang();
}

void Regulator::setGeneratorTriangParam(double amplitude, unsigned int period)
{
    m_generator->setTriangParam(amplitude,period);
}

void Regulator::addGeneratorRand()
{
    m_generator->addRand();
}

void Regulator::setGeneratorRandParam(double var)
{
    m_generator->setRandParam(var);
}

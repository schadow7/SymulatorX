#include "generator.h"
#include "genrect.h"
#include "gensin.h"
#include "gentriang.h"
#include "genrand.h"

Generator::Generator()
{
    m_offset=0;
}

Generator::~Generator()
{
    delete m_rect;
}

void Generator::setOffset(double offset)
{
    m_offset=offset;
}

void Generator::addRect()
{
    m_rect=new GenRect(0,2,50);
}

void Generator::removeRect()
{
    delete m_rect;
}

void Generator::setRectParam(double amplitude, unsigned int period, unsigned int gamma)
{
    m_rect->setParam(amplitude,period,gamma);
}

double Generator::gen()
{
    double sum=0;
    if(m_rect)
        sum+=m_rect->gen();
    if(m_sin)
        sum+=m_sin->gen();
    if(m_triang)
        sum+=m_triang->gen();
    if(m_rand)
        sum+=m_rand->gen();

    sum+=m_offset;
    notify({0, sum});
    return sum;
}

void Generator::addSin()
{
    m_sin=new GenSin(0,2);
}

void Generator::setSinParam(double amplitude, unsigned int period)
{
    m_sin->setParam(amplitude,period);
}

void Generator::addTriang()
{
    m_triang=new GenTriang(0,4);
}

void Generator::setTriangParam(double amplitude, unsigned int period)
{
    m_triang->setParam(amplitude,period);
}

void Generator::addRand()
{
    m_rand=new GenRand(0);
}

void Generator::setRandParam(double var)
{
    m_rand->setParam(var);
}

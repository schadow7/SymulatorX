#include "gensin.h"
#include "cmath"

GenSin::GenSin(double amplitude,unsigned int period)
{
    m_amplitude=amplitude;
    m_period=period;
}

void GenSin::setParam(double amplitude, unsigned int period)
{
    m_amplitude=amplitude;
    m_period=period;
}

double GenSin::gen()
{
    if(m_time>m_period)
        m_time=0;
    if(m_period==0)
        m_period=1;
    double ret=m_amplitude*sin((6.28/m_period)*m_time);
    m_time++;
    return ret;

}

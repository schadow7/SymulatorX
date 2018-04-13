#include "gentriang.h"
#include "cmath"

GenTriang::GenTriang(double amplitude, unsigned int period)
{
    m_amplitude=amplitude;
    m_period=period;
}

void GenTriang::setParam(double amplitude, unsigned int period)
{
    m_amplitude=amplitude;
    m_period=period;
}

double GenTriang::gen()
{
    if(m_time>m_period)
        m_time=0;
    double ret=0;
        ret=1-4*(double)fabs( round(((double)m_time/(double)m_period)-0.25)-(((double)m_time/(double)m_period)-0.25) );
    m_time++;
    return m_amplitude*ret;
}

#include "genrect.h"
#include "cmath"

GenRect::GenRect(double amplitude,unsigned int period, unsigned int gamma)
{
    m_amplitude=amplitude;
    m_period=period;
    m_gamma=gamma;
}

void GenRect::setParam(double amplitude, unsigned int period, unsigned int gamma)
{
    m_amplitude=amplitude;
    m_period=period;
    m_gamma=gamma;
}

double GenRect::gen()
{
    if(m_time>m_period)
        m_time=0;
   if( m_time++ < ceil(m_period*m_gamma/100))
       return m_amplitude;
   else
       return (-m_amplitude);
}

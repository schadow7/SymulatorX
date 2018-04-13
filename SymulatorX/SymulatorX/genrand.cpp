#include "genrand.h"

GenRand::GenRand(double var)
{
    m_var=var;
    if (m_distribution!=NULL) delete m_distribution;
    m_distribution=new std::normal_distribution<> {0,m_var};
}
GenRand::~GenRand()
{
    delete m_distribution;
}

void GenRand::setParam(double var)
{
    m_var=var;
    if (m_distribution!=NULL) delete m_distribution;
    m_distribution=new std::normal_distribution<> {0,m_var};
}


double GenRand::gen()
{
    if(m_var)
        return (*m_distribution)(engine);
    else
        return 0;
}

#ifndef OBJECTDISCRETE_H
#define OBJECTDISCRETE_H
#include "objectsiso.h"
#include "subject.h"
#include <random>
#include "polymonial.h"
#include <deque>

class ObjectDiscrete : public ObjectSISO
{
    Polymonial m_poly1A,m_poly1B;
    Polymonial m_poly2A,m_poly2B;
    Polymonial *m_polyA=&m_poly1A, *m_polyB=&m_poly1B;
    unsigned int m_dA, m_dB, m_delay=0,m_swapTime=0,m_time=0;
    std::deque<double> m_y,m_u;
    void update(std::deque<double>&,double);
    std::normal_distribution<> d{0,.1};
    std::default_random_engine silnik;
    void swapParameters();


public:
    ObjectDiscrete();
    ObjectDiscrete(const std::vector<double>&,const std::vector<double>&);
    ObjectDiscrete(const std::vector<double>&,const std::vector<double>&,unsigned int);
    ObjectDiscrete(const std::vector<double>&,const std::vector<double>&,const std::vector<double>&,const std::vector<double>&);
   ObjectDiscrete(const std::vector<double>&,const std::vector<double>&,const std::vector<double>&,const std::vector<double>&,unsigned int);
    void setDelay(const unsigned int&);
    void setSwapTime(unsigned int);
   virtual double sim(double);




};

#endif // OBJECTDISCRETE_H

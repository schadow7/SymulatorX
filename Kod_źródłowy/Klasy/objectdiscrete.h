#ifndef OBJECTDISCRETE_H
#define OBJECTDISCRETE_H
#include "objectsiso.h"
#include "subject.h"
#include <random>
#include "polymonial.h"
#include <deque>
#include <stdexcept>
#include <QtGlobal>
//#include <algorithm>

class ObjectDiscrete : public ObjectSISO
{
    Polymonial *m_poly1A=0,*m_poly1B=0;
    Polymonial *m_poly2A=0,*m_poly2B=0;
    unsigned int m_dA, m_dB, m_delay=0,m_swapTime=0,m_time=0;
    std::deque<double> m_y,m_u;
    void update(std::deque<double>&,double);
    std::normal_distribution<> d{0,.1};
    std::default_random_engine engine;
    void swapParameters();
    bool m_c=1;

public:

   ObjectDiscrete(const std::vector<double>* A2,const std::vector<double>* B2,unsigned int deley=0,const std::vector<double>* A1=0,const std::vector<double>* B1=0);
   void setDelay(const unsigned int&);
    void setSwapTime(unsigned int);
    void enableNoise(bool);
   virtual double sim(double);




};

#endif // OBJECTDISCRETE_H

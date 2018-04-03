#include "objectdiscrete.h"

ObjectDiscrete::ObjectDiscrete(const std::vector<double>* A2,const std::vector<double>* B2,unsigned int deley,const std::vector<double>* A1,const std::vector<double>* B1)
{
    m_delay=deley;
    if (A1) m_poly1A=new Polymonial(*A1);
    if (B1) m_poly1B=new Polymonial(*B1);
    m_poly2A=new Polymonial(*A2);
    m_dA=m_poly2A->size();
    m_y=std::deque<double>(m_dA,0.0);
    m_poly2B=new Polymonial(*B2);
    m_dB=m_poly2B->size();
    m_u=std::deque<double>(m_dB+m_delay,0.0);
}
void ObjectDiscrete::setDelay(const unsigned int& del)
{
    m_delay=del;
}
double ObjectDiscrete::sim(double value)
{
    if (m_time==m_swapTime) swapParameters();
    update(m_u,value);
    double e;
    if (m_c) e=d(engine);
    else e=0.0;
    double y=(m_poly1B->compute(m_u)+e)-m_poly1A->compute(m_y);
    notify(y);
    update(m_y,y);
    m_time++;
    return y;
}
void ObjectDiscrete::update(std::deque<double>& queue,double value)
{
    queue.erase(queue.begin());
    queue.push_back(value);
}
void ObjectDiscrete::setSwapTime(unsigned int SwapTime)
{
    if(SwapTime!=0 && (m_poly1A==0 || m_poly1B==0)) throw std::invalid_argument("Setting swap time: no first time of parameters");
    else
        m_swapTime=SwapTime;
}
void ObjectDiscrete::swapParameters()
{
    if(m_time!=0 && (m_poly1A==0 || m_poly1B==0)) throw std::invalid_argument("Attempt to swap: not enough parameters");
    if(m_poly2A==0 || m_poly2B==0) throw std::invalid_argument("Attempt to swap: not enough parameters");
    std::swap(m_poly1A,m_poly2A);
    std::swap(m_poly1B,m_poly2B);
}
void ObjectDiscrete::enableNoise(bool noise)
{
    m_c=noise;
}

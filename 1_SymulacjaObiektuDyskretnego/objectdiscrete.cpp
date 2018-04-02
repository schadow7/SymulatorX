#include "objectdiscrete.h"

ObjectDiscrete::ObjectDiscrete()
{
}
ObjectDiscrete::ObjectDiscrete(const std::vector<double>& A,const std::vector<double>& B):ObjectDiscrete()
{
    m_dA=m_poly1A.setCoeffs(A);
    m_y=std::deque<double>(m_dA,0.0);
    m_dB=m_poly1B.setCoeffs(B);
    m_u=std::deque<double>(m_dB,0.0);
}
ObjectDiscrete::ObjectDiscrete(const std::vector<double>& A,const std::vector<double>& B, unsigned int deley):ObjectDiscrete()
{
    m_delay=deley;
    m_dA=m_poly1A.setCoeffs(A);
    m_y=std::deque<double>(m_dA,0.0);
    m_dB=m_poly1B.setCoeffs(B);
    m_u=std::deque<double>(m_dB+m_delay,0.0);
}
ObjectDiscrete::ObjectDiscrete(const std::vector<double>& A,const std::vector<double>& B,const std::vector<double>& A2,const std::vector<double>& B2):ObjectDiscrete(A,B)
{
    m_poly2A.setCoeffs(A2);
    m_poly2B.setCoeffs(B2);
}
ObjectDiscrete::ObjectDiscrete(const std::vector<double>& A,const std::vector<double>& B,const std::vector<double>& A2,const std::vector<double>& B2,unsigned int deley):ObjectDiscrete(A,B,deley)
{
    m_poly2A.setCoeffs(A2);
    m_poly2B.setCoeffs(B2);
}
void ObjectDiscrete::setDelay(const unsigned int& del)
{
    m_delay=del;
}
double ObjectDiscrete::sim(double value)
{
    if (m_time==m_swapTime) swapParameters();
    update(m_u,value);
    double e=d(silnik);
    double y=(m_polyB->compute(m_u)+e)-m_polyA->compute(m_y);
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
   m_swapTime=SwapTime;
}
void ObjectDiscrete::swapParameters()
{
   m_polyA=&m_poly2A;
   m_polyB=&m_poly2B;
}

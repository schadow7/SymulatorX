#include "polymonial.h"
#include <QDebug> //qdebug in here
using namespace std;

Polymonial::Polymonial()
{
}
Polymonial::Polymonial(const std::vector<double>& coeffs)
{
    m_coeffs=coeffs;
}

double Polymonial::compute(const std::vector<double> &z)
{
    double suma=0;
    if(z.size()==m_coeffs.size())
    {
        for(int i=0; i<m_coeffs.size();i++)
        {
            //suma+=pow(z[i],i)*m_coeffs[i];
            suma+=z[i]*m_coeffs[i];
        }
    } else
        throw std::runtime_error("Polymonial compute: vector sizes mismatch");
    qDebug() <<"compute(const std::vector<double> &z) Suma="<< suma;
    qDebug() << "m_coeffs:"<<m_coeffs;
    qDebug() <<"z:"<<z;
    return suma;

}
double Polymonial::compute(const std::deque<double> &z)
{
    double suma=0;
    if(z.size()>=m_coeffs.size())
    {
        for(int i=0; i<m_coeffs.size();i++)
        {
            //suma+=pow(z[i],i)*m_coeffs[i];
            suma+=z[i]*m_coeffs[i];
        }
    }
    else throw std::runtime_error("Polymonial compute: vector sizes mismatch");
    qDebug() <<"compute(const std::deque<double> &z) Suma="<< suma;
    qDebug() << "m_coeffs:"<<m_coeffs;
    return suma;

}

int Polymonial::setCoeffs(const std::vector<double> &coeffs)
{
     m_coeffs=coeffs;
     return coeffs.size();

}

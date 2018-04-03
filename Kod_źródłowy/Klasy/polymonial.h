#ifndef WIELOMIAN_H
#define WIELOMIAN_H

#include <vector>
#include <deque>
#include <math.h>
class Polymonial
{
    std::vector<double> m_coeffs;
public:
    Polymonial();
    Polymonial(const std::vector<double>&);
    double compute(const std:: vector<double>&);
    double compute(const std:: deque<double>&);
    int setCoeffs(const std:: vector<double>&);
    int size();
};

#endif // WIELOMIAN_H

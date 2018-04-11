#ifndef POLYMONIAL_H
#define POLYMONIAL_H
#include <vector>
#include <deque>
#include <string>

class Polymonial
{
public:
    Polymonial();
    Polymonial(const std::vector<double>&);
    double compute(const std:: vector<double>&);
    double compute(const std:: deque<double>&);
    int setCoeffs(const std:: vector<double>&);

    std::string show() const;
    int size() const;
    double operator[](int) const;
private:
    std::vector <double> m_coeffs={0};
};

#endif // POLYMONIAL_H

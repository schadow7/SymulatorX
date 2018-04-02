#ifndef POLYMONIAL_H
#define POLYMONIAL_H
#include <vector>

class Polymonial
{
private:
    std::vector <double> m_coeffs;
public:
    Polymonial(std::vector <double>);
    ~Polymonial();
    void show() const;
    int size() const;
    double operator[](int) const;
};

#endif // POLYMONIAL_H

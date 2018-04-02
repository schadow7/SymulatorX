#include "polymonial.h"
#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;

Polymonial::Polymonial(vector<double> wektor)
{
    m_coeffs=wektor;
}

void Polymonial::show() const
{
    vector <double>::const_iterator it=m_coeffs.begin();
    for( ; it !=m_coeffs.end();++it)
    {
        cout << *it << "    ";
    }
    cout << endl;
}
int Polymonial::size() const
{
    return m_coeffs.size();
}

double Polymonial::operator [](int index) const
{
    assert(index < size() && index >=0);
    return m_coeffs[ index ];
}

Polymonial::~Polymonial()
{

}

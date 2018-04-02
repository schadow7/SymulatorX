#include "proces.h"
#include <cmath>
proces::proces()
{
    alfa=1;
}
proces::proces(double walfa)
{
    alfa=walfa;
}
double proces::procesuj(double x)
{
    double temp;
    temp=sin(alfa*x);
    notify(temp);
    return temp;
}

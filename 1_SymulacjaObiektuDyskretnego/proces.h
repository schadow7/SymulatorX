#ifndef PROCES_H
#define PROCES_H
#include "subject.h"


class proces : public Subject{
public:
   double procesuj(double x);
   proces();
   proces(double walfa);
   //void powiadom (int id, double wartosc) const;
private:
    double alfa;
};

#endif // PROCES_H

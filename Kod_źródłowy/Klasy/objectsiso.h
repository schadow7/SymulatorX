#ifndef OBIEKTSISO_H
#define OBIEKTSISO_H
#include"subject.h"

class ObjectSISO: public Subject
{
public:
    ObjectSISO();
   virtual double sim(double);
};

#endif // OBIEKTSISO_H

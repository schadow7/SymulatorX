#ifndef REGULATOR_H
#define REGULATOR_H
#include "objectsiso.h"
#include "observer.h"
#include "generator.h"

class Regulator : public ObjectSISO, public Observer
{
public:
    virtual ~Regulator(){ }
    virtual void setChartGenerator(Observer*)=0;
    virtual double sim(double)=0;
    virtual void setOffset(double)=0;
    //Tesotwa
    virtual double gen()=0;

};

#endif // REGULATOR_H

#ifndef GENERATOR_H
#define GENERATOR_H
#include "subject.h"

class Generator : public Subject
{
public:
    Generator();
    ~Generator();
    void setOffset(double offset);
    double gen();
private:
    double m_offset=0;
};

#endif // GENERATOR_H

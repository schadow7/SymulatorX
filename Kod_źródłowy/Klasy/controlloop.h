#ifndef PETLAREGULACJI_H
#define PETLAREGULACJI_H
#include "objectsiso.h"

class ControlLoop
{
public:
    ControlLoop();
private:
    ObjectSISO * m_object=nullptr;
};

#endif // PETLAREGULACJI_H

#ifndef OBJECTDISCRETE_H
#define OBJECTDISCRETE_H
#include "objectsiso.h"
#include <string>
class Polymonial;

class ObjectDiscrete : public ObjectSISO
{
public:
    ObjectDiscrete();
    ObjectDiscrete(std::string);
    ObjectDiscrete(Polymonial*,Polymonial*,unsigned int);
    void readConfig(std::string) override;
    void saveConfig(std::string) override;
    ~ObjectDiscrete();
    void show() override;
private:
    Polymonial* checkPoly(std::string);
    double checkDelay(std::string);
public:
    Polymonial *m_polyA=nullptr;
    Polymonial *m_polyB=nullptr;
    unsigned int m_dA=0;
    unsigned int m_dB=0;
    unsigned int m_delay=0;
};

#endif // OBJECTDISCRETE_H

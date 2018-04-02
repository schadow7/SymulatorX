#include "objectsiso.h"
#include "objectdiscrete.h"
#include <exception>
#include <iostream>

using namespace std;

ObjectSISO::~ObjectSISO()
{

}
void ObjectSISO::readConfig(std::string)
{

}

void ObjectSISO::saveConfig(std::string)
{

}

ObjectSISO* ObjectSISO::createObject(std::string name)
{
    ObjectDiscrete * object;
    try
    {
        object=new ObjectDiscrete(name);
    }
    catch (...)
    {
        throw;
    }
    return object;
}

void ObjectSISO::show()
{
    cout << "SISO" << endl;
}

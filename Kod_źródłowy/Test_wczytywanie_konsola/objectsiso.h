#ifndef OBJECTSISO_H
#define OBJECTSISO_H
#include <string>

class ObjectSISO
{
public:
    virtual ~ObjectSISO();
    virtual void readConfig(std::string);
    virtual void saveConfig(std::string);
    static ObjectSISO *createObject(std::string); //Tutaj, bo powinien na podstawie pliku konfiguracyjnego ustalać typ i wywoływać odpowiedni konstruktor
    virtual void show();
};

#endif // OBJECTSISO_H

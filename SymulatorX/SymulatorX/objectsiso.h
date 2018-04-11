#ifndef OBJECTSISO_H
#define OBJECTSISO_H
#include <string>
#include "subject.h"
/**
 * @brief Klasa wirtualna obiektu dyskretnego z jednym wejściem i jednym wyjściem
 */
class ObjectSISO : public Subject
{
public:
   virtual ~ObjectSISO() {}
    /**
    * @brief readConfig
    */
   virtual void readConfig(std::string)=0;
   virtual void saveConfig(std::string)=0;
   virtual std::string show()=0;
   virtual double sim(double)=0;
   virtual bool checkConfiguration()=0;
};

#endif // OBJECTSISO_H

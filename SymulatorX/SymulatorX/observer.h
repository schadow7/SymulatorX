#ifndef __OBSERWATOR_H__
#define __OBSERWATOR_H__
#include<vector>

class Observer {
public:
    virtual ~Observer () {}
    virtual void update (double) = 0;
    virtual void update (std::vector<double>) = 0;
    //virtual void aktualizuj (int id, double wartosc) = 0;
};

#endif

#ifndef __OBSERWOWANY_H__
#define __OBSERWOWANY_H__
#include <list>

class Observer;

class Subject {
public:
    Subject ();
    virtual ~Subject ();
    bool registerObserver (Observer *);
    bool unregisterObserver (Observer *);
    void notify (double wartosc) const;
private:
    std::list<Observer * > m_observers;
};

#endif

#ifndef __OBSERWOWANY_H__
#define __OBSERWOWANY_H__
#include <list>
#include <vector>
class Observer;

class Subject {
public:
    Subject ();
    virtual ~Subject ();
    virtual bool registerObserver (Observer *);
    bool unregisterObserver (Observer *);
    void notify (double wartosc) const;
    void notify(std::vector<double>) const;
private:
    std::list<Observer * > m_observers;
};

#endif

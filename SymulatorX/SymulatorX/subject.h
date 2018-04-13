#ifndef __OBSERWOWANY_H__
#define __OBSERWOWANY_H__
#include <list>
#include <vector>
class Observer;
/**
 * @brief Klasa obserwowany
 */
class Subject {
public:
    Subject ();
    virtual ~Subject ();
    /**
     * @brief Rejestracja obserwatora
     * @param Wskaźnik na obiekt do dodania
     * @return
     * + true- zakończona sukcesem,
     * + false-zakończona porażką
     */
    virtual bool registerObserver (Observer *);
    /**
     * @brief Usunięcie obserwatora z listy
     * @param Wskaźnik na obiekt do usunięcia
     * @return
     * + true- zakończona sukcesem,
     * + false-zakończona porażką
     */
    bool unregisterObserver (Observer *);
    /**
     * @brief Powiadomienie obserwatorów
     * @param wartosc
     */
    void notify (double wartosc) const;
    /**
     * @brief Powiadomienie obserwatorów
     * @param wektor przesyłanych wartości
     */
    void notify(std::vector<double>) const;
private:
    std::list<Observer * > m_observers;
};

#endif

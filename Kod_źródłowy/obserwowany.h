#ifndef OBSERWOWANY_H
#define OBSERWOWANY_H
#include <list>

/*! \file obserwowany.h
    \brief Nagłówek klasy Obserwowany
*/
/*! \class Obserwowany
    \brief Klasa Obserwowany
    \details Wirtualna klasa obserwowanego realizująca wzorzec projektowy OBSERWATOR.
*/

class Obserwator;

class Obserwowany
{
public:
    /*!
        \brief Wirtualny destruktor.
    */
    virtual ~Obserwowany();
    /*!
        \brief Rejestruje Obserwatora, którego ma powiadamiać o zdarzeniach.
        \param obserwator   Wskaźnik do obiektu dziedziczącego z klasy Obserwator.
        \return - true  Udało się zarejestrować Obserwatora.
                    - false Nie udało się zarejestrować Obserwatora, ponieważ już jest zarejstrowany.
    */
    bool rejestrujObserwatora (Obserwator * obserwator);
    /*!
        \brief Wyrejestrowywuje Obserwatora, który od tej pory nie będzie informowany o zdarzeniach.
        \param obserwator   Wskaźnik do obiektu dziedziczącego z klasy Obserwator.
        \return - true  Udało się wyrejestrować Obserwatora.
                     - false Nie udało się wyrejestrować Obserwatora, ponieważ nie był zarejstrowany.
    */
    bool wyrejestrujObserwatora (Obserwator * obserwator);
    /*!
        \brief Powiadamia wszystkich Obserwatorów o zaistniałym zdarzeniu.
        \param wartosc   Wartość, która zostanie wszystkim Obserwatorom.
    */
    void powiadom (double wartosc) const;
private:
    /*!
        \brief Lista przechowująca wskaźniki do zarejestrowanych Obserwatorów.
    */
    std::list<Obserwator *> m_obserwatorzy;
};

#endif // OBSERWOWANY_H

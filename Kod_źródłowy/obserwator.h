#ifndef OBSERWATOR_H
#define OBSERWATOR_H

/*! \file obserwator.h
    \brief Nagłówek klasy Obserwator
*/
/*! \class Obserwator
    \brief Klasa Obserwator
    \details Wirtualna klasa obserwatora realizująca wzorzec projektowy OBSERWATOR.
*/


class Obserwator
{
public:
    /*!
        \brief Konstruktor wirualny
    */
    virtual ~Obserwator();
    /*!
        \brief Odbiera informacje od obserwowanego obiektu.
        \param[in] wartosc     Wartość typu double zwracana przez obserwowany obiekt.
    */
    virtual void aktualizuj (double wartosc) = 0;
};

#endif //OBSERWATOR_H

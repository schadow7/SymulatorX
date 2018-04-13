#ifndef __OBSERWATOR_H__
#define __OBSERWATOR_H__
#include<vector>
/**
 * @brief Klasa obserwatora
 */
class Observer {
public:
    virtual ~Observer () {}
    /**
     * @brief Aktualizuje obserwowane wartości
     */
    virtual void update (double) = 0;
    /**
     * @brief Aktualizuje obserwowane wartości
     */
    virtual void update (std::vector<double>) = 0;
    //virtual void aktualizuj (int id, double wartosc) = 0;
};

#endif

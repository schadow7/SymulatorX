#ifndef GENRAND_H
#define GENRAND_H
#include <random>
/**
 * @brief Generator białego szumu
 */
class GenRand
{
public:
    /**
     * @brief Konstruktor
     * @param Wariancja
     */
    GenRand(double var);
    /**
     * @brief Destruktor
     */
    ~GenRand();
    /**
     * @brief Ustawienie wariancji
     * @param Wariancja
     */
    void setParam(double var);
    /**
     * @brief Generuje losową próbkę o średniej 0 i ustawionej wariancji
     * @return Losowa próbka
     */
    double gen();
private:
    double m_var=0.0;
    /** Rozkład normalny do symulacji zakłuceń*/
    //std::normal_distribution<> d{0,.1};
    std::normal_distribution<> *m_distribution=NULL;
    std::default_random_engine engine;
};

#endif // GENRAND_H

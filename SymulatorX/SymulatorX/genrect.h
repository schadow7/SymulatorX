#ifndef GENRECT_H
#define GENRECT_H

/**
 * @brief Generator fali prostokątnej
 * @details Generator fali prostokątnej o wybranej amplitudzie, okresie oraz współczynniku wypełnienia
 */
class GenRect
{
public:
    /**
     * @brief Konstruktor
     * @param Amplituda
     * @param Okres fali
     * @param Współczynnik wypełnienia w %
     */
    GenRect(double amplitude,unsigned int period,unsigned int gamma);
    /**
     * @brief Generuje próbkę fali prostokątnej
     * @return Wartość próbki z fali prostokątnej
     */
    double gen();
    /**
     * @brief Ustawia parametry fali prostokątnej
     * @param Amplituda
     * @param Okres fali
     * @param Współczynnik wypełnienia
     */
    void setParam(double amplitude,unsigned int period,unsigned int gamma);
private:
    unsigned int m_time=0;
    unsigned int m_period=2;
    unsigned int m_gamma=50;
    double  m_amplitude=1;
};

#endif // GENRECT_H

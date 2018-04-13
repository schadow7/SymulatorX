#ifndef GENSIN_H
#define GENSIN_H

/**
 * @brief Generator sygnału sinusoidalnego
 */
class GenSin
{
public:
    /**
     * @brief Konstruktor
     * @param amplitude
     * @param period
     */
    GenSin(double amplitude, unsigned int period);
    /**
     * @brief Ustawia parametry sinusoidy
     * @param amplitude
     * @param period
     */
    void setParam(double amplitude,unsigned int period);
    double gen();
private:
    double m_amplitude=0;
    unsigned int m_period=1;
    unsigned int m_time=0;
};

#endif // GENSIN_H

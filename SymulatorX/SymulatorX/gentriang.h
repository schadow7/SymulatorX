#ifndef GENTRIANG_H
#define GENTRIANG_H

/**
 * @brief Generator sygnału trójkątnego
 */
class GenTriang
{
public:
    /**
     * @brief Konstruktor
     * @param amplitude
     * @param period
     */
    GenTriang(double amplitude,unsigned int period);
    /**
     * @brief Ustawia parametry sygnału trójkątnego
     * @param amplitude
     * @param period
     */
    void setParam(double amplitude,unsigned int period);
    /**
     * @brief Generuje sygnał trójkątny
     * @return Próbka sygnału trójkątnego
     */
    double gen();
private:
    double m_amplitude=0;
    unsigned int m_period=4;
    unsigned int m_time=0;
};

#endif // GENTRIANG_H

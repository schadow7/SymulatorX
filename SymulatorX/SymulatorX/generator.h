#ifndef GENERATOR_H
#define GENERATOR_H
#include "subject.h"

class GenRect;
class GenSin;
class GenTriang;
class GenRand;
/**
 * @brief Generator wybranych sygnałów
 * @details Generator sygnałów: prostokątnego, skoku, trójkątnego, sinusoidy, szumu losowego oraz dowolnej ich sumy
 */
class Generator : public Subject
{
public:
    /**
     * @brief Konstruktor
     */
    Generator();
    ~Generator();
    /**
     * @brief Ustawienie stałej wartości dodawanej do generowanego sygnału
     * @param Stała
     */
    void setOffset(double offset);
    /**
     * @brief Generuje sygnał będący sumą generowanych sygnałów
     * @return Próbka generowanego sygnału
     */
    double gen();
    /**
     * @brief Dodaje generator fali prostokątnej
     */
    void addRect();
    /**
     * @brief Usuwa generator fali prostokątnej
     */
    void removeRect();
    /**
     * @brief Ustawia parametry generowania sygnału prostokątnego
     * @param Amplituda
     * @param Okres
     * @param Współczynnik wypełnienia
     */
    void setRectParam(double amplitude,unsigned int period, unsigned int gamma);
    /**
     * @brief Dodaj generator sinusoidalny
     */
    void addSin();
    /**
     * @brief Ustawia parametry sygnału sinusoidalnego
     * @param amplitude
     * @param period
     */
    void setSinParam(double amplitude,unsigned int period);
    /**
     * @brief Dodaj generator sygnału trójkątnego
     */
    void addTriang();
    /**
     * @brief Ustawia parametry sygnalu trójkątnego
     * @param amplitude
     * @param period
     */
    void setTriangParam(double amplitude,unsigned int period);
    /**
     * @brief addRand
     */
    void addRand();
    /**
     * @brief setRandParam
     * @param Wariancja
     */
    void setRandParam(double var);
private:
    double m_offset=0;
    GenRect * m_rect=nullptr;
    GenSin * m_sin=nullptr;
    GenTriang * m_triang=nullptr;
    GenRand * m_rand=nullptr;
};

#endif // GENERATOR_H

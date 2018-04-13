#ifndef REGULATOR_H
#define REGULATOR_H
#include "objectsiso.h"
#include "observer.h"
#include "generator.h"
/**
 * @brief The Regulator class
 */
class Regulator : public ObjectSISO, public Observer
{

public:
    /**
     * @brief Konstruktor
     */
    Regulator();
    /**
     * @brief Destruktor
     */
    virtual ~Regulator();
    /**
     * @return Ostatnie wyjście obserwowanego obiektu
     */
    virtual double getObjectOutput();
    /**
     * @return Uchyb regulacji ostatniego kroku symulacji
     */
    virtual double getOffset();
    /**
     * @brief Ustawia wartość zadaną
     */
    virtual void setSetPoint(double);
    /**
     * @return Wartość zadana regulacji
     */
    virtual double getSetPoint();
    /**
     * @return Wartość sterowania
     */
    virtual double getControlValue();
    /**
     * @brief Oblicza wartość sterowania <i>m_control_value</i> w reakcji na zmianę odpowiedzi obiektu
     */
    void update (double) override;
    void update (std::vector<double>) override;
    virtual void setParameters(std::vector<double>)=0;

    /**
     * @brief Przypisanie obserwatora do generatora
     * @param Wskaźnik do obserwatora
     */
    void setChartGenerator(Observer* ptr);
    /**
     * @brief Ustawia przesunięcie o stałą sygnału generowanego
     * @param Stała dodawana do sygnału generowanego
     */
    void setGeneratorOffset(double value);
    /**
     * @brief Dodaje generator fali prostokątnej
     */
    void addGeneratorRect();
    /**
     * @brief removeGeneratorRect
     */
    void removeGeneratorRect();
    /**
     * @brief Ustawia parametry generacji sygnału prostokątnego
     * @param Amplituda
     * @param Okres
     * @param Współczynnik wypełnienia
     */
    void setGeneratorRectParam(double amplitude, unsigned int period, unsigned int gamma);
    /**
     * @brief addGeneratorSin
     */
    void addGeneratorSin();
    /**
     * @brief setGeneratorSinParam
     * @param amplitude
     * @param period
     */
    void setGeneratorSinParam(double amplitude, unsigned int period);
    /**
     * @brief addGeneratorTriang
     */
    void addGeneratorTriang();
    /**
     * @brief setGeneratorTriangParam
     * @param amplitude
     * @param period
     */
    void setGeneratorTriangParam(double amplitude, unsigned int period);
    /**
     * @brief addGeneratorRand
     */
    void addGeneratorRand();
    /**
     * @brief setGeneratorRandParam
     * @param var
     */
    void setGeneratorRandParam(double var);
    /**
     * @brief Zmienna przechowująca ostatnią wartosć wyjścia obiektu
     */
    double m_object_output=0;
    /**
     * @brief Zmienna przechowująca ostatnią wartosć sterowania
     */
    double m_control_value=0;
    /**
     * @brief Zmienna przechowująca wartość zadaną
     */
    double m_set_point;
protected:
    /**
     * @brief m_generator
     */
    Generator * m_generator;
};

#endif // REGULATOR_H

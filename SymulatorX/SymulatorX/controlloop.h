#ifndef CONTROLLOOP_H
#define CONTROLLOOP_H
#include <string>
class ObjectSISO;
class Observer;
class Regulator;
/**
 * @brief Klasa pętli regulacji służąca do symulacji dyskretnej pętli regulacji
 */

class ControlLoop
{
public:
    ControlLoop();
    /**
     * @brief Konstruktor z elementami pętli regulacji
     * @param Wskaźnik <i>object</i> na obiekt w pętli regulacji
     */
    ControlLoop(ObjectSISO* object,Regulator * regulator);
    /**
      @brief Destruktor
      */
    ~ControlLoop();
    /**
     * @brief Generuje łańcuch znakowy z informacją o konfiguracji
     * @param 0-obiektu, 1-regulatora
     * @return Łańcuch znakowy z konfiguracją obiektu
     */
    std::string show(int);
    /**
     * @brief Wczytuje konfiguracje obiektu z pliku o nazwie <i>name</i>
     * @param Nazwa pliku, z którego ma być pobrana konfiguracja
     */
    void loadObjectConfiguration(std::string name);
    /**
     * @brief Wczytuje konfiguracje ragulatora z pliku o nazwie <i>name</i>
     * @param Nazwa pliku, z którego ma być pobrana konfiguracja
     */
    void loadRegulatorConfiguration(std::string name);
    /**
     * @brief Zapisuje konfiguracje obiektu do pliku o nazwie <i>name</i>
     * @param Nazwa pliku, do którego ma być zapisana konfiguracja
     */
    void saveObjectConfiguration(std::string name);
    /**
     * @brief Zapisuje konfiguracje regulatora do pliku o nazwie <i>name</i>
     * @param Nazwa pliku, do którego ma być zapisana konfiguracja
     */
    void saveRegulatorConfiguration(std::string name);

    void setChartY(Observer*);
    void setChartU(Observer*);
    double simLoop(double);
    /**
     * @brief Podpina obserwatora pod generator
     * @param Wskaźnik do obserwatora
     */
    void setChartGenerator(Observer* ptr);
    /**
     * @brief Ustawia stałe przesunięcie generowanego sygnału
     * @param Stała wartość przesunięcia
     */
    void setGeneratorOffset(double val);
    /**
     * @brief addGeneratorRect
     */
    void addGeneratorRect();
    /**
     * @brief removeGeneratorRect
     */
    void removeGeneratorRect();
    /**
     * @brief Ustawia parametry generatora fali prostokątnej
     * @param amplitude
     * @param period
     * @param gamma
     */
    void setGeneratorRectParam(double amplitude,unsigned int period,unsigned int gamma);
    /**
     * @brief Sprawdza poprawność konfiguracji obiektu
     * @return
     * + true - poprawna konfiguracja
     * + false - niepoprawna konfiguracja
     */
    bool checkObjectConfiguration();
    /**
     * @brief Ustawia <i>object</i> jako obiekt pętli regulacji
     * @param Wskaźnik na obiekt
     */
    void setObject(ObjectSISO* object);
    /**
     * @brief addGeneratorSin
     */
    void addGeneratorSin();
    /**
     * @brief setGeneratorSinParam
     * @param amplitude
     * @param period
     */
    void setGeneratorSinParam(double amplitude,unsigned int period);
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
    void setRegulatorParameters(double);
    void setGeneratorRandParam(double var);
   private:
    ObjectSISO * m_object;
    Regulator * m_regulator;
};

#endif // CONTROLLOOP_H

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
     * @brief Generuje łańcuch znakowy z informacją o konfiguracji obiektu
     * @return Łańcuch znakowy z konfiguracją obiektu
     */
    std::string show();
    /**
     * @brief Wczytuje konfiguracje obiektu z pliku o nazwie <i>name</i>
     * @param Nazwa pliku, z którego ma być pobrana konfiguracja
     */
    void loadObjectConfiguration(std::string name);
    /**
     * @brief Zapisuje konfiguracje obiektu do pliku o nazwie <i>name</i>
     * @param Nazwa pliku, do którego ma być zapisana konfiguracja
     */
    void saveObjectConfiguration(std::string name);

    void setChart(Observer*);
    double simLoop(double);

    void setChartGenerator(Observer* ptr);
    void setGeneratorOffset(double val);

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
private:
    ObjectSISO * m_object;
    Regulator * m_regulator;
};

#endif // CONTROLLOOP_H

#ifndef OBJECTDISCRETE_H
#define OBJECTDISCRETE_H
#include "objectsiso.h"
#include <string>
#include <random>
#include <deque>
class Polymonial;
/**
 * @brief Klasa obiektu dykretnego
 */
class ObjectDiscrete : public ObjectSISO
{
public:
    /**
     * @brief Konstruktor
     */
    ObjectDiscrete();
    /**
     * @brief Konstruktor wczytujący konfigurację obiektu dyskretnego z pliku
     * @param Nazwa pliku, z którego ma być wczytana konfiguracja
     */
    ObjectDiscrete(std::string name);
    /**
     * @brief Konstruktor inicjalizujący obiekt obiektem stacjonarnym
     * @param Wielomian A obiektu
     * @param Wielomian B obiektu
     * @param Opóźnienie
     */
    ObjectDiscrete(Polymonial* poly2A,Polymonial* poly2B,unsigned int delay);
    /**
     * @brief Wczytuje konfigurację obiektu z pliku o nazwie <i>name</i>
     * @param Nazwa pliku, z którego ma być wczytana konfiguracja
     */
    void readConfig(std::string name) override;
    /**
     * @brief Zapisuje konfigurację obiektu do pliku o nazwie <i>name</i>
     * @param Nazwa pliku
     */
    void saveConfig(std::string name) override;
    ~ObjectDiscrete();
    /**
     * @brief Wyświetlenie konfiguracji w postaci łańcucha znakowego
     * @return Konfiguracja w postaci łańcucha znakowego
     */
    std::string show() override;
    /**
     * @brief Sprawdzenie poprawności konfiguracji
     * @return
     * + true - konfiguracja poprawna
     * + false - konfiguracja niepoprawna
     */
    bool checkConfiguration() override;
private:
    Polymonial* checkPoly(std::string);
    double checkDelay(std::string);
    int checkSwapTime(std::string);
    double checkVariance(std::string);

    /**Pierwsza para parametrów modelu ARX. Wielomian A nie uwzglądnia pierwszej jedynki.*/
    Polymonial *m_poly1A=nullptr,*m_poly1B=nullptr;
    /** Parametry ARX ustawiane w chwili swapTime*/
    Polymonial *m_poly2A=nullptr,*m_poly2B=nullptr;
    unsigned int m_dA=0;
    unsigned int m_dB=0;
    unsigned int m_delay=0;
    unsigned int m_swapTime=0;
    unsigned int     m_time=0;
    /** Historia wyjść i wejść*/
    std::deque<double> m_y,m_u;
    /**Funkcja odpowiedzialna za zapamiętywanie i zapominanie próbek*/
    void update(std::deque<double>&,double);
    /** Rozkład normalny do symulacji zakłuceń*/
    //std::normal_distribution<> d{0,.1};
    double m_variance=.1;
    std::normal_distribution<> *m_distribution=NULL;
    std::default_random_engine engine;
    /*Funkcja zamieniająca zastaw parametrów modelu ARX*/
    void swapParameters();
    bool m_c=1;

public:
    ObjectDiscrete(const std::vector<double>* A2,const std::vector<double>* B2,unsigned int deley=0,const std::vector<double>* A1=nullptr,const std::vector<double>* B1=nullptr);
    /**Ustawia czas zamiany parametrów*/
    void setSwapTime(unsigned int);
    /** 0- syulacja bez zakłóceń, 1- z zakłóceniami*/
    void enableNoise(bool);
    /** Sumulacja krokowa*/
    virtual double sim(double);

};

#endif // OBJECTDISCRETE_H

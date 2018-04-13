#ifndef REGULATORPID_H
#define REGULATORPID_H
#include "regulator.h"
#include <vector>
/**
 * @brief Regulator PID
 */
class RegulatorPID: public Regulator
{
public:
    /**
     * @brief RegulatorPID
     */
    RegulatorPID();
    /**
     * @brief Konstruktor wczytujący konfigurację regulatora z pliku
     * @param Nazwa pliku, z którego ma być wczytana konfiguracja
     */
    RegulatorPID(std::string name);
    ~RegulatorPID();
    /**
     * @brief Oblicza sterowanie
     * @param Wyjście z obiektu
     */
    double sim(double) override;
    //void update(double) override;
    //void update(std::vector<double>) override;
    /**
     * @brief Odczyt konfiguracji regulatora z pliku
     * @param Nazwa pliku
     */
    void readConfig(std::string name) override;
    /**
     * @brief Zapis konfiguracji do pliku
     * @param Nazwa pliku
     */
    void saveConfig(std::string name) override;
    /**
     * @return String zawiarający nastawy regulatora wyświetlane w Control Tab
     */
    std::string show() override;
    /**
     * @brief Sprawdzenie poprawności konfiguracji
     * @return
     * + true - konfiguracja poprawna
     * + false - konfiguracja niepoprawna
     */
    bool checkConfiguration() override;
    /**
     * @brief Ustawia parametry regulatora
     * @param Kolejność paramerów {kr,Ti,Td}
     */
    void setParameters(std::vector<double>)override;
private:
    double m_kr=1, m_Ti=999999, m_Td=0;
    double checkKr(std::string);
    double checkTi(std::string);
    double checkTd(std::string);
};

#endif // REGULATORPID_H

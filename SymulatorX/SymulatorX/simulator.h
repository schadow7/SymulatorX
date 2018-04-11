#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <QTabWidget>

enum target {OBJECT,REGULATOR};

class ControlLoop;
class SimulationTab;
class ConfigurationTab;
class QTimer;

/**
 * @brief Klasa Symulatora służąca do symulacji dyskretnej pętli regulacji i dostarczająca wymagany interfejs graficzny
 */


class Simulator : public QTabWidget
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor
     * @param Ustawienie rodzica <i>parrent</i>, pozwala na wywołanie destruktora klasy symulatora przy usuwanie rodzica
     */

    explicit Simulator(QWidget *parent = nullptr);

    /**
      @brief Destruktor
      */
    ~Simulator();
public slots:
    /**
     * @brief Wyświetla informacje o konfiguracji wybranego celu (obiekcie, regulatorze)
     */
    void showConfiguration();
    /**
     * @brief Wczytuje konfigurację wybranego celu (obiekt, regulator) o wybranej nazwie
     */
    void load();
    /**
     * @brief Zapisuje konfigurację wybranego celu (obiekt, regulator) o wybranej nazwie
     */
    void save();
    void run();
    void start();
    void setTimerInterval(int);
    void setSetPoint(int);
private:
    ControlLoop * m_loop;
    SimulationTab * m_simTab;
    ConfigurationTab * m_confTab;
    target m_current_target;
    QTimer *timer;
    QTimer* setTimer();
    int m_set_point=0;


};

#endif // SIMULATOR_H

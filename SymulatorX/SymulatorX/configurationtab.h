#ifndef CONFIGURATIONTAB_H
#define CONFIGURATIONTAB_H

#include <QWidget>

class QGroupBox;
class QLabel;
class QTextEdit;
class QPushButton;
/**
 * @brief Klasa zakładki konfiguracji dostarczająca interfejs graficzny do konfiguracji pętli regulacji dla klasy Simulator
 */
class ConfigurationTab : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor
     * @param Ustawienie rodzica <i>parrent</i> pozwala na wywołanie destruktora podczas usuwania rodzica
     */
    explicit ConfigurationTab(QWidget *parent = nullptr);
    /**
     * @brief Wyświetla wiadomość w polu tekstowym
     * @param Łańcuch znakowy, który zostanie wyświetlony
     */
    void showConfiguration(std::string text);
signals:
    /**
     * @brief Sygnał informujący o kliknięciu przycisku Object
     */
    void clickedObject();
    /**
     * @brief Sygnał informujący o kliknięciu przycisku Load
     */
    void clickedLoad();
    /**
     * @brief Sygnał informujący o kliknięciu przycisku Save
     */
    void clickedSave();
private:
    void createLayout();
    QTextEdit * m_display;
    QPushButton * m_button_object;
    QPushButton * m_button_regulator;
    QPushButton * m_button_save;
    QPushButton * m_button_load;

};

#endif // CONFIGURATIONTAB_H

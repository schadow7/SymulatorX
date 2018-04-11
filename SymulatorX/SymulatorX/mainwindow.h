#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

class Simulator;
/**
 * @brief Klasa głównego okna
 *
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
protected:

private slots:
    void about();
    void help();
private:
    void createActions();
    void createStatusBar();
    void readSettings();

    Simulator * m_simulator;
};

#endif // MAINWINDOW_H

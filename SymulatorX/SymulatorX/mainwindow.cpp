#include <QtWidgets>
#include "mainwindow.h"
#include "simulator.h"

MainWindow::MainWindow()
{
    m_simulator=new Simulator(this);
    //Ustawia jako centralny widget symulator
    setCentralWidget(m_simulator);
    //Tworzy menu górne
    createActions();
    //Tworzy pasek statusu u dołu
    createStatusBar();
    //Czyta ustawienia(jeśli jakieś były, u nas parę rzeczy jest podanych w main.cpp)
    //oraz ustawia rozmiar okna
    readSettings();
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About SimulatorX"),
                       tr("The <b>SimulatorX</b> is application to "
                          "simulate control loop with discrete object "
                          "and regulator"));
}

void MainWindow::help()
{
    QMessageBox::about(this, tr("Help"),
                       tr("This is help section of <b>SimulatorX</b>."));
}

void MainWindow::createActions()
{
    menuBar()->addMenu(tr("&Control Loops"));
    QMenu * helpMenu = menuBar()->addMenu(tr("&Help"));

    QAction * helpAct = helpMenu->addAction(tr("&Help"),this,&MainWindow::help);
    helpAct->setStatusTip(tr("Show the help"));
    QAction * aboutAct = helpMenu->addAction(tr("&About"), this, &MainWindow::about);
    aboutAct->setStatusTip(tr("Show the application's About box"));
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::readSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    const QByteArray geometry = settings.value("geometry", QByteArray()).toByteArray();
    if (geometry.isEmpty()) {
        const QRect availableGeometry = QApplication::desktop()->availableGeometry(this);
        resize(availableGeometry.width() / 3, availableGeometry.height() / 2);
        move((availableGeometry.width() - width()) / 2,
             (availableGeometry.height() - height()) / 2);
    } else {
        restoreGeometry(geometry);
    }
}

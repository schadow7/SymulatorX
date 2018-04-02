#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setPlot();
    csinus= new proces(.5);
    csinus->registerObserver(wyk2);
    timer=setTimer();
    speedSlider=setSpeedSlider();
    main_layout=setLayout();

    std::vector<double> wek(3,2), A,A2;
    A.push_back(0.2); A.push_back(0.1);
    A2.push_back(0.6); A2.push_back(0.3);
    std::deque<double> zety(3,13);
    //qDebug() <<wek.size() <<"  Wart:" <<wek;
    Polymonial obiekt(wek);

    obiektTestowy= new ObjectDiscrete(A,wek,A2,wek,50);
    obiektTestowy->registerObserver(wyk1);
    obiektTestowy->setSwapTime(75);
    timer->start();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPlot()
{
    wyk1 = new Chart("Wykres1");
    wyk1->getHandle()->setMinimumSize(800, 300);
    wyk1->axisY()->setRange(0,25);
    wyk2 = new Chart("Wykres2");
    wyk2->getHandle()->setMinimumSize(800, 300);
}

QGridLayout* MainWindow::setLayout()
{
    QGridLayout* layout;
    layout = new QGridLayout(ui->centralWidget);
    layout->addWidget(wyk1->getHandle());
    layout->addWidget(wyk2->getHandle());
    layout->addWidget(speedSlider);
    return layout;
}

void MainWindow::run()
{
    qDebug() <<"obiektTestowy:"<< obiektTestowy->sim(4);
    csinus->procesuj(Wzadana);
    Wzadana+=0.05;
//    qDebug() <<"run sinus:"<< sinus->procesuj(Wzadana);
//    qDebug() <<"run Wzadana:"<< Wzadana;
}

void MainWindow::setTimerInterval(int tempo)
{
    if (tempo==speedSlider->maximum()) timer->stop();
    else
        if (!timer->isActive()) timer->start();
    timer->setInterval(tempo);
    qDebug() <<"timer interval:"<< timer->interval();
}

QSlider* MainWindow::setSpeedSlider()
{
    QSlider* wsk;
    wsk=new QSlider(Qt::Horizontal,this);
    wsk->setRange(0,1001);
    wsk->setValue(tempo);
    connect(wsk, QOverload<int>::of(&QSlider::valueChanged), [=](int i){ setTimerInterval(i); });
    return wsk;
}

QTimer* MainWindow::setTimer()
{
    QTimer* wsk;
    wsk = new QTimer;
    wsk->setInterval(tempo);  //100ms
    connect(wsk, SIGNAL(timeout()), this, SLOT(run()));
    return wsk;
}

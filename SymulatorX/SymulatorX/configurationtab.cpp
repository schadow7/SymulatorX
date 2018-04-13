#include "configurationtab.h"
#include <QtWidgets>
#include <string>

using namespace std;

ConfigurationTab::ConfigurationTab(QWidget *parent) : QWidget(parent)
{
    createLayout();

    connect(m_button_object,SIGNAL(clicked()),this,SIGNAL(clickedObject()));
    connect(m_button_regulator,SIGNAL(clicked()),this,SIGNAL(clickedRegulator()));
    connect(m_button_load,SIGNAL(clicked()),this,SIGNAL(clickedLoad()));
    connect(m_button_save,SIGNAL(clicked()),this,SIGNAL(clickedSave()));
}

void ConfigurationTab::createLayout()
{
    QGridLayout * layout = new QGridLayout;

    //Stworzenie przycisków...
    m_button_object=new QPushButton;
    m_button_regulator=new QPushButton;
    m_button_save=new QPushButton;
    m_button_load=new QPushButton;
    m_display=new QTextEdit;

    //Dodanie przycisku obiektu
    layout->addWidget(new QLabel(tr("<center>Discrete object</td></center>")), 0,0);
    m_button_object->setIcon(QIcon::fromTheme("object",QIcon(":/images/images/object.png")));
    m_button_object->setIconSize(QSize(64,64));
    layout->addWidget(m_button_object,1,0);

    //Dodanie przycisku regulatora
    layout->addWidget(new QLabel(tr("<center>Discrete regulator</center>")), 2,0);
    m_button_regulator->setIcon(QIcon::fromTheme("regulator",QIcon(":/images/images/regulator.png")));
    m_button_regulator->setIconSize(QSize(64,64));
    layout->addWidget(m_button_regulator,3,0);

    //Dodanie pola do wyświetlania zawartości obiektu/regulatora
    m_display->setPlaceholderText("Click on object/regulator to show properties");
    m_display->setReadOnly(true);
    layout->addWidget(m_display,0,1,6,6);

    //Dodanie przycisków zapisz/wczytaj
    m_button_save->setGeometry(10,10,30,60);
    m_button_save->setText("Save");
    layout->addWidget(m_button_save,6,4);

    m_button_load->setGeometry(10,10,30,60);
    m_button_load->setText("Load");
    layout->addWidget(m_button_load,6,5);

    //Ustawienie minimalnych wysokości wierszy i szerokości kolumn
    layout->setRowMinimumHeight(0,32);
    layout->setRowMinimumHeight(1,72);
    layout->setRowMinimumHeight(2,32);
    layout->setRowMinimumHeight(3,72);
    layout->setRowMinimumHeight(4,32);
    layout->setRowMinimumHeight(5,72);
    layout->setRowMinimumHeight(6,72);

    layout->setColumnMinimumWidth(0,72);
    layout->setColumnMinimumWidth(1,72);
    layout->setColumnMinimumWidth(2,72);
    layout->setColumnMinimumWidth(3,72);
    layout->setColumnMinimumWidth(4,100);
    layout->setColumnMinimumWidth(5,100);

    setLayout(layout);
}


void ConfigurationTab::showConfiguration(std::string text)
{
    string str="Click on object/regulator to show properties\n\n";
    str+=text;
    m_display->setText(QString::fromStdString(str));
}



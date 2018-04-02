#include <QCoreApplication>
#include <vector>
#include "polymonial.h"
#include "objectdiscrete.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector <double> wektor, wektor2;
    wektor.push_back(1);    wektor.push_back(2);    wektor.push_back(11);    wektor.push_back(1.2);
    Polymonial w1(wektor);
    wektor2.push_back(2.8);    wektor2.push_back(4);
    Polymonial w2(wektor2);
    ObjectDiscrete ob1(&w1,&w2,10); ObjectDiscrete ob2;
    //ob1.saveConfig("wentylator.txt");
    ObjectSISO * wskSISO;
    try
    {
        wskSISO=ObjectSISO::createObject("wentylator.txt");
        //ob2.m_polyA->show();
        //ob2.m_polyB->show();
        //cout << ob2.m_delay << endl;
        wskSISO->show();
        wskSISO->saveConfig("obiekt.txt");
    }
    catch(...)
    {
        cout << "Unable to read from file." << endl;
    }

    return a.exec();
}

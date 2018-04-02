#include "objectdiscrete.h"
#include "polymonial.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <exception>
//Brak: jeśli nie jest .txt (zabezpieczenie na nazwe);

using namespace std;

ObjectDiscrete::ObjectDiscrete()
{

}

ObjectDiscrete::ObjectDiscrete(string name)
{
    try
    {
        readConfig(name);
    }
    catch(...)
    {
        throw;
    }
}

ObjectDiscrete::ObjectDiscrete(Polymonial*wA,Polymonial*wB,unsigned int T0)
{
    m_polyA=wA;
    m_polyB=wB;
    m_delay=T0;
    m_dA=m_polyA->size();
    m_dB=m_polyB->size();

}

 ObjectDiscrete::~ObjectDiscrete()
{
     delete m_polyA;
     delete m_polyB;
}

 void ObjectDiscrete::readConfig(string name)
 {
    string line; unsigned int i=0; unsigned int k=0;
    vector<string> keys={"poly1A:","poly1B","delay1"};
    ifstream file;
    try
    {
        file.open(name,ios::in);
        if(file.is_open())
        {
            while(getline(file,line))
            {
                k++;
                if(line[0]=='#')
                    continue;
                else if(line.length()<8)
                    continue;
                else
                {
                    for(i = 0; i<keys.size() ; i++)
                    {
                        if(line.find(keys[i])!=string::npos)
                        {
                            switch(i)
                            {
                                case 0:
                                    m_polyA=checkPoly(line);
                                    m_dA=m_polyA->size();
                                    break;
                                case 1:
                                    m_polyB=checkPoly(line);
                                    m_dB=m_polyB->size();
                                    break;
                                case 2:
                                    m_delay=checkDelay(line);
                                    break;
                            }
                            break;
                        }
                    }

                }
            }
            file.close();
        }
        else
            cout << "Unable to open file" << endl;
    }
    catch (invalid_argument &ia)
    {
        cerr << "Invalid argument in line: " << k << endl;
        cerr << "Thrown by: " << ia.what() << endl;
        throw invalid_argument(ia);
    }
    catch (bad_alloc &ia)
    {
        cerr << "Bad alloc by: " << ia.what() << endl;
        throw bad_alloc(ia);
    }
 }

 void ObjectDiscrete::saveConfig(string name)
 {
    ofstream file;
    try
    {
        file.open(name, ios::out | ios::trunc);
        if (file.is_open())
        {
            file << "#This file is configuration of DiscreteObject named:   " << name.substr(0,name.length()-4) << endl;
            file << "#For information how to create configuration file please check Help in SymulatorX" << endl;
            file << "#Type" << endl;
            file << "type: objectdiscrete" << endl;
            file << "#Polymonial A (first set of parameters)" << endl;
            file << "poly1A:";
            for(int i=0;i<m_polyA->size();i++)
            {
                file <<  " " << (*m_polyA)[i] ;
            }
            file << endl;
            file << "#Polymonial B (first set of parameters)" << endl;
            file << "poly1B:";
            for(int i=0;i<m_polyB->size();i++)
            {
                file <<" "<< (*m_polyB)[i];
            }
            file << endl;
            file << "#Delay (first set of parameters)" << endl;
            file << "delay1: " << m_delay << endl;
            file.close();
        }
        else
            cout << "Unable to open file" << endl;
    }
    catch(...)
    {
        throw;
    }
 }

 Polymonial * ObjectDiscrete::checkPoly(string line)
 {
    vector <double> vec;
    Polymonial * poly;
    try {
            string::size_type sz=0;
            sz=line.find("poly");
            line=line.erase(0,sz+7);
            sz=0; unsigned int x=0; string str=line;
            while(x<line.size())
            {
                double temp = stod(str,&sz);
                vec.push_back(temp);
                str=str.substr(sz);
                x+=sz;
            }
            poly=new Polymonial(vec);
        }
        catch (invalid_argument& ia)
        {
            throw invalid_argument(ia);
        }
        catch (bad_alloc & ia)
        {
            throw bad_alloc(ia);
        }
        return poly;
 }

 double ObjectDiscrete::checkDelay(string line)
 {
    double delay;
    try {
            string::size_type sz=0;
            sz=line.find("delay");
            line=line.erase(0,sz+7);
            sz=0;
            delay = stod(line,&sz);
        }
        catch (invalid_argument& ia)
        {
            throw invalid_argument(ia);
        }
        return delay;
 }

 void ObjectDiscrete::show()
 {
     m_polyA->show();
     m_polyB->show();
     cout << m_dA << endl;
     cout << m_dB << endl;
     cout << m_delay << endl;
 }

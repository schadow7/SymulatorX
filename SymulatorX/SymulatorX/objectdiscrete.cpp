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

ObjectDiscrete::ObjectDiscrete(Polymonial *poly2A, Polymonial *poly2B, unsigned int delay)
{
    m_poly2A=poly2A;
    m_poly2B=poly2B;
    if(m_poly2A)
        m_dA=m_poly2A->size();
    if(m_poly2B)
        m_dB=m_poly2B->size();
    m_delay=delay;
    m_swapTime=0;
}

ObjectDiscrete::ObjectDiscrete(const std::vector<double>* A2,const std::vector<double>* B2,unsigned int deley,const std::vector<double>* A1,const std::vector<double>* B1)
{
    m_delay=deley;
    if (A1) m_poly1A=new Polymonial(*A1);
    if (B1) m_poly1B=new Polymonial(*B1);
    m_poly2A=new Polymonial(*A2);
    m_dA=m_poly2A->size();
    m_y=std::deque<double>(m_dA,0.0);
    m_poly2B=new Polymonial(*B2);
    m_dB=m_poly2B->size();
    m_u=std::deque<double>(m_dB+m_delay,0.0);
}

ObjectDiscrete::~ObjectDiscrete()
{
    delete m_poly1A;
    delete m_poly1B;
    delete m_poly2A;
    delete m_poly2B;
    delete m_distribution;
}

void ObjectDiscrete::readConfig(string name)
{
    string line; unsigned int i=0; unsigned int k=0;
    vector<string> keys={"poly1A","poly1B","delay1","poly2A","poly2B","swaptime","variance"};
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
                            if(line.find("none")!=string::npos)
                                continue;
                            Polymonial*tmp;
                            switch(i)
                            {

                            case 0:
                                tmp=m_poly1A;
                                m_poly1A=checkPoly(line);
                                delete tmp;
                                break;
                            case 1:
                                tmp=m_poly1B;
                                m_poly1B=checkPoly(line);
                                m_dB=m_poly1B->size();
                                delete tmp;
                                break;
                            case 2:
                                m_delay=checkDelay(line);
                                break;
                            case 3:
                                tmp=m_poly2A;
                                m_poly2A=checkPoly(line);
                                m_dA=m_poly2A->size();
                                delete tmp;
                                break;
                            case 4:
                                tmp=m_poly2B;
                                m_poly2B=checkPoly(line);
                                m_dB=m_poly2B->size();
                                delete tmp;
                                break;
                            case 5:
                                m_swapTime=checkSwapTime(line);
                                break;
                            case 6:
                                m_variance=checkVariance(line);
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
            throw ios_base::failure("Unable to read configuration");
    }
    catch (invalid_argument &ia)
    {
        throw invalid_argument(ia);
    }
    catch (bad_alloc &ia)
    {
        throw bad_alloc(ia);
    }
    catch(ios_base::failure &fail)
    {
        throw ios_base::failure("Unable to correctly read configuration");
    }
    m_y=std::deque<double>(m_dA,0.0);
    m_u=std::deque<double>(m_dB+m_delay,0.0);
    if (m_distribution!=NULL) delete m_distribution;
    m_distribution=new std::normal_distribution<> {0,m_variance};
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
            if (m_poly1A!=NULL)
            {
                for(int i=0;i<m_poly1A->size();i++)
                {
                    file <<  " " << (*m_poly1A)[i] ;
                }
                file << endl;
            }
            else
                file << " none" << endl;

            file << "#Polymonial B (first set of parameters)" << endl;
            file << "poly1B:";
            if (m_poly1B!=NULL)
            {
                for(int i=0;i<m_poly1B->size();i++)
                {
                    file <<  " " << (*m_poly1B)[i] ;
                }
                file << endl;
            }
            else
                file << " none" << endl;

            file << "#Polymonial A (second set of parameters)" << endl;
            file << "poly2A:";
            if (m_poly2A!=NULL)
            {
                for(int i=0;i<m_poly2A->size();i++)
                {
                    file <<  " " << (*m_poly2A)[i] ;
                }
                file << endl;
            }
            else
                file << " none" << endl;

            file << "#Polymonial B (second set of parameters)" << endl;
            file << "poly2B:";
            if (m_poly2B!=NULL)
            {
                for(int i=0;i<m_poly2B->size();i++)
                {
                    file <<  " " << (*m_poly2B)[i] ;
                }
                file << endl;
            }
            else
                file << " none" << endl;

            file << "#Delay " << endl;
            file << "delay1: " << m_delay << endl;
            file << "#Swap time" << endl;
            file << "swaptime: " << m_swapTime<< endl;
            file << "#Variance" << endl;
            file << "variance: " << m_variance<< endl;
            file.close();
        }
        else
            throw ios_base::failure("Unable to save configuration");
    }
    catch(ios_base::failure &fail)
    {
        throw ios_base::failure("Unable to correctly save configuration");
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
        throw invalid_argument("Invalid argument (Polymonial)");
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
        throw invalid_argument("Invalid argument (Delay)");
    }
    return delay;
}

int ObjectDiscrete::checkSwapTime(string line)
{
    int swaptime;
    try {
        string::size_type sz=0;
        sz=line.find("swaptime");
        line=line.erase(0,sz+9);
        sz=0;
        swaptime = stoi(line,&sz);
        if (swaptime<0)
            swaptime=0;
    }
    catch (invalid_argument& ia)
    {
        throw invalid_argument("Invalid argument (SwapTime)");
    }
    return swaptime;
}

double ObjectDiscrete::checkVariance(string line)
{
    double var;
    try {
        string::size_type sz=0;
        sz=line.find("variance");
        line=line.erase(0,sz+9);
        sz=0;
        var = stod(line,&sz);
        if (var<0) var=0.0;
    }
    catch (invalid_argument& ia)
    {
        throw invalid_argument("Invalid argument (Variance)");
    }
    return var;
}

string ObjectDiscrete::show()
{
    string str="Object type: objectdiscrete\n";
    str+="Coeffs of polymonials A are displayed from a1 to an, a0 is always equal 1\n";
    if (m_poly1A!=NULL)
        str+="Polymonial 1A:"+m_poly1A->show()+"\n";
    else
        str+="Polymonial 1A: none\n";

    if (m_poly1B!=NULL)
        str+="Polymonial 1B:" + m_poly1B->show()+"\n";
    else
        str+="Polymonial 1B: none\n";

    if (m_poly2A!=NULL)
        str+="Polymonial 2A:" + m_poly2A->show()+"\n";
    else
        str+="Polymonial 2A: none\n";

    if (m_poly2B!=NULL)
        str+="Polymonial 2B:" + m_poly2B->show()+"\n";
    else
        str+="Polymonial 2B: none\n";

    str+="Delay: " + to_string(m_delay) + "\n";

    str+="Swaptime: " + to_string(m_swapTime) + "\n";

    str+="Variance: " + to_string(m_variance) + "\n";

    return str;
}

double ObjectDiscrete::sim(double value)
{
    if (m_time==m_swapTime) swapParameters();
    update(m_u,value);
    double e;
    if (m_c) e=(*m_distribution)(engine);
    else e=0.0;
    double y=(m_poly1B->compute(m_u)+e)-m_poly1A->compute(m_y);
    notify({y,value});
    //notify(y);
    update(m_y,y);
    m_time++;
    return y;
}
void ObjectDiscrete::update(std::deque<double>& queue,double value)
{
    queue.erase(queue.begin());
    queue.push_back(value);
}
void ObjectDiscrete::setSwapTime(unsigned int SwapTime)
{
    if(SwapTime!=0 && (m_poly1A==0 || m_poly1B==0)) throw std::invalid_argument("Setting swap time: no first time of parameters");
    else
        m_swapTime=SwapTime;
}
void ObjectDiscrete::swapParameters()
{
    if(m_time!=0 && (m_poly1A==0 || m_poly1B==0)) throw std::invalid_argument("Attempt to swap: not enough parameters");
    if(m_poly2A==0 || m_poly2B==0) throw std::invalid_argument("Attempt to swap: not enough parameters");
    std::swap(m_poly1A,m_poly2A);
    std::swap(m_poly1B,m_poly2B);
}
void ObjectDiscrete::enableNoise(bool noise)
{
    m_c=noise;
}

bool ObjectDiscrete::checkConfiguration()
{
    if(m_swapTime>0)
    {
        if(m_poly1A!=NULL && m_poly2A!=NULL && m_poly2B!=NULL && m_poly1B!=NULL)
        {
            if(m_poly1A->size()==m_poly2A->size() && m_poly1B->size()==m_poly2B->size())
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
    {
        if(m_poly2A!=NULL && m_poly2B)
            return true;
    }
    return false;
}

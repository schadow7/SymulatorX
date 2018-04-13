#include "regulatorpid.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

RegulatorPID::RegulatorPID()
{

}
RegulatorPID::RegulatorPID(string name)
{
    m_generator=new Generator;
    try
    {
        readConfig(name);
    }
    catch(...)
    {
        throw;
    }
}


RegulatorPID::~RegulatorPID()
{

}



double RegulatorPID::sim(double)
{
    m_set_point=m_generator->gen();
    double offset=m_set_point-m_object_output;
    m_control_value=m_kr*offset;
    return m_control_value;
}


void RegulatorPID::readConfig(string name)
{
    string line; unsigned int i=0; unsigned int k=0;
    vector<string> keys={"kr","Ti","Td"};
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
                else if(line.length()<4)
                    continue;
                else
                {
                    for(i = 0; i<keys.size() ; i++)
                    {
                        if(line.find(keys[i])!=string::npos)
                        {
                            if(line.find("none")!=string::npos)
                                continue;

                            switch(i)
                            {

                            case 0:
                                m_kr=checkKr(line);
                                break;
                            case 1:
                                m_Ti=checkTi(line);
                                break;
                            case 2:
                               m_Td=checkTd(line);
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
}

void RegulatorPID::saveConfig(string name)
{
    ofstream file;
    try
    {
        file.open(name, ios::out | ios::trunc);
        if (file.is_open())
        {
            file << "#This file is configuration of RegulatorPID named:   " << name.substr(0,name.length()-4) << endl;
            file << "#For information how to create configuration file please check Help in SymulatorX" << endl;
            file << "#Type" << endl;
            file << "type: regulatorpid" << endl;
            file << "#Gain " << endl;
            file << "kr: "<<m_kr<< endl;
            file << "#Integral time constant " << endl;
            file << "Ti: "<<m_Ti<< endl;
            file << "#Derivative time constant " << endl;
            file << "Td: "<<m_Td<< endl;

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
string RegulatorPID::show()
{
    string str="Object type: RegulatorPID\n";

        str+="kr:"+to_string(m_kr)+"\n";
        str+="Ti:"+to_string(m_Ti)+"\n";
        str+="Td:"+to_string(m_Td)+"\n";

    return str;
}

bool RegulatorPID::checkConfiguration()
{
 if (m_kr<0 ||m_Ti<0 ||m_Td<0) return false;
 else return true;
}

double RegulatorPID::checkKr(string line)
{
    double val;
    try {
        string::size_type sz=0;
        sz=line.find("kr");
        line=line.erase(0,sz+3);
        sz=0;
        val = stod(line,&sz);
    }
    catch (invalid_argument& ia)
    {
        throw invalid_argument("Invalid argument (kr)");
    }
    return val;
}

double RegulatorPID::checkTi(string line)
{
    double val;
    try {
        string::size_type sz=0;
        sz=line.find("Ti");
        line=line.erase(0,sz+3);
        sz=0;
        val = stod(line,&sz);
    }
    catch (invalid_argument& ia)
    {
        throw invalid_argument("Invalid argument (Ti)");
    }
    return val;
}

double RegulatorPID::checkTd(string line)
{
    double val;
    try {
        string::size_type sz=0;
        sz=line.find("Td");
        line=line.erase(0,sz+3);
        sz=0;
        val = stod(line,&sz);
    }
    catch (invalid_argument& ia)
    {
        throw invalid_argument("Invalid argument (Td)");
    }
    return val;
}
void RegulatorPID::setParameters(vector<double> params)
{
    if (params[0]>=0) m_kr=params[0];
}

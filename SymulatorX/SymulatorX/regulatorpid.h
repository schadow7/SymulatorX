#ifndef REGULATORPID_H
#define REGULATORPID_H
#include "regulator.h"

class RegulatorPID: public Regulator
{
public:
    RegulatorPID();
    ~RegulatorPID();
    void setChartGenerator(Observer*) override;
    void setOffset(double val) override;
    double sim(double) override;
    double gen() override;
    void update(double) override;
    void update(std::vector<double>) override;

    void readConfig(std::string) override;
    void saveConfig(std::string) override;
    std::string show() override;
    bool checkConfiguration() override;
private:
    Generator * m_generator=nullptr;
};

#endif // REGULATORPID_H

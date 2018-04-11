#include "generator.h"

Generator::Generator()
{
    m_offset=3;
}

Generator::~Generator()
{

}

void Generator::setOffset(double offset)
{
    m_offset=offset;
}

double Generator::gen()
{
    notify(m_offset);
    return m_offset;
}

#include "obserwowany.h"
#include "obserwator.h"
#include <algorithm>

Obserwowany::~Obserwowany()
{
}

bool Obserwowany::rejestrujObserwatora(Obserwator * obserwator)
{
    if (std::find(m_obserwatorzy.begin(), m_obserwatorzy.end(), obserwator)==m_obserwatorzy.end())
    {
        m_obserwatorzy.push_back(obserwator);
        return true;
    }
    else
        return false;
}

bool Obserwowany::wyrejestrujObserwatora(Obserwator *obserwator)
{
    std::list<Obserwator *>::iterator it;
    it=std::find(m_obserwatorzy.begin(), m_obserwatorzy.end(), obserwator);
    if (it != m_obserwatorzy.end())
    {
        m_obserwatorzy.erase(it);
        return true;
    }
    else
        return false;
}

void Obserwowany::powiadom(double wartosc) const
{
        std::list<Obserwator *>::const_iterator it =m_obserwatorzy.begin();
        for(; it != m_obserwatorzy.end(); ++it)
        {
            (*it)->aktualizuj(wartosc);
        }
}

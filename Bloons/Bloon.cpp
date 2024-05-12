#include "Bloon.h"
Bloon::Bloon()
{
m_health = 0;
m_location = -1;
}
Bloon::Bloon(int health, int location)
{
    m_health = health;
    m_location = location;
}
Bloon::~Bloon()
{

}
int Bloon::GetHealth()
{
    return m_health;
}
void Bloon::SetHealth(int health)
{
    m_health = health;
}
int Bloon::GetLocation()
{
    return m_location;
}
void Bloon::SetLocation(int location)
{
    m_location = location;
}
ostream& operator<<(ostream& out, Bloon& b)
{
out<< b.m_health << b.m_location;
return out;
}
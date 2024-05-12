#include "Monkey.h"

Monkey::Monkey()
{

}
Monkey::Monkey(string type, int damage, int location)
{
    m_type = type;
    m_damage = damage;
    m_location = location;
}
Monkey::~Monkey()
{

}
int Monkey::GetDamage()
{
    return m_damage;
}
string Monkey::GetType()
{
    return m_type;
}
int Monkey::GetLocation()
{
    return m_location;
}
void Monkey::SetDamage(int inDamage)
{
    m_damage = inDamage;
}
void Monkey::SetType(string type)
{
    m_type = type;
}
void Monkey::SetLocation(int location)
{
    m_location = location;
}
ostream& operator<<(ostream& out, Monkey& m)
{
    out<< m.m_type << "Monkey"<< m.m_damage << m.m_location;
    return out;
}
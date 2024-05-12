#include "Boomerang.h"
Boomerang::Boomerang():
Monkey("Boomerang Monkey",1,1)
{

}
Boomerang::Boomerang(string type, int damage, int location)
:Monkey(type,damage,location)
{

}
Boomerang::~Boomerang()
{
}
int Boomerang::Attack(vector<Bloon*> vec)
{int earnings=0;

for(uint16_t i=0;i<vec.size();++i)
{
    if(vec[i]->GetLocation()==GetLocation())
    {
        cout<< "Boomerang monkey throws a boomerang!"<< endl;
        earnings += vec[i]->Pop(GetDamage()+GetDamage());
    }
}
return earnings;
}

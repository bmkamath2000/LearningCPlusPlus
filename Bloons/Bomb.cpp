#include "Bomb.h"
Bomb::Bomb()
{

}
Bomb::Bomb(string type, int damage, int location)
:Monkey(type,damage,location)
{

}
Bomb::~Bomb()
{

}
int Bomb::Attack(vector<Bloon*> vec)
{int earnings=0;

for(uint16_t i=0;i<vec.size();++i)
{
    if(vec[i]->GetLocation()==GetLocation())
    {
        cout<< "bomb shooter launches a bomb"<< endl;
        earnings += vec[i]->Pop(GetDamage());

    }
}
return earnings;
}
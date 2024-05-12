#include "Dart.h"
Dart::Dart()
{

}
Dart::Dart(string type, int damage, int location)
:Monkey(type,damage,location)
{

}
Dart::~Dart()
{

}
int Dart::Attack(vector<Bloon*> vec)
{
uint16_t i=0;
while(i<vec.size()&&vec[i]->GetLocation()!=GetLocation())
{
    ++i;
}
int earnings = vec[i]->Pop(GetDamage());
cout<< "The dart monkey shoots a dart!"<< endl;
return earnings;
}
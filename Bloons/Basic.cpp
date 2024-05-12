#include "Basic.h"
 Basic::Basic()
 {

 }
 Basic::Basic(int health, int location)
 :Bloon(health,location)
 {
  switch(health)
  {
  case red: m_color = "Red";break;
  case blue: m_color = "Blue";break;
  case green: m_color = "Green";break;
  case yellow: m_color = "Yellow";break;
  case pink: m_color = "Pink";break;
  case black: m_color = "Black";break;
  }
 }
 Basic::~Basic()
 {

 }
 int Basic::Pop(int damage)
 {
    int health = Bloon::GetHealth();
    if((health-damage)<=0)
    {
      cout<< "A "<<m_color<< "Bloon Popped!"<< endl;
      cout<< "The bloon is now gone!"<< endl;
      Bloon::SetHealth(0);
      return 1;
    }
    else {
      Bloon::SetHealth(health-damage);
      switch(Bloon::GetHealth())
      {
      case red: m_color = "Red";break;
      case blue: m_color = "Blue";break;
      case green: m_color = "Green";break;
      case yellow: m_color = "Yellow";break;
      case pink: m_color = "Pink";break;
      case black: m_color = "Black";break;
      }
      cout<< "The bloon is now "<<m_color<< endl;
    }
    return 0;
 }
 string Basic::GetColor()
 {
   return m_color;
 }
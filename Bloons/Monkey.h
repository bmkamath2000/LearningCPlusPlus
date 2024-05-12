
#ifndef MONKEY_H_
#define MONKEY_H_
#include "Bloon.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

//Parent class for all factions                                                                                                                                                                             
class Monkey {
 public:
  // Name: Monkey() - Default Constructor                                                                                                                                                                   
  // Description: Abstract class - cannot directly instantiate this class                                                                                                                                   
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: Populates variables used in child classes (may not be specifically used)                                                                                                               
  Monkey();
  // Name: Monkey(string type, int damage, int location) - Overloaded Constructor                                                                                                                           
  // Description: Abstract class - cannot directly instantiate this class                                                                                                                                   
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: Populates variables used in child classes                                                                                                                                              
  Monkey(string, int, int);
  // Name: virtual ~Monkey - Virtual Destructor                                                                                                                                                             
  // Description: Makes sure everything in child class is deallocated                                                                                                                                       
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: Everything dynamically allocated is deallocated                                                                                                                                        
  virtual ~Monkey();
  // Name: GetDamage()                                                                                                                                                                                      
  // Description: Returns damage of monkey                                                                                                                                                                  
  // Preconditions: Monkey has damage defined                                                                                                                                                               
  // Postconditions: None                                                                                                                                                                                   
  int GetDamage();
  // Name: GetType()                                                                                                                                                                                        
  // Description: Returns types of monkey                                                                                                                                                                   
  // Preconditions: Monkey has a type defined                                                                                                                                                               
  // Postconditions: None                                                                                                                                                                                   
  string GetType();
  // Name: GetLocation()                                                                                                                                                                                    
  // Description: Returns location of monkey on track                                                                                                                                                       
  // Preconditions: Monkey is on the track                                                                                                                                                                  
  // Postconditions: None                                                                                                                                                                                   
  int GetLocation();
  // Name: SetDamage()                                                                                                                                                                                      
  // Description: Sets damage of monkey                                                                                                                                                                     
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: Damage is set
  void SetDamage(int);
  // Name: SetType()                                                                                                                                                                                        
  // Description: Sets type of monkey (dart, bomb, or boomerang)                                                                                                                                            
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: Type is set                                                                                                                                                                            
  void SetType(string);
  // Name: SetLocation()                                                                                                                                                                                    
  // Description: Sets location of monkey on track                                                                                                                                                          
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: Type is set                                                                                                                                                                            
  void SetLocation(int);
  // Name: Attack()                                                                                                                                                                                         
  // Description: Defines attack for an monkey                                                                                                                                                              
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: None (Purely virtual - must be in child classes)                                                                                                                                       
  virtual int Attack(vector<Bloon*>) = 0;
  // Name: Overloaded <<                                                                                                                                                                                    
  // Description: Prints the details of a monkey                                                                                                                                                            
  // Preconditions: all variables are set valid                                                                                                                                                             
  // Postconditions: returns an ostream with output of monkey                                                                                                                                               
  friend ostream& operator<<(ostream&, Monkey&);
private:
  int m_damage; //Damage of monkey                                                                                                                                                                          
  string m_type; //Type of monkey (Dart, Bomb, or Boomerang)                                                                                                                                                
  int m_location; //Location of monkey on track                                                                                                                                                             
};

#endif
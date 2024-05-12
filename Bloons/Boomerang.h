#ifndef BOOMERANG_H_
#define BOOMERANG_H_

#include "Monkey.h"

// Boomerang monkey hurls a boomerang that follows a curved path. Good range and pierce.                                                                                                                    

class Boomerang: public Monkey {
 public:
  // Name: Boomerang() - Default Constructor                                                                                                                                                                
  // Description: Creates a new Boomerang Monkey                                                                                                                                                            
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: Can create a Boomerang Monkey                                                                                                                                                          
  Boomerang();
  // Name: Boomerang(string type, int damage, int location)                                                                                                                                                 
  // Description: Creates a new Boomerang Monkey                                                                                                                                                            
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: Can create a Boomerang Monkey                                                                                                                                                          
  Boomerang(string, int, int);
  // Name: ~Boomerang - Virtual Destructor                                                                                                                                                                  
  // Description: Makes sure everything in child class is deallocated                                                                                                                                       
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: Everything dynamically allocated is deallocated                                                                                                                                        
  ~Boomerang();
  // Name: Attack                                                                                                                                                                                           
  // Description: Iterates through all bloons. For each bloon in the same location as boomerang,                                                                                                            
  //              hits each bloon twice (once out and once back)                                                                                                                                            
  //              Returns total bloon health or damage (whichever is less) for earnings (money)                                                                                                             
  // Preconditions: Bloons must be in same location as Boomerang Monkey                                                                                                                                     
  // Postconditions: Damages each bloon and returns earnings (total pops)                                                                                                                                   
  int Attack(vector<Bloon*>);
};
#endif
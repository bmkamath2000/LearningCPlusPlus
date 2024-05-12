#ifndef DART_H_
#define DART_H_

#include "Monkey.h"

// The Dart is the basic dart monkey. Throws a single dart at a Bloons.                                                                                                                                     
// Low damage but cheap.                                                                                                                                                                                    

class Dart: public Monkey {
 public:
  // Name: Dart() - Default Constructor                                                                                                                                                                     
  // Description: Creates a new Dart Monkey                                                                                                                                                                 
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: Can create a Dart Monkey                                                                                                                                                               
  Dart();
  // Name: Dart(string type, int damage, int location)                                                                                                                                                      
  // Description: Creates a new Dart Monkey                                                                                                                                                                 
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: Can create a Dart Monkey                                                                                                                                                               
  Dart(string, int, int);
  // Name: ~Dart - Virtual Destructor                                                                                                                                                                       
  // Description: Makes sure everything in child class is deallocated                                                                                                                                       
  // Preconditions: None                                                                                                                                                                                    
  // Postconditions: Everything dynamically allocated is deallocated                                                                                                                                        
  ~Dart();
  // Name: Attack                                                                                                                                                                                           
  // Description: Iterates through all bloons. Hits first bloon in the same location as dart.                                                                                                               
  //              Returns total bloon health or damage (whichever is less) for earnings (money)                                                                                                             
  // Preconditions: Bloon must be in same location as Dart monkey                                                                                                                                           
  // Postconditions: Damages one bloon and returns earnings (total pops)                                                                                                                                    
  int Attack(vector<Bloon*>);
};
#endif
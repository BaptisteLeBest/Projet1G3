#include "coeur.h"
#include "Arduino.h" 

int z,o; 

void un_deux()
{
  //répétition 10 fois 
  while (1)
  {
    o = random(750,770);
    // Allumage d'une led sur deux à la suite 
    for (z=2 ; z<=11; z+=2)
    {      
      digitalWrite(z,HIGH);      
    }
    delay(100);
    // Etaignage d'une led sur deux à la suite 
    for (z=2 ; z<=11; z+=2)
    {
      digitalWrite(z,LOW);      
    }
    //Délai aléatoire cohérent avec de réelles valeurs de pouls 
    delay(o);
    
  }
  
  
    
  
  
}

#include "coeur.h"
#include "Arduino.h" 

int z,h,o; 

void un_deux()
{
  //répétition 10 fois 
  while (h<=10)
  {
    o = random(750,770);
    // Allumage d'une led sur deux à la suite 
    for (z=2 ; z<=11; z+=2)
    {      
      digitalWrite(z,HIGH);      
    }
    delay(100);
    for (z=2 ; z<=11; z+=2)
    {
      digitalWrite(z,LOW);      
    }
    delay(o);
    h = h+1; 
  }
  loop();
  
    
  
  
}

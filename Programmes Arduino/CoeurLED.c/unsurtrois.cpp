#include "coeur.h"
#include "Arduino.h" 

int c,n;
void un_trois()
{ 
   
    // Allumage d'une led sur trois à la suite 
    while(1)
    {
      n = random(750, 770);
      digitalWrite(2,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(11,HIGH);       
      delay(100); 
      digitalWrite(2,LOW);
      digitalWrite(5,LOW);
      digitalWrite(8,LOW);
      digitalWrite(11,LOW);       
      delay(n);
    }
    
   
   loop();
    
}

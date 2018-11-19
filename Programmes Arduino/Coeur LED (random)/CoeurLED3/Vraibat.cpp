#include "coeur.h"
#include "Arduino.h"

#ifndef VRAIBAT
#define VRAIBAT
  
int x; 

void vraibat(){ 

  while(1){
       
        x = random(750,770);
        ledup(); 
        delay(100);
        ledlow();
        //delai aléatoire cohérent avec des valeurs de pouls 
        delay(x);        
  }
       
     
}

#endif

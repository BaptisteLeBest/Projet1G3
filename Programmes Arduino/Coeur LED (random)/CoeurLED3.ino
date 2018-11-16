
#include "coeur.h"
#include "param.h"

#ifndef choixLED
#define choixLED 0
#endif

void setup() {
 Serial.begin(9600); 
   for(int i = 2; i <= 11; i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop() 
{
  Serial.println(choix);
  // Choisir le mode d'allumage 
   if (choix==1)
      {
       Serial.println("Vous avez choisi de tout allumer");
        vraibat(); 
      }
   else if (choix>=5)
     {
      Serial.println("Vous avez choisi d'allumer une led de votre choix");
         
     }
   else if (choix==2) 
     {
      Serial.println("Vous avez choisi d'allumer les leds une par une ");
      one_led();
     }
   else if (choix==3) 
    {
      Serial.println("Vous avez choisi d'allumer une led sur deux");
      un_deux(); 
    }
   else if (choix==4) 
    {
      Serial.println("Vous avez choisi d'allumer une led sur trois");
      un_trois();
    }
}

#include "coeur.h" 
#include "Arduino.h" 

void ledup()
{
  //Allumage des leds sur les pins digitales de 2 à 11 
  for(int i = 2; i <= 11; i++)
  {
    digitalWrite(i,HIGH);
  }
}

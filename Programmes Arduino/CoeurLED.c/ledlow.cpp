#include "coeur.h" 
#include "Arduino.h"

void ledlow()
{
   //Eteignage des leds aux pins digitales allant de 2 à 11 
  for(int i = 2; i <= 11; i++)
  {
    digitalWrite(i,LOW);
  }
}

#include "coeur.h" 
#include "Arduino.h"

void ledlow()
{ 
  //Eteignage des LEDS des pins 2 à 11 
  for(int i = 2; i <= 11; i++)
  {
    digitalWrite(i,LOW);
  }
}

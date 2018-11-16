#include "coeur.h" 
#include "Arduino.h" 

void ledup()
{
  for(int i = 2; i <= 11; i++)
  {
    digitalWrite(i,HIGH);
  }
}

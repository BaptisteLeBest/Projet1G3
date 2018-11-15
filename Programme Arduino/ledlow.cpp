#include "coeur.h" 
#include "Arduino.h"

void ledlow()
{
  for(int i = 2; i <= 11; i++)
  {
    digitalWrite(i,LOW);
  }
}

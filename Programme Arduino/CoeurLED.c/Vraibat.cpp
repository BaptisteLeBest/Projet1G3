#include "coeur.h"
#include "Arduino.h"

#ifndef VRAIBAT
#define VRAIBAT
  
int valeurPrecedente = 0;
int tempsPrecedent = 0;
int Ledbat,calc;

void vraibat(int led) {
  int valeurActuelle, valeurSeuil;
  int tempsDetection;

  valeurActuelle = analogRead(0);
  valeurSeuil = 200;

  if (valeurActuelle > valeurSeuil) {  
    if (valeurPrecedente <= valeurSeuil) {  
      tempsDetection = millis();
      //if (tempsDetection > (tempsPrecedent + 200)){  
        Ledbat = (1000.0 * 60.0) / (tempsDetection - tempsPrecedent);
        if(Ledbat > 30 && Ledbat < 300)
        {
          Serial.println(Ledbat);
          if(led > 0)
          {
            digitalWrite(led,HIGH);
            delay(50);
            digitalWrite(led,LOW);
          } else {
            ledup(); 
             delay(50);
             ledlow(); 
          }
          //delay((1000/Ledbat)*60);
          tempsPrecedent = tempsDetection;
        }
      //}
    }
  }
  valeurPrecedente = valeurActuelle;
}

#endif

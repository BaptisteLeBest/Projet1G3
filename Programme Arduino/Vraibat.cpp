#include "coeur.h"
#include "Arduino.h"
  
int valeurPrecedente = 0;
int tempsPrecedent = 0;
int Ledbat,calc;

void vraibat() {
  int valeurActuelle, valeurSeuil;
  int tempsDetection;

  valeurActuelle = analogRead(0);
  valeurSeuil = 390;
  
  if (valeurActuelle > valeurSeuil) {  
    if (valeurPrecedente <= valeurSeuil) {  
      tempsDetection = millis();
      if (tempsDetection > (tempsPrecedent + 200)){  
        Ledbat = (1000.0 * 60.0) / (tempsDetection - tempsPrecedent);
        if(Ledbat > 40 && Ledbat < 120)
        {
          Serial.println(Ledbat);
          ledup(); 
          delay(50);
          ledlow(); 
          //delay((1000/Ledbat)*60);
          tempsPrecedent = tempsDetection;
        }
      }
    }
  }
  valeurPrecedente = valeurActuelle;
}

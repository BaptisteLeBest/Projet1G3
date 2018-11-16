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

  valeurActuelle = analogRead(0); // lecture de la sortie A0
  valeurSeuil = 300; // // Valeur Seuil d'analog0 avant enregistrement de battements 

  //Serial.println(valeurActuelle);
  if (valeurActuelle > valeurSeuil) {  
    if (valeurPrecedente <= valeurSeuil) {  
      tempsDetection = millis(); // détection du temps depuis le démarrage du programme 
      if (tempsDetection > (tempsPrecedent + 200)){  
        Ledbat = (1000.0 * 60.0) / (tempsDetection - tempsPrecedent); // Calcul des battements de coeurs en battements par minutes 
        if(Ledbat > 30 && Ledbat < 120) // intervalle de battements défini à cause de l'imprecision de la led infrarouge 
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
      }
    }
  }
  valeurPrecedente = valeurActuelle;
}

#endif

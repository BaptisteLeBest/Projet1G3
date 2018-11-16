#include "coeur.h"
#include "Arduino.h" 

int ValeurPrecedente = 0;
int TempsPrecedent = 0;
int Ledba,z; 

void un_deux(int led)
{
   while(1) 
   {
      int ValeurActuelle, ValeurSeuil;
      int TempsDetection;

       ValeurActuelle = analogRead(0); // lecture de la sortie A0
       ValeurSeuil = 300; // // Valeur Seuil d'analog0 avant enregistrement de battements 

       
        if (ValeurActuelle > ValeurSeuil) {  
          if (ValeurPrecedente <= ValeurSeuil) {  
            TempsDetection = millis(); // détection du temps depuis le démarrage du programme 
            if (TempsDetection > (TempsPrecedent + 200)){  
              Ledba = (1000.0 * 60.0) / (TempsDetection - TempsPrecedent); // Calcul des battements de coeurs en battements par minutes 
              if(Ledba > 30 && Ledba < 120) // intervalle de battements défini à cause de l'imprecision de la led infrarouge 
              {
                Serial.println(Ledba); 
                //Allumage des leds 1 sur 2 
                for (z =2; z<=11 ; z+=2){
                  digitalWrite(z,HIGH); 
                }
                delay(100);
                //Eteignage des leds 1 sur 2 
                for (z =2; z<=11 ; z+=2){
                  digitalWrite(z,LOW); 
                }
                //delay((1000/Ledbat)*60);
                TempsPrecedent = TempsDetection;
              }
      }
    }
  }
  ValeurPrecedente = ValeurActuelle;
   }
  
}
    
  
  

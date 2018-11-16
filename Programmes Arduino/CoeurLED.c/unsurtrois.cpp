#include "coeur.h"
#include "Arduino.h" 


int ValeurPrecedent = 0;
int TempsPreceden = 0;
int ledba,c;

void un_trois()
{ 
   
    // Allumage d'une led sur trois à la suite 
    while(1)
    {
      int ValeurActuel, ValeurSeui;
      int TempsDetectio;

       ValeurActuel = analogRead(0); // lecture de la sortie A0
       ValeurSeui = 300; // // Valeur Seuil d'analog0 avant enregistrement de battements 

       
        if (ValeurActuel > ValeurSeui) {  
          if (ValeurPrecedent <= ValeurSeui) {  
            TempsDetectio = millis(); // détection du temps depuis le démarrage du programme 
            if (TempsDetectio > (TempsPreceden + 200)){  
              ledba = (1000.0 * 60.0) / (TempsDetectio - TempsPreceden); // Calcul des battements de coeurs en battements par minutes 
              if(ledba > 30 && ledba < 120) // intervalle de battements défini à cause de l'imprecision de la led infrarouge 
              {
                Serial.println(ledba); 
                //Allumage des leds 1 sur 2 
                for (c =2; c<=11 ; c+=3){
                  digitalWrite(c,HIGH); 
                }
                delay(100);
                //Eteignage des leds 1 sur 2 
                for (c =2; c<=11 ; c+=3){
                  digitalWrite(c,LOW); 
                }
                //delay((1000/ledba)*60);
                TempsPreceden = TempsDetectio;
              }
              }
            }
          }
  ValeurPrecedent = ValeurActuel;
    }
    
   
   
    
}

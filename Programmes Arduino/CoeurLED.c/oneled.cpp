#include "coeur.h" 
#include "Arduino.h" 

int ValeurPrecedentee = 0;
int TempsPrecedente = 0;
int Ledbatt,m; 

void one_led()
{    
      while(1) 
   {
      int ValeurActuellee, ValeurSeuile;
      int TempsDetectione;

       ValeurActuellee = analogRead(0); // lecture de la sortie A0
       ValeurSeuile = 300; // // Valeur Seuil d'analog0 avant enregistrement de battements 

       
        if (ValeurActuellee > ValeurSeuile) {  
          if (ValeurPrecedentee <= ValeurSeuile) {  
            TempsDetectione = millis(); // détection du temps depuis le démarrage du programme 
            if (TempsDetectione > (TempsPrecedente + 200)){  
              Ledbatt = (1000.0 * 60.0) / (TempsDetectione - TempsPrecedente); // Calcul des battements de coeurs en battements par minutes 
              if(Ledbatt > 30 && Ledbatt < 120) // intervalle de battements défini à cause de l'imprecision de la led infrarouge 
              {
                Serial.println(Ledbatt); 
                //Allumage des leds 1 sur 2 
                for (m =2; m<=11 ; m++){
                  digitalWrite(m,HIGH); 
                  delay(100); 
                  digitalWrite(m,LOW);
                }
                
                //delay((1000/Ledbatt)*60);
                TempsPrecedente = TempsDetectione;
              }
      }
    }
  }
  ValeurPrecedentee = ValeurActuellee;
   }
  
}

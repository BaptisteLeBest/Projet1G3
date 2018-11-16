#include "car.h" 
#include "Arduino.h" 

unsigned long time; 
int valeurPrecedente = 0;
long tempsPrecedent = 0;

void Card() {
  

  int valeurActuelle, valeurSeuil;
 long tempsDetection;

  valeurActuelle = analogRead(0);
  //Serial.println(valeurActuelle);
  valeurSeuil = 380;

  
 if (valeurActuelle > valeurSeuil) {  // on est dans la zone max
    if (valeurPrecedente <= valeurSeuil) {  // est-ce qu'on vient d'y entrer?
      tempsDetection = millis();
      if (tempsDetection > (tempsPrecedent + 200)){  // ce n'est pas seulement du bruit?
        Serial.print( (1000.0 * 60.0) / (tempsDetection - tempsPrecedent),0);
        tempsPrecedent = tempsDetection;
        Serial.print(";");
        time = millis();
       Serial.println(time);
      }
    }
  }
  
  valeurPrecedente = valeurActuelle;
  

}

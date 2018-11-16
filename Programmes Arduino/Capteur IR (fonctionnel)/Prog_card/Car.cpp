#include "car.h" 
#include "Arduino.h" 

unsigned long time; 
int valeurPrecedente = 0;
long tempsPrecedent = 0;
int Ledbat,calc;

void Card(){
  

  int valeurActuelle, valeurSeuil;
  long tempsDetection;

  valeurActuelle = analogRead(0);
  valeurSeuil = 300;

  
  if (valeurActuelle > valeurSeuil) {  
    if (valeurPrecedente <= valeurSeuil) {  
      tempsDetection = millis();
      if (tempsDetection > (tempsPrecedent + 200)){  
        Ledbat = (1000.0 * 60.0) / (tempsDetection - tempsPrecedent);
        if(Ledbat > 30 && Ledbat < 120)
        {
          time = millis();
          Serial.println(time);          
          Serial.print(";");
          Serial.print(Ledbat);
         
          
          //delay((1000/Ledbat)*60);
          tempsPrecedent = tempsDetection;
        }
      }
    }
  }
  valeurPrecedente = valeurActuelle;
}

#include "coeur.h" 
#include "Arduino.h" 

int t,v,m; 
void one_led()
{    
      // 10 répétitions de l'allumage de toutes les leds 
      while (v<=10)
      {
         for (t=2; t<=11; t++) 
        {
          //Allulage des leds une par une en éteignant la precédente. 
          m = random(750,770);
          digitalWrite(t,HIGH); 
          delay(100);
          digitalWrite(t,LOW);
          delay(m);
          
        }
        v = v+1;  
      }
       
     loop(); 
     
    
}

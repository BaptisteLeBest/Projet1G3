#include "menu.h"
#include <stdio.h>

void menu ()
{
    int pulsation = 1;

    printf("*** Afficher les differents cliniotements ***\n\n");

    //Differents message qui demande de faire l'action pour les differents clignotements des LEDS
    while ((pulsation >0) && (pulsation <7))
    {
        printf("Choisir les differents clignotements \n");
        printf("(1)     Faire clignioter les LEDS au rythme du coeur \n");
        printf("(2)     Faire clignioter les LEDS sous forme de chenille au rythme du coeur \n");
        printf("(3)     Faire clignioter les LEDS 1 sur 2 \n");
        printf("(4)     Faire clignioter les LEDS 1 sur 3 \n");
        printf("(5)     Choisir la LED que vous voulez \n");
        printf("(6)     Eteindre les LEDS \n");
        printf("(autre)     Quitter \n\n");

        scanf("%d" , &pulsation);

        generationCode(pulsation);
    }
}

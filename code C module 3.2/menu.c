#include "menu.h"
#include <stdio.h>

void menu ()
{
    int pulsation = 1;

    printf("*** Afficher les differents cliniotements ***\n\n");

    while ((pulsation >0) && (pulsation <5))
    {
        printf("Choisir les differents clignotements \n");
        printf("(1)     Faire cligniote les LEDS au rythme du coeur \n");
        printf("(2)     Faire cligniote les LEDS sous forme de chenille au rythme du coeur \n");
        printf("(3)     Faire cligniote les LEDS 1 sur 2 \n");
        printf("(4)     Faire cligniote les LEDS 1 sur 3 \n");
        printf("(autre)     Quitter \n\n");

        scanf("%d" ,&pulsation);

        switch(pulsation)
        {

            case 1 :
            {
                generationCode(pulsation);
                break;
            }

            case 2 :
                {
                    generationCode(pulsation);
                    break;
                }

            case 3 :
                {
                    generationCode(pulsation);
                    break;
                }

            case 4 :
                {
                    generationCode(pulsation);
                    break;
                }
            default :
                {
                }
        }
    }
}

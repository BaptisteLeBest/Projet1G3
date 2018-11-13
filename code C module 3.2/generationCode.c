#include "generationCode.h"
#include <stdio.h>

int generationCode(int pulsation)
{
    FILE *f;

    f = fopen("param.h", "w");

    if(f == NULL)
    {
        printf("Echec d'ouverture du fichier\n");
    }
    else
    {
        switch(pulsation)
        {

            case 1 :
            {
                printf("choix\n");
                fprintf(f, "clignote les LEDS au rythme du coeur");
                break;
            }

            case 2 :
                {
                    fprintf(f, "clignotes les LEDS sous forme de chenille");
                    break;
                }

            case 3 :
                {
                    fprintf(f, "clignotes les LEDS 1 sur 2");
                    break;
                }

            case 4 :
                {
                    fprintf(f, "clignotes les LEDS 1 sur 3");
                    break;
                }
            default :
                {
                }
        }
        fclose(f);
    }
return 0;
}


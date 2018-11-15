#include "generationCode.h"
#include <stdio.h>

int choixLED = 0;
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

//Partie qui fait fonctionner pour le cas 5 qui demande de choisir entre un interval et pas le depasser
        if (pulsation == 5)
        {
            do
            {
                printf("Veuillez choisir la LED  que vous voulez entre 1 et 10\n");
                scanf("%d" , &choixLED);
            }
            while(choixLED < 1 || choixLED > 10);
            fprintf(f, "#define choixLED %d\n", choixLED);
        }

//Ca crée une varible choix qui depend de la valeur pulsation entrée
        fprintf(f, "#define choix %d", pulsation);
        fclose(f);
    }

return 0;
}


#define _CRT_SECURE_NO_DEPRECATE

#define SIZE_LIST 10

#include "menu.h"
#include "donnees.h"
#include "actions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu()
{
	int type_tri = 0;
	int choix_type_tri = 0;
	int choix = 1;
	while ((choix > 0) && (choix < 6))
	{
		system("cls");
		printf("Que souhaitez-vous faire?\n\n");
		printf("(1) Afficher les donnees\n");
		printf("(2) Afficher les donnees triees\n");
		printf("(3) Rechercher les donnees pour un temps particulier\n");
		printf("(4) Moyenne pouls sur intervalle de temps\n");
		printf("(autre) Quitter\n");

		scanf("%d", &choix);

		switch (choix)
		{
		case 1:
		{
			data *listeData = NULL;
			listeData = chargeData();
			data *list[100];
			int i = 0;
			listeData = listeData->nextData;
			while (listeData->nextData != NULL)
			{
				list[i] = listeData;
				listeData = listeData->nextData;
				i++;
			}

			afficherToutData(list, SIZE_LIST);

			break;
		}
		case 2:
		{
			data *listeData = NULL;
			listeData = chargeData();
			data *list[100];
			int i = 0;
			listeData = listeData->nextData;
			while (listeData->nextData != NULL)
			{
				list[i] = listeData;
				listeData = listeData->nextData;
				i++;
			}

			printf("Par quoi voulez-vous trier?\n\n");
			printf("(1) Le temps\n");
			printf("(2) Le pouls\n");
			scanf("%d", &choix_type_tri);

			if (choix_type_tri == 1) {
				printf("Quel ordre de tri pour le temps?\n\n");
				printf("(1) Croissant\n");
				printf("(2) Decroissant\n");
				scanf("%d", &choix_type_tri);
				if (choix_type_tri == 1) {
					type_tri = 0;
				}
				else if (choix_type_tri == 2) {
					type_tri = 1;
				}
			}
			else if (choix_type_tri == 2) {
				printf("Quel ordre de tri pour le pouls?\n\n");
				printf("(1) Croissant\n");
				printf("(2) Decroissant\n");
				scanf("%d", &choix_type_tri);
				if (choix_type_tri == 1) {
					type_tri = 2;
				}
				else if (choix_type_tri == 2) {
					type_tri = 3;
				}
			}

			tri_a_bulles(&list, SIZE_LIST, type_tri);
			printf("Tri reussi\n");
			afficherToutData(list, SIZE_LIST);

			break;
		}
		case 3:
		{
			int size_list_temps = 0;
			int temps_recherche;
			data *list[100];
			printf("Pour quel temps voulez-vous obtenir les donnees?\n");
			scanf("%d", &temps_recherche);

			data *listeData = NULL;
			listeData = chargeData();
			int i = 0;
			listeData = listeData->nextData;
			while (listeData->nextData != NULL)
			{
				if (listeData->a == temps_recherche) {
					list[i] = listeData;
					i++;
					size_list_temps++;
				}
				listeData = listeData->nextData;
			}
			afficherToutData(list, size_list_temps);

			break;
		}
		case 4:
		{
			int size_list_temps = 0;
			int temps_debut;
			int temps_fin;
			printf("Temps de debut?\n");
			scanf("%d", &temps_debut);
			printf("Temps de fin?\n");
			scanf("%d", &temps_fin);

			data *listeData = NULL;
			listeData = chargeData();
			data *list[100];
			int i = 0;
			listeData = listeData->nextData;
			while (listeData->nextData != NULL)
			{
				if (listeData->a >= temps_debut && listeData->a <= temps_fin)
				{
					list[i] = listeData;
					i++;
					size_list_temps++;
				}
				listeData = listeData->nextData;
			}

			int totPouls = 0;
			for (int j = 0; j < size_list_temps; j++)
			{
				totPouls += list[j]->b;
			}
			float moyennePouls;
			moyennePouls = (float)totPouls / (float)size_list_temps;
			printf("Pouls moyen: %f\n", moyennePouls);

			break;
		}
		default:
		{
			printf("CIAO !\n");
		}
		}
		system("pause");
	}
	return 0;
}
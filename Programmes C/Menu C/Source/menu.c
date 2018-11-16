#define _CRT_SECURE_NO_DEPRECATE

#include "menu.h"
#include "donnees.h"
#include "actions.h"

#include "generationCode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu()
{
	int choix = 1;
	while ((choix > 0) && (choix < 3))
	{
		system("cls");
		printf("Que souhaitez-vous faire?\n");
		printf("(1) Choisir le clignotement des LEDs\n");
		printf("(2) Gestion du fichier CSV\n");
		printf("(autre) Quitter\n");

		scanf("%d", &choix);

		switch (choix)
		{
		case 1:
		{
			menu_led();
			break;
		}
		case 2:
		{
			menu_csv();
			break;
		}
		default:
		{
			printf("Fermeture du programme !\n");
		}
		}

	}
	return 0;
}

int menu_led()
{
	int pulsation = 1;

	printf("*** Afficher les differents cliniotements ***\n\n");

	//Differents message qui demande de faire l'action pour les differents clignotements des LEDS
	while ((pulsation > 0) && (pulsation < 7))
	{
		system("cls");
		printf("Choisir les differents clignotements \n");
		printf("(1)     Faire clignioter les LEDS au rythme du coeur \n");
		printf("(2)     Faire clignioter les LEDS sous forme de chenille au rythme du coeur \n");
		printf("(3)     Faire clignioter les LEDS 1 sur 2 \n");
		printf("(4)     Faire clignioter les LEDS 1 sur 3 \n");
		printf("(5)     Choisir la LED que vous voulez \n");
		printf("(6)     Eteindre les LEDS \n");
		printf("(autre)     Quitter \n\n");

		scanf("%d", &pulsation);

		generationCode(pulsation);

		printf("Fichier param.h mis a jour\n");
		system("pause");
	}
	return 0;
}

int menu_csv()
{
	int choix = 1;
	while ((choix > 0) && (choix < 6))
	{
		system("cls");
		printf("Que souhaitez-vous faire?\n");
		printf("(1) Afficher les donnees\n");
		printf("(2) Afficher les donnees triees\n");
		printf("(3) Rechercher les donnees pour un temps particulier\n");
		printf("(4) Moyenne pouls sur intervalle de temps\n");
		printf("(5) Pouls max et pouls min\n");
		printf("(autre) Quitter\n");

		scanf("%d", &choix);

		switch (choix)
		{
		case 1:
		{
			// Initialisation et chargement de la liste de structures
			data *listeData = NULL;
			listeData = chargeData();

			// Transformation de la liste en tableau
			data *tableau_data[1000];
			creerTableau(listeData, tableau_data);

			// Affichage du tableau
			afficherToutData(tableau_data);

			break;
		}
		case 2:
		{
			int type_tri = 0;
			int choix_type_tri = 0;

			data *listeData = NULL;
			listeData = chargeData();

			data *tableau_data[1000];
			creerTableau(listeData, tableau_data);

			printf("Par quoi voulez-vous trier?\n");
			printf("(1) Le temps\n");
			printf("(2) Le pouls\n");
			scanf("%d", &choix_type_tri);

			// Tri par temps
			if (choix_type_tri == 1) {
				printf("Quel ordre de tri pour le temps?\n");
				printf("(1) Croissant\n");
				printf("(2) Decroissant\n");
				scanf("%d", &choix_type_tri);
				if (choix_type_tri == 1) {
					type_tri = 0; // Tri par temps croissant
				}
				else if (choix_type_tri == 2) {
					type_tri = 1; // Tri par temps decroissant
				}
			}
			// Tri par pouls
			else if (choix_type_tri == 2) {
				printf("Quel ordre de tri pour le pouls?\n");
				printf("(1) Croissant\n");
				printf("(2) Decroissant\n");
				scanf("%d", &choix_type_tri);
				if (choix_type_tri == 1) {
					type_tri = 2; // Tri par pouls croissant
				}
				else if (choix_type_tri == 2) {
					type_tri = 3; // Tri par pouls decroissant
				}
			}
			printf("Tri en cours\n");
			tri_a_bulles(&tableau_data, tailleDonnees(listeData), type_tri);
			printf("Tri reussi\n");

			afficherToutData(tableau_data);

			break;
		}
		case 3:
		{
			int temps_recherche;
			printf("Pour quel temps voulez-vous obtenir les donnees?\n");
			scanf("%d", &temps_recherche);

			data *listeData = NULL;
			listeData = chargeData();

			data *tableau_data[1000];
			rechercherPouls(listeData, tableau_data, temps_recherche);

			afficherToutData(tableau_data);

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

			printf("Pouls moyen: %f\n", moyennePouls(listeData, temps_debut, temps_fin));

			break;
		}
		case 5:
		{
			data *listeData = NULL;
			listeData = chargeData();

			data *tableau_data[1000];
			poulsMinMax(listeData, tableau_data);

			printf("Le pouls min est de %d (temps = %d)\n", tableau_data[0]->b, tableau_data[0]->a);
			printf("Le pouls max est de %d (temps = %d)\n", tableau_data[1]->b, tableau_data[1]->a);

			break;
		}
		default:
		{
			printf("Retour au menu principal !\n");
		}
		}
		system("pause");
	}
	return 0;
}

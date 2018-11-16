#define _CRT_SECURE_NO_DEPRECATE

#include "donnees.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ajouterDataListe(data *dataAAjouter, data *dernierDataDeLaListe)
{
	dernierDataDeLaListe->nextData = dataAAjouter;
}

data* creerData(int a, int b)
{
	data *dataCreation;
	dataCreation = malloc(sizeof(data));
	dataCreation->b = b;
	dataCreation->a = a;
	dataCreation->nextData = NULL;
	//printf("Data cree\n");
	return dataCreation;
}

data* chargeData()
{
	FILE *f;
	data *listeData = NULL;
	data *lastData = NULL;
	data *currData = NULL;
	f = fopen("data.csv", "r");

	int checkCloture = 1;
	char line[255];
	int a;
	int b;
	listeData = malloc(sizeof(data));
	currData = listeData;

	if (f == NULL)
	{
		printf("Echec d'ouverture du fichier\n");
	}
	else
	{
		//printf("Succes ouverture du fichier\n");
		memset(line, '\0', 255);
		while (fgets(line, 255, f))
		{
			sscanf(line, "%d;%d\n", &a, &b);
			lastData = creerData(a, b);
			ajouterDataListe(lastData, currData);
			currData = lastData;
			//printf("%d %d\n", currData->a, currData->b);
		}
	}
	checkCloture = fclose(f);
	if (checkCloture == 0)
	{
		//printf("Succes fermeture du fichier\n");
	}
	else
	{
		printf("Echec fermeture du fichier\n");
	}
	return listeData;
}

int tailleDonnees(data *d)
{
	int taille = 0;
	d = d->nextData;
	while (d->nextData != NULL)
	{
		taille++;
		d = d->nextData;
	}
	return taille;
}

void afficherToutData(data *d[])
{
	int i = 0;
	while((int)d[i] > 0) // Tant que le contenu du tableau n'est pas vide a l'index i
	{
		printf("Temps: %d | Pouls: %d\n",
			d[i]->a,
			d[i]->b);
		i++;
	}
	printf("Il y a %d lignes de donnee(s) en memoire\n", i);
}

// Rechercher des pouls a partir d'un temps donne
data *rechercherPouls(data *d, data *t[], int temps)
{
	int i = 0;
	d = d->nextData;
	while (d->nextData != NULL)
	{
		if (d->a == temps) {
			t[i] = d;
			i++;
		}
		d = d->nextData;
	}
	return t;
}

// Calculer le pouls moyen dans un intervalle de temps
float moyennePouls(data *d, int tempsDebut, int tempsFin)
{
	int size_list_temps = 0;
	int totPouls = 0;
	int i = 0;
	data *t[1000];
	d = d->nextData;
	while (d->nextData != NULL)
	{
		if (d->a >= tempsDebut && d->a <= tempsFin)
		{
			t[i] = d;
			i++;
			size_list_temps++;
		}
		d = d->nextData;
	}
	for (int j = 0; j < size_list_temps; j++)
	{
		totPouls += t[j]->b;
	}
	return (float)totPouls / (float)size_list_temps;
}

// Calculer le pouls minimum et le pouls maximum
data *poulsMinMax(data *d, data *t[])
{
	d = d->nextData;
	data *poulsMin = d;
	data *poulsMax = d;
	while (d->nextData != NULL)
	{
		if (poulsMax->b < d->b) {
			poulsMax = d;
		}
		if (poulsMin->b > d->b) {
			poulsMin = d;
		}
		d = d->nextData;
	}
	t[0] = poulsMin;
	t[1] = poulsMax;
	return t;
}
#define _CRT_SECURE_NO_DEPRECATE

#define SIZE_LIST 10

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
		printf("Succes ouverture du fichier\n");
		memset(line, '\0', 255);
		while (fgets(line, 255, f))
		{
			sscanf(line, "%d;%d\n", &a, &b);
			lastData = creerData(a, b);
			ajouterDataListe(lastData, currData);
			currData = lastData;
			//SIZE_LIST++;
			//printf("%d %d\n", currData->a, currData->b);
		}
		/*a = 0;
		b = 0;
		lastData = creerData(a, b);
		ajouterDataListe(lastData, currData);
		currData = lastData;*/
	}
	checkCloture = fclose(f);
	if (checkCloture == 0)
	{
		printf("Succes fermeture du fichier\n");
	}
	else
	{
		printf("Echec fermeture du fichier\n");
	}
	return listeData;
}

void afficherData(data *monData) {
	printf("Temps: %d ;Pouls: %d\n\n",
		monData->a,
		monData->b);
}

/*void afficherToutData(data *listeData)
{
	data *dataAAfficher = listeData->nextData;
	while (dataAAfficher->nextData != NULL)
	{
		afficherData(dataAAfficher);
		dataAAfficher = dataAAfficher->nextData;
	}
	afficherData(dataAAfficher);
}*/

void afficherToutData(data *d[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Temps: %d ;Pouls: %d\n\n",
			d[i]->a,
			d[i]->b);
	}
	printf("Il y a %d lignes de donnee(s) en memoire\n", n);
}
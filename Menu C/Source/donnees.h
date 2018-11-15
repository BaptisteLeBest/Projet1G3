#ifndef DONNEES_H
#define DONNEES_H

typedef struct data data;
struct data {
	int a;
	int b;
	data *nextData;
};

void ajouterDataListe(data *dataAAjouter, data *dernierDataDeLaListe);
data* creerData(int a, int b);
data* chargeData();
void afficherToutData(data *d[]);
data *rechercherPouls(data *d, data *t[], int temps);
float moyennePouls(data *d, int tempsDebut, int tempsFin);
data *poulsMinMax(data *d, data *t[]);

#endif
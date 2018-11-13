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
void afficherData(data *monData);
void afficherToutData(data *d[100], int n);

#endif
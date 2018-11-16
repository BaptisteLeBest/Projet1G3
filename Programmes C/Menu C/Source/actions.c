#include "menu.h"
#include "donnees.h"
#include "actions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Echange deux structures
void swap(data **A, data **B) {
	struct data *temp = *A;
	*A = *B;
	*B = temp;
}

void tri_a_bulles(data *d[], int n, int type_tri)
{
	int tab_en_ordre = 0;
	int taille = n;
	while (tab_en_ordre == 0)
	{
		tab_en_ordre = 1;
		for (int i = 0; i < taille - 1; i++)
		{
			if (type_tri == 0)
			{
				// Tri par temps croissant
				if (d[i]->a > d[i + 1]->a)
				{
					swap(&d[i], &d[i + 1]);
					tab_en_ordre = 0;
				}
			}
			if (type_tri == 1)
			{
				// Tri par temps decroissant
				if (d[i]->a < d[i + 1]->a)
				{
					swap(&d[i], &d[i + 1]);
					tab_en_ordre = 0;
				}
			}
			if (type_tri == 2)
			{
				// Tri par pouls croissant
				if (d[i]->b > d[i + 1]->b)
				{
					swap(&d[i], &d[i + 1]);
					tab_en_ordre = 0;
				}
			}
			if (type_tri == 3)
			{
				// Tri par pouls decroissant
				if (d[i]->b < d[i + 1]->b)
				{
					swap(&d[i], &d[i + 1]);
					tab_en_ordre = 0;
				}
			}

		}
		taille--;
	}
}

data *creerTableau(data *d, data *t[])
{
	int i = 0;
	d = d->nextData;
	while (d->nextData != NULL)
	{
		t[i] = d;
		d = d->nextData;
		i++;
	}
	return t;
}
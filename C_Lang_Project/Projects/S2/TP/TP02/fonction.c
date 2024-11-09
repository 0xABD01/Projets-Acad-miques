#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

liste AjouterAlaFin(liste l, char valeur[])
{
	liste newL = malloc(sizeof(cellule));
	strcpy(newL->valeur, valeur);
	newL->next = NULL;
	if (l == NULL)
		return newL;
	else
	{
		liste l1 = l;
		while (l1->next != NULL)
			l1 = l1->next;
		l1->next = newL;
		return l;
	}
}

void AfficherCellule(liste l)
{
	while (l != NULL)
	{
		printf("[%s]->", l->valeur);
		l = l->next;
	}
	printf("NULL");
}

liste trieOrdreAlpha(liste l)
{
	if (l == NULL || l->next == NULL)
		return l;
	bool estTrier;
	liste l1;
	char tab[30];
	do
	{
		estTrier = true;
		l1 = l;
		while (l1->next != NULL)
		{
			if (strcmp(l1->valeur, l1->next->valeur) > 0)
			{
				strcpy(tab, l1->next->valeur);
				strcpy(l1->next->valeur, l1->valeur);
				strcpy(l1->valeur, tab);
				estTrier = false;
			}
			l1 = l1->next;
		}
	} while (!estTrier);
	return l;
}

liste supprimerValeur(liste l, char valeur[])
{
	if (l != NULL)
	{
		if (strcmp(l->valeur, valeur) == 0)
		{
			liste l1 = l->next;
			free(l);
			return l1;
		}
		liste l1 = l;
		while (strcasecmp(l1->next->valeur, valeur) != 0 && l1->next != NULL)
			l1 = l1->next;
		if (l1->next != NULL)
		{
			liste l2 = l1->next;
			l1->next = l1->next->next;
			free(l2);
			return l;
		}
	}
	return l;
}

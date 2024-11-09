#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

liste AjouterAlaFin(liste Wagon, char class[], int nbrPlaces, char code[])
{
	liste l1 = malloc(sizeof(struct Wagon));
	if (l1 == NULL)
	l1->nbrPlaces = nbrPlaces;
	strcpy(l1->class, class);
	strcpy(l1->code, code);
	l1->next = NULL;
	if (Wagon == NULL)
	{
		l1->prev = NULL;
		return l1;
	}
	liste l2 = Wagon;
	while (l2->next != NULL)
		l2 = l2->next;
	l2->next = l1;
	l1->prev = l2;
	return Wagon;
}

void AfficheListe(liste Wagon)
{
	if (Wagon == NULL)
	{
		printf("NULL\t\tNULL\t\t\tNULL");
		return;
	}
	printf("%s\t\t%d\t\t%s\n", Wagon->class, Wagon->nbrPlaces, Wagon->code);
	AfficheListe(Wagon->next);
}

liste SuppWagon(liste Wagon)
{
	liste l2, l1 = Wagon;
	while (l1 != NULL)
	{
		if (strstr(l1->code, "Q5") != NULL)
		{
			if (l1->prev == NULL)
			{
				Wagon = Wagon->next;
				Wagon->prev = NULL;
				l2 = l1;
				free(l2);
			}
			else
			{
				l1->prev->next = l1->next;
				if (l1->next != NULL)
				{
					l1->next->prev = l1->prev;
				}
				l2 = l1;
				free(l2);
			}
		}

		l1 = l1->next;
	}
	return Wagon;
}
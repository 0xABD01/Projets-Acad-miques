#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

liste AjouterAlaFin(liste Stations, int num, char nom[], int nbrBus)
{
	liste l1 = malloc(sizeof(station));
	l1->num = num;
	strcpy(l1->nom, nom);
	l1->nbrBus = nbrBus;
	l1->next = NULL;
	if (Stations == NULL)
		return l1;
	liste l2 = Stations;
	while (l2->next != NULL)
		l2 = l2->next;
	l2->next = l1;
	return Stations;
}

void AfficheList(liste Stations)
{
	if (Stations == NULL)
	{
		printf("NULL");
		return;
	}
	printf("[%d]||[%s]||[%d]---->", Stations->num, Stations->nom, Stations->nbrBus);
	AfficheList(Stations->next);
}

liste SupprimerLaFin(liste Stations)
{
	if (Stations == NULL || Stations->next == NULL)
		return NULL;
	else
	{
		liste l1 = Stations;
		while (l1->next->next != NULL)
			l1 = l1->next;
		liste l2 = l1->next;
		l1->next = NULL;
		free(l2);
		return Stations;
	}
}
void AfficheListInverse(liste Stations)
{
	if (Stations == NULL)
	{
		return;
	}

	AfficheListInverse(Stations->next);

	printf("[%d]||[%s]||[%d]---->", Stations->num, Stations->nom, Stations->nbrBus);
}

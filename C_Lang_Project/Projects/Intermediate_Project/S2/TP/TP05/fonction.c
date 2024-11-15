#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

liste AjouterAlaFin(liste Stations, int duree, char nom[])
{
	liste l1 = malloc(sizeof(station));
	l1->duree = duree;
	strcpy(l1->nom, nom);
	l1->next = NULL;
	if (Stations == NULL)
	{
		l1->prev = NULL;
		return l1;
	}
	liste l2 = Stations;
	while (l2->next != NULL)
		l2 = l2->next;
	l2->next = l1;
	l1->prev = l2;
	return Stations;


	
}

void AfficheList(liste Stations)
{
	if (Stations == NULL)
	{
		printf("NULL");
		return;
	}
	printf("[%d]||[%s]---->", Stations->duree, Stations->nom);
	AfficheList(Stations->next);
}

liste SupprimerStation(liste Stations, char nom[])
{
	if (Stations != NULL)
	{

		liste l1 = Stations;
		if (strcasecmp(Stations->nom, nom) == 0)
		{
			Stations = Stations->next;
			Stations->prev = NULL;
			free(l1);
			return Stations;
		}
		while (strcmp(l1->nom, nom) != 0 && l1->next != NULL)
			l1 = l1->next;
		if (strcmp(l1->nom, nom) == 0)
		{
			l1->prev->next = l1->next;
			if (l1->next != NULL)
			{
				l1->next->prev = l1->prev;
			}
			free(l1);
		}
		return Stations;
	}
	return Stations;
}

int CalculerNbrdureePair(liste Stations)
{
	if (Stations == NULL)
	{
		return 0;
	}
	if ((Stations->duree) % 2 == 0)
		return (1 + CalculerNbrdureePair(Stations->next));
	else
	    return CalculerNbrdureePair(Stations->next);
}
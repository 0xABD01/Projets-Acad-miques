#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
liste AjoutDebut(liste Employes, char CIN[], char Nom[], float Salaire)
{
	liste l1 = (liste)malloc(sizeof(Employe));
	strcpy(l1->CIN, CIN);
	strcpy(l1->Nom, Nom);
	l1->Salaire = Salaire;
	l1->prev = NULL;
	l1->next = Employes;
	if (Employes == NULL)
	{
		return l1;
	}

	Employes->prev = l1;
	return l1;
}
void AffListe(liste Employes)
{
	if (Employes != NULL)
	{
		printf("%s\t\t%s\t\t%.2f\n", Employes->CIN, Employes->Nom, Employes->Salaire);
		AffListe(Employes->next);
	}
}
liste suppDebut(liste Employes)
{
	liste l1 = Employes;
	Employes = Employes->next;
	Employes->prev = NULL;
	free(l1);
	return Employes;
}

liste suppEmploy(liste Emploiyes)
{
	liste l2, l1 = Emploiyes;
	while (l1 != NULL)
	{
		if (strstr(l1->CIN, "AA") != NULL)
		{
			if (l1->prev == NULL)
			{
				Emploiyes = Emploiyes->next;
				Emploiyes->prev = NULL;
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
	return Emploiyes;
}

liste inverserEmployes(liste Employes)
{
	liste l1 = NULL;
	while (Employes != NULL)
	{
		l1 = AjoutDebut(l1, Employes->CIN, Employes->Nom, Employes->Salaire);
		Employes = Employes->next;
	}
	return l1;
}

liste trieSalaire(liste Employes)
{
	liste l1;
	char CINX[20];
	char NomX[20];
	float SalaireX;
	bool estTrier;
	do
	{
		l1 = Employes;
		estTrier = true;
		while (l1->next != NULL)
		{
			if (l1->next->Salaire < l1->Salaire)
			{
				strcpy(CINX, l1->CIN);
				strcpy(NomX, l1->Nom);
				SalaireX = l1->Salaire;
				strcpy(l1->CIN, l1->next->CIN);
				strcpy(l1->Nom, l1->next->Nom);
				l1->Salaire = l1->next->Salaire;
				strcpy(l1->next->CIN, CINX);
				strcpy(l1->next->Nom, NomX);
				l1->next->Salaire = SalaireX;
				estTrier = false;
			}
			l1 = l1->next;
		}
	} while (!estTrier);

	return Employes;
}

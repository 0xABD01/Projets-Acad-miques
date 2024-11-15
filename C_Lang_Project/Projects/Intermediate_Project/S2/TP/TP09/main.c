#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	pile p = NULL;
	int choix;
	do
	{
		printf("\nMenu :\n");
		printf("1. Empiler\n");
		printf("2. Afficher la pile\n");
		printf("3. Dépiler\n");
		printf("33. RecupSommet\n");
		printf("4. Renverser la pile\n");
		printf("5. Vider la pile\n");
		printf("6. Quitter\n");
		printf("7.supp milieu\n");

		printf("Entrez votre choix : ");
		scanf("%d", &choix);
		printf("\033[2J\033[1;1H");

		switch (choix)
		{
		case 1:
			int valeur;
			printf("Entrez la valeur à empiler : ");
			scanf("%d", &valeur);
			p = empiler(p, valeur);
			break;
		case 2:
			printf("Contenu de la pile :\n");
			affPile(p);
			break;
		case 3:
			p = depiler(p);
			printf("Element dépilé.\n");
			break;
		case 33:
			if (p == NULL)
				printf("la pile est vide.\n");
			else
			{
				int valeurs;
				valeurs = recupSommet2(&p);
				printf("le sommet est  :%d ", valeurs);
			}
			break;
		case 4:
			p = renverserPile(p);
			printf("La pile a été renversée.\n");
			break;
		case 5:
			p = ViderPile(p);
			printf("La pile a été vidée.\n");
			break;

		case 6:
			printf("Fin du programme.\n");
			break;
		case 7:
            p = supMilieu(p);
			break;
		default:
			printf("Choix invalide.\n");
		}
	} while (choix != 6);
}
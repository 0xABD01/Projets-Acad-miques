#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

pile empiler(pile p, int valeur)
{
	pile p1 = malloc(sizeof(Cellule));
	p1->value = valeur;
	p1->prev = p;
	// automatiqument il prent la valeur null si la pile est vide
	return p1;
}

pile depiler(pile p)
{
	if (p == NULL)
	{
		return NULL;
	}
	pile p1 = p;
	p = p->prev;
	free(p1);
	return p;
}

int recupSommet2(pile *p)
{
	if (*p == NULL)
	{
		return -1;
	}
	int val = (*p)->value;
	pile p1 = *p;
	(*p) = (*p)->prev;
	free(p1);
	return val;
}

pile renverserPile(pile p)
{
	pile p1 = NULL;
	while (p != NULL)
		p1 = empiler(p1, recupSommet2(&p));
	return p1;
}

int Nbr4(pile p)
{
	if (p == NULL)
		return 0;
	else if (p->value > 4)
		return 1 + Nbr4(p->prev);
	else
		return Nbr4(p->prev);
}

int longeurPile(pile p)
{
	int lng = 0;
	while (p != NULL)
	{
		lng++;
		p = p->prev;
	}
	return lng;
}

pile permuter2DvalPile(pile p)
{
	if (p == NULL || p->prev == NULL)
		return p;
	int val1, val2;
	val1 = recupSommet2(&p);
	val2 = recupSommet2(&p);
	p = empiler(p, val1);
	p = empiler(p, val2);
	return p;
}

pile permuterDebutEtFin(pile p)
{
	if (p == NULL || p->prev == NULL)
		return p;
	int val1, val2;
	val1 = recupSommet2(&p);
	p = renverserPile(p);
	val2 = recupSommet2(&p);
	p = empiler(p, val1);
	p = renverserPile(p);
	p = empiler(p, val2);
	return p;
}

pile renverseCerculaire(pile p, int n)
{
	if (p == NULL || p->prev == NULL)
		return p;
	else
	{
		int r = n % longeurPile(p);
		if (r == 0)
			return p;
		else
		{
			pile p1 = NULL, p2 = NULL;
			while (r != 0)
			{
				p1 = empiler(p1, recupSommet2(&p));
				r--;
			}
			p=renverserPile(p);
			while (p1 != NULL)
				p2 = empiler(p2, recupSommet2(&p1));
			while (p != NULL)
				p2 = empiler(p2, recupSommet2(&p));
			return p2;
		}
	}
}
//
void affPile(pile p)
{
	while (p != NULL)
	{
		printf("{%d}\n", p->value);
		p = p->prev;
	}
	printf("NULL");
}

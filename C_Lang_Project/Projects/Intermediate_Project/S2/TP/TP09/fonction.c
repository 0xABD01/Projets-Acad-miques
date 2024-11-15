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

void affPile(pile p)
{
	while (p != NULL)
	{
		printf("{%d}\n", p->value);
		p = p->prev;
	}
	printf("NULL");
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

pile ViderPile(pile p)
{
	while (p != NULL)
		p = depiler(p);
	return p;
}

pile supMilieu(pile p)
{
	pile p2,p1 = p->prev;
	while (p1->prev != NULL)
	{
			p2 = p1;
			p1=p1->prev;
			p->prev = p1;
			free(p2);
	}
	return p;
}

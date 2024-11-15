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
		printf("{%c}\n", p->value);
		p = p->prev;
	}
	printf("NULL\n");
}

char recupSommet2(pile *p)
{
	if (*p == NULL)
	{
		return '*';
	}
	char val = (*p)->value;
	pile p1 = *p;
	(*p) = (*p)->prev;
	free(p1);
	return val;
}

pile Miroir(pile p)
{
	pile p1 = NULL;
	while (p != NULL)
	{
		p1 = empiler(p1, p->value);
		p = p->prev;
	}
	return p1;
}

bool estPalindrome(pile p)
{
	pile p1 = NULL;
	p1 = Miroir(p);
	// printf("P1:\n");
	// affPile(p1);
	while (p != NULL)
	{
		if (p->value == p1->value || p->value + 32 == p1->value || p->value - 32 == p1->value)
		{
			p = p->prev;
			p1 = p1->prev;
		}
		else
			return false;
	}
	return true;
}

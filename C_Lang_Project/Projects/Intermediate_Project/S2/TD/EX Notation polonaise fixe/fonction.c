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

int transferEntier(char c)
{
	return c - '0';
}

int estOperation(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

int calculer(char op, int valeur1, int valeur2)
{
	int s;
	if (op == '+')
		s = valeur1 + valeur2;
	else if (op == '-')
		s = valeur1 - valeur2;
	else if (op == '*')
		s = valeur1 * valeur2;
	else if (op == '/')
		s = valeur1 / valeur2;
	return s;
}

pile Expresion(char expresion[])
{
	pile p = NULL;
	int i = 0;
	int a, b, c, resultat = 0;
	while (expresion[i] != '\0')
	{
		if (!estOperation(expresion[i]) && expresion[i] != ' ')
		{
			resultat = 0;
			while (!estOperation(expresion[i]) && expresion[i] != ' ')
			{

				a = transferEntier(expresion[i]);
				resultat = ((resultat * 10) + a);
				i++;
			}
			p = empiler(p, resultat);
		}
		else
		{
			if (estOperation(expresion[i]) && expresion[i] != ' ')
			{
				a = depiler(&p);
				b = depiler(&p);
				c = calculer(expresion[i], a, b);
				p = empiler(p, c);
			}
		}
		i++;
	}
	return p;
}

void affPile(pile p)
{
	while (p != NULL)
	{
		printf("{%d}\n", p->value);
		p = p->prev;
	}
}

#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	pile p = NULL;
	p = empiler(p, 1);
	p = empiler(p, 2);
	p = empiler(p, 3);
	p = empiler(p, 4);
	p = empiler(p, 5);
	p = empiler(p, 6);

	int n=6;

	p = renverseCerculaire(p,n);
	affPile(p);
}
#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	pile p = NULL;
	char expresion[20];
	printf("entrer l'expresion :");
	gets(expresion);
	p = Expresion(expresion);
	affPile(p);
}
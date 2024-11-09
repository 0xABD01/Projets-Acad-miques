#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	pile p = NULL;
	p = empiler(p, 'A');
	p = empiler(p, 'l');
	p = empiler(p, 'L');
	p = empiler(p, 'a');
	printf("P:\n");
	affPile(p);

	if (estPalindrome(p))
		printf("la mot est palindrome");
	else
		printf("la mot est NON palindrome");
}
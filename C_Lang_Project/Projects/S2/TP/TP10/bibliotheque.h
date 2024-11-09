#include <stdbool.h>
typedef struct Cellule
{
	char value;
	struct Cellule *prev;
} Cellule, *pile;

pile empiler(pile p, int valeur);
void affPile(pile p);
char recupSommet2(pile *p);
pile Miroir(pile p);
bool estPalindrome(pile p);



//

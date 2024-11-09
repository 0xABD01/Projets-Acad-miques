
typedef struct Cellule
{
	int value;
	struct Cellule *prev;
} Cellule, *pile;

pile empiler(pile p, int valeur);
void affPile(pile p);
pile depiler(pile p);
int recupSommet2(pile *p);
pile renverserPile(pile p);
int longeurPile(pile p);
pile ViderPile(pile p);

pile supMilieu(pile p);

//

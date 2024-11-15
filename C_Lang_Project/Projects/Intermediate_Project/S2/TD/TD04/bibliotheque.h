
typedef struct Cellule
{
	int value;
	struct Cellule *prev;
} Cellule, *pile;

pile empiler(pile p, int valeur);
pile depiler(pile p);
int recupSommet2(pile *p);
pile renverserPile(pile p);
int Nbr4(pile p);
int longeurPile(pile p);
pile permuter2DvalPile(pile p);
pile permuterDebutEtFin(pile p);
pile renverseCerculaire(pile p, int n);

//
void affPile(pile p);

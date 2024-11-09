
typedef struct Cellule
{
	int value;
	struct Cellule *prev;
} Cellule, *pile;

pile empiler(pile p, int valeur);
pile depiler(pile p);

int transferEntier(char c);
int estOperation(char c);

int calculer(char op, int valeur1,int valeur2);
pile Expresion(char expresion[]);

//
void affPile(pile p);

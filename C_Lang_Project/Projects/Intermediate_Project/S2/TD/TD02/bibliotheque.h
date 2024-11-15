
typedef struct Wagon{
	char code[20];
	char class[20];
	int nbrPlaces;
	struct Wagon *next;
	struct Wagon *prev;	
}Wagon,*liste;


liste AjouterAlaFin(liste Wagon,char class[],int nbrPlaces,char code[]);
void AfficheListe(liste Wagon);
liste SuppWagon(liste Wagon);




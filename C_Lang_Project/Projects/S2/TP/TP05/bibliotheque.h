
typedef struct station{
	int duree;
	char nom[50];
	struct station *next;
	struct station *prev;
}station,*liste;


liste AjouterAlaFin(liste Stations,int duree,char nom[]);
void AfficheList(liste Stations);
liste SupprimerStation(liste Stations,char nom[]);
int CalculerNbrdureePair(liste Stations);




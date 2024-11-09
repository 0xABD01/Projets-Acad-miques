
typedef struct station{
	int num;
	char nom[50];
	int nbrBus;
	struct station *next;
}station,*liste;


liste AjouterAlaFin(liste Stations,int num,char nom[],int nbrBus);
void AfficheList(liste Stations);
liste SupprimerLaFin(liste Stations);
void AfficheListInverse(liste Stations);





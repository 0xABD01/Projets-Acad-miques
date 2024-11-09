
typedef struct Station
{
	int num;
	char Nom[20];
	int nbrBus;
	struct Station *next;
} Station, *liste;

liste AjoutDebut(liste Stations, int num, char Nom[], int nbrBus);
void AffListe(liste Stations);
liste SuppTete(liste Stations);
liste SuppStationInf3(liste Stations);


typedef struct Employe
{
	char CIN[20];
	char Nom[20];
	float Salaire;
	struct Employe *next, *prev;
} Employe, *liste;

liste AjoutDebut(liste Employes, char CIN[], char Nom[], float Salaire);
void AffListe(liste Employes);
liste suppDebut(liste Employes);
liste suppEmploy(liste Employes);
liste inverserEmployes(liste Employes);
liste trieSalaire(liste Employes);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Employe {
	char CIN[20];
	char Nom[20];
	float Salaire;
	struct Employe *next, *prev;
} Employe, *liste;

liste AjoutDebut(liste Employes, char CIN[], char Nom[], float Salaire);
void AffListe(liste Employes);
liste suppDebut(liste Employes);
liste suppEmploy(liste Emploiyes);



int main() {
	liste Employes=NULL;

	Employes= AjoutDebut(Employes,"JAA9873","brahim",9888.21);
	Employes= AjoutDebut(Employes,"JZ71635","Hamza",8716.21);
	Employes= AjoutDebut(Employes,"LZAA28263","omar",7727.21);
	Employes= AjoutDebut(Employes,"L01723","othmane",19287.21);
	Employes= AjoutDebut(Employes,"AF155AA2535","anouar",10299.21);

	AffListe(Employes);
	printf("----------------------------------------------------------------\n");
	Employes=suppEmploy(Employes);
	AffListe(Employes);

}


liste AjoutDebut(liste Employes, char CIN[], char Nom[], float Salaire) {
	liste l1 =(liste)malloc(sizeof(Employe));
	strcpy(l1->CIN, CIN);
	strcpy(l1->Nom, Nom);
	l1->Salaire = Salaire;
	l1->prev = NULL;
	l1->next = Employes;
	if (Employes == NULL) {
		return l1;
	}

	Employes->prev = l1;
	return l1;
}
void AffListe(liste Employes) {
	if(Employes != NULL) {
		printf("%s\t\t%s\t\t%f\n",Employes->CIN,Employes->Nom,Employes->Salaire);
		AffListe(Employes->next);
	}
}
liste suppDebut(liste Employes) {
	liste l1=Employes;
	Employes=Employes->next;
	Employes->prev=NULL;
	free(l1);
	return Employes;
}

liste suppEmploy(liste Emploiyes)
{
	liste l2, l1 = Emploiyes;
	while (l1 != NULL)
	{
		if (strstr(l1->CIN, "AA") != NULL)
		{
			if (l1->prev == NULL)
			{
				Emploiyes = Emploiyes->next;
				Emploiyes->prev = NULL;
				l2 = l1;
				free(l2);
			}
			else
			{
				l1->prev->next = l1->next;
				if (l1->next != NULL)
				{
					l1->next->prev = l1->prev;
				}
				l2 = l1;
				free(l2);
			}
		}

		l1 = l1->next;
	}
	return Emploiyes;
}

#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	liste Employes = NULL;

	Employes = AjoutDebut(Employes, "JAA9873", "brahim", 9888.21);
	Employes = AjoutDebut(Employes, "JA1837", "simo", 7253.83);
	Employes = AjoutDebut(Employes, "JZ71635", "Hamza", 8716.21);
	Employes = AjoutDebut(Employes, "LZAA28263", "omar", 7727.10);
	Employes = AjoutDebut(Employes, "L01723", "othmane", 1287.34);
	Employes = AjoutDebut(Employes, "AF155A2535", "anouar", 10299.17);

	AffListe(Employes);

	printf("-------------------------supprime le premier employé de la liste\n");
	Employes = suppDebut(Employes);
	AffListe(Employes);

	printf("------supprime les employés avec un numéro de CIN contenant le mot « AA»\n");
	Employes = suppEmploy(Employes);
	AffListe(Employes);

	printf("-----------inverse la liste en utilisant la fonction AjoutDebut .\n");
	Employes = inverserEmployes(Employes);
	AffListe(Employes);

	printf("-------------trier les employés par ordre décroissant du salaire.\n");
	Employes = trieSalaire(Employes);
	AffListe(Employes);
}
#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	liste mots = NULL;
	mots = AjouterAlaFin(mots, "Fin");
	mots = AjouterAlaFin(mots, "BlaBla a la");
	mots = AjouterAlaFin(mots, "ZA");
	mots = AjouterAlaFin(mots, "Ajouter");
	mots = AjouterAlaFin(mots, "Fin");
	mots = AjouterAlaFin(mots, "Fin");
	mots = AjouterAlaFin(mots, "BlaBla a la");
	mots = AjouterAlaFin(mots, "ZA");
	mots = AjouterAlaFin(mots, "Ajouter");
	mots = AjouterAlaFin(mots, "Fin");

	printf("\n--------------------------------\n");
	AfficherCellule(mots);
	printf("\n--------------------------------\n");
	mots = trieOrdreAlpha(mots);
	AfficherCellule(mots);
	printf("\n--------------------------------\n");
	mots = supprimerValeur(mots, "ZA");

	AfficherCellule(mots);
}
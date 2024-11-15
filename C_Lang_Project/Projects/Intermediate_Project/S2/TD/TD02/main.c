#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	liste Wagons = NULL;
	Wagons = AjouterAlaFin(Wagons, "A5AJ", 86, "premiere");

	Wagons = AjouterAlaFin(Wagons, "172Z", 82, "dexieme");
	Wagons = AjouterAlaFin(Wagons, "PZJD762", 122, "premiere");
	Wagons = AjouterAlaFin(Wagons, "LE683", 65, "dexieme");
	Wagons = AjouterAlaFin(Wagons, "JJD65", 92, "dexieme");

	AfficheListe(Wagons);

	printf("\nApree supprimer-------------------------------------------------------\n");
	Wagons = SuppWagon(Wagons);
	AfficheListe(Wagons);
}
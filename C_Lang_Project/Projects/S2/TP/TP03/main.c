#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	liste Stations = NULL;

	Stations = AjouterAlaFin(Stations, 8272, "dior jammaa", 727);
	Stations = AjouterAlaFin(Stations, 7273, "AGDAL", 6262);
	Stations = AjouterAlaFin(Stations, 1828, "hay fath", 52);

	AfficheList(Stations);

	printf("\n================================\n");
	Stations = SupprimerLaFin(Stations);

	AfficheList(Stations);
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	AfficheListInverse(Stations);
	
}
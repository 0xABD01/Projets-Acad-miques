#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	liste Stations = NULL;

	Stations = AjouterAlaFin(Stations, 1, "dior jammaa");
	Stations = AjouterAlaFin(Stations, 2, "AGDAL");
	Stations = AjouterAlaFin(Stations, 4, "hay fa");
	Stations = AjouterAlaFin(Stations, 5, "hay fath");
	Stations = AjouterAlaFin(Stations, 2, "AGDAL");

	AfficheList(Stations);

	printf("\n================================\n");
	Stations = SupprimerStation(Stations, "hay fath");

	AfficheList(Stations);

	printf("\n================================\n");
	int nbr = CalculerNbrdureePair(Stations);
	printf("Le NBR des stations ayant une duree divisible par 2 est %d\n", nbr);
}
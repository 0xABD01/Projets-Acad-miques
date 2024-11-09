#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	liste Stations=NULL;

	Stations= AjoutDebut(Stations,1,"hay riyad",7);
	Stations= AjoutDebut(Stations,2,"Agdal",2);
	Stations= AjoutDebut(Stations,3,"avenue france",5);
	Stations= AjoutDebut(Stations,4,"suissi",1);
	Stations= AjoutDebut(Stations,5,"joulane",9);

	AffListe(Stations);


	printf("-------------------------supprime le premier Station de la liste\n");
    Stations = SuppTete(Stations);
    AffListe(Stations);


	

	printf("------supprime les employés avec un numéro de nbrBus <= 3 \n");
	Stations =SuppStationInf3(Stations);
    AffListe(Stations);

	

	
}
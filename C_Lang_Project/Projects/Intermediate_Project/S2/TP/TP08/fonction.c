#include "bibliotheque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
liste AjoutDebut(liste Stations, int num, char Nom[], int nbrBus){
	liste newStation=malloc(sizeof(Station));
	newStation->nbrBus = nbrBus;
	newStation->num= num;
	strcpy(newStation->Nom,Nom);
	if(Stations==NULL){
		newStation->next = newStation;
		return newStation;
	}
    newStation->next = Stations;
	liste l= Stations;
	while(l->next!=Stations)
		l=l->next;
	l->next = newStation;
	return newStation;
}
void AffListe(liste Stations){
	liste l= Stations;
	do{
		printf("[%d]\t[%s]\t[%d]\n",l->num,l->Nom,l->nbrBus);
		l=l->next;
	}while(l!=Stations);
}
liste SuppTete(liste Stations){
	if(Stations==NULL){
		return Stations;
	}
	liste l1 =Stations;
	liste l2=Stations->next;
	while(l1->next!=Stations){
		l1=l1->next;
	}
	l1->next=l2;
	free(Stations);
	return l2;	
}

liste SuppStationInf3(liste Stations){
	if(Stations==NULL){
		return Stations;
	}
	liste l1= Stations,l2;
	while(l1->next != Stations){
		if(Stations->nbrBus<=3){
			Stations=SuppTete(Stations);
		}
		else if(l1->next->nbrBus<=3){
				l2=l1->next;
				l1->next=l2->next;
				free(l2);
			l1=l1->next;
		}
		l1=l1->next;
	}

	return Stations;
}




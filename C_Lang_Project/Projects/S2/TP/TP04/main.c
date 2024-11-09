#include"bibliotheque.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	liste lContacts=NULL;

	lContacts=AjouterAlaFin(lContacts,"marwan","0675176252");
	lContacts=AjouterAlaFin(lContacts,"ayoub","0674667888");
	lContacts=AjouterAlaFin(lContacts,"sasa","2455666666");
	lContacts=AjouterAlaFin(lContacts,"ksks","2455666666");
	lContacts=AjouterAlaFin(lContacts,"zaza","0674667888");
	lContacts=AjouterAlaFin(lContacts,"ksks","2455666666");

	printf("\n================================\n");

	AfficherListe(lContacts);

	printf("\n================================\n");

	lContacts=suppElement(lContacts,"ksks");

	AfficherListe(lContacts);

	printf("\n================================\n");

	int compteur = 0;
	compteur = calculateContactchi(lContacts,compteur);

	printf("le nombre des elememment qui contien le chifre '5'est :%d ",compteur);

	printf("\n================================\n");

	lContacts = triListe(lContacts);

	AfficherListe(lContacts);

}
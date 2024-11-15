#include"bibliotheque.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

liste AjouterAlaFin(liste contact, char name[],char phone[]) {
	liste newContact =(liste)malloc(sizeof(Contact));
	strcpy(newContact->name,name);
	strcpy(newContact->phone,phone);
	newContact->next = NULL;
	if(contact==NULL) {
		return newContact;
	} else {
		liste contactX=contact;
		while(contactX->next !=NULL)
		    contactX=contactX->next;
	
		contactX->next=newContact;
		return contact;
	}
}

void AfficherListe(liste contact) {
	if(contact==NULL){
		printf("NULL.\n");
        return;
    }
	printf("[%s][%s]-->",contact->name,contact->phone);
	AfficherListe(contact->next);
}

liste suppElement(liste contact,char name[30]){
	if(strcmp(contact->name,name)==0){
        liste contactASupp=contact;
        contact=contact->next;
        free(contactASupp);
        return contact;
    }
    else{
        liste contactX=contact;
        while(strcmp(contactX->next->name,name)!=0 && contact->next!=NULL){
            contactX=contactX->next;
        }
        if(strcmp(contactX->next->name,name)==0){
            liste contactASupp=contactX->next;
            contactX->next=contactASupp->next;
            free(contactASupp);

        }
        return contact;
    }
}

int calculateContactchi(liste contact,int compteur){
    if(contact== NULL)
        return compteur;
    if(strchr(contact->phone,'5')){
        compteur++;
    }
    calculateContactchi(contact->next, compteur);
}

liste triListe(liste contact) {
	if (contact == NULL || contact->next == NULL) {
		return contact;
	}

	liste i, y;
	bool estTrier;
	char Nom[30];
	char Telephone[20];
	do {
		estTrier = true;
		i = contact;
		while (i->next != NULL) {
			y = i->next;
			if (strcmp(i->name, y->name) == 1) {
				strcpy(Nom, i->name);
				strcpy(Telephone, i->phone);
				strcpy(i->name, y->name);
				strcpy(i->phone, y->phone);
				strcpy(y->name, Nom);
				strcpy(y->phone, Telephone);
				estTrier = false;
			}
			i = i->next;
		}
	} while (estTrier);

	return contact;
}



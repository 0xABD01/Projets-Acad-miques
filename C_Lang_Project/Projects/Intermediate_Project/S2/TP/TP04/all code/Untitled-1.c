#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Contact {
    char name[30];
    char phone[30];
    struct Contact *next;
}Contact,*liste;

liste AjouterAlaFin(liste contact, char name[],char phone[]);
void AfficherListe(liste contact);

int main(){
    liste lContacts=NULL;
    printf("\n================================\n");

    lContacts=AjouterAlaFin(lContacts,"marwan","0675176252");
    lContacts=AjouterAlaFin(lContacts,"ayoub","0674667888");

    printf("\n================================\n");
    printf("\n================================\n");

    AfficherListe(lContacts);
    printf("\n================================\n");
    AfficherListe(lContacts);
        printf("\n================================\n");
    printf("\n================================\n");

  
}


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
	if(contact==NULL)
		printf("NULL.\n");
	printf("[%s][%s]-->",contact->name,contact->phone);
	AfficherListe(contact->next);
}

liste suppElement(liste contact,char name[]){
	if(contact==NULL){
		
	}
}
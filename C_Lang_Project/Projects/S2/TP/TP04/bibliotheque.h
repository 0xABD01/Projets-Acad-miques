
typedef struct Contact {
    char name[30];
    char phone[30];
    struct Contact *next;
}Contact,*liste;

liste AjouterAlaFin(liste contact, char name[],char phone[]);
void AfficherListe(liste contact);
liste suppElement(liste contact,char name[30]);
int calculateContactchi(liste contact,int compteur);
liste triListe(liste contact);




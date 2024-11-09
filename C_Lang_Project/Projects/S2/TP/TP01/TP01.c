#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct{
    char nom[20];
    char prenom[20];
    char nInscription[20];
    char ville[20];

    
}Etudiant;

void sasirEtudiant(Etudiant *E){

    printf("sasir les information de l'etudiant :\n");
    printf("nom : ");
    scanf("%s",E->nom);
    printf("prenom : ");
    scanf("%s",E->prenom);
    printf("nInscription : ");
    scanf("%s",E->nInscription);
    printf("ville : ");
    scanf("%s",E->ville);
}

Etudiant *TabEtudiant(int n){
    Etudiant *tab = (Etudiant *)malloc(n*sizeof(Etudiant));
    for(int i=0; i<n; i++){
       sasirEtudiant(&tab[i]);
    }
    return tab;
}
void afficheEtudiant(Etudiant *tab,int n,char ville[]){
    bool exists = false;
    for(int i=0; i<n; i++){
        if(strcmp(ville,tab[i].ville)==0){
            exists = true;
            printf("L'etudiant %s %s avec le nIscription %s apartient a la ville %s",tab[i].nom,tab[i].prenom,tab[i].nInscription,tab[i].ville);
        }
    }
    if(exists==false)
        printf("Aucun etudiant existe dans cette ville");
}

int rechercheEtudiant(Etudiant *tab,int n,char nom[]){  
    for(int i=0; i<n; i++){
        if(strcmp(nom,tab[i].nom)==0)
            return 1;
    }
    return 0;
}

int main(){
    int N;
    printf("saisir le nombre des etudiant :");
    scanf("%d",&N);
    Etudiant *tab;
    tab =TabEtudiant(N);

    char ville[20];
    printf("saisir une ville :");
    gets(ville);
    afficheEtudiant(tab,N,ville);
    
    char nom[20];
    printf("saisir un nom :");
    gets(nom);
    if(rechercheEtudiant(tab,N,nom))
       printf("il existe un etudiant avec ce nom ");
    else 
       printf("aucun etudiant avec ce nom ");
}
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int numFacture;
    char nomClient[20];
    float prixHrsTaxe;
    int aneeLimitPayment;
}facture;

facture *Factures(int nmbFacture);
void TabToFile(FILE *f,int nmbFacture);
void AfficheFac(FILE *f,int nmbFacture);
int rechercheFac(FILE *f,char *nomClien,int *pos);
facture *TriFactures(FILE *f,int nmbFacture);
facture *MajPrix(FILE *f,int nmbFacture);

int main(){
    
    ////////////////////////////////////////////////////////////////
    return 0;
}

facture *Factures(int nmbFacture){
    facture *tabFacture = malloc(nmbFacture*sizeof(facture));
    for(int i=0;i<nmbFacture;i++){
        printf("CLien %d .................................\nSaisir :\n",i);
        printf("Le num de facture :");
        scanf("%d",&tabFacture[i].numFacture);
        printf("Le nom du Clien :");
        gets(tabFacture[i].nomClien);
        printf("Le prix de facture HT :");
        scanf("%f",&tabFacture[i].numFacture);
        printf("L annee limite de payment :");
        scanf("%d",&tabFacture[i].anneeLimitPayment);
    }
    return tabFacture;
}
void TabToFile(FILE *f,int nmbFacture){
    for(int i=0;i<nmbFacture;i++){
        printf("CLien %d .................................\n",i);
        fwrite(tabFacture,sizeof(faacture),N,f);
        
    }
}





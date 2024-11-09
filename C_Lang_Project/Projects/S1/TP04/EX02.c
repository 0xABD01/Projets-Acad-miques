#include<stdio.h>
 
 void remplisage(int tab[],int tailleTab){
    printf("saisir les entier du tableau \n");
    for(int *i=tab;i<tab+tailleTab;i++){
        printf("Tab[%d] :",i-tab);
        scanf("%d",i);
    }
 }
void affichage(int tab[],int tailleTab){
    printf("les valeur du tableau sont :\n");
    for(int *i=tab;i<tab+tailleTab;i++){
      printf(" :%d\n",*i);
    }
}
void tri(int *tab[],int tailleTab){
int temp;
for(int i=0;i<tailleTab;i++){
}
void trie(int *tab[],int taillTab){
    int *temp;
    for(int *i=tab;i<tab+taillTab;i++){
        int indiceOfMin=0; 
        for(int *j=tab;j<tab+tab+taillTab;j++){
            if(*)
        }
    }   
}

 main(){
    int tab1[50],tailleTab;
    do{
        printf("saisir la taille effectuve du tableau ");
        scanf("%d",&tailleTab);
    }while(tailleTab<1||tailleTab>50);
    remplisage(tab1,tailleTab);
    affichage(tab1,tailleTab);

 }
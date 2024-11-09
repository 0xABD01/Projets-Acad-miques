#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void remplisageAutomatique(int matrice[][]);
void remplisageManuel(int matrice[][]);
void remplisage(int matrice[][]);

int main(){
    int matrice[3][3];
    printF("welcome in this program\n");
    remplisage(matrice);


}
void remplisage(int matrice[][]){
    int choice;
    printf("saisir votre choix :\n");
    printf("1-pour le remplisage automatique :\n");
    printf("2-pour le remplisage automatique :\n==> ");
    scanf("%d",&choice);
    if(choice==1)
       remplisageManuel(matrice);
    else if(choice==2)
       remplisageAutomatique(matrice);
    else
       printf("error de choix :\n");
}
void remplisageManuel(int matrice[][]){
    for(int i=0 ;i<3;i++){
        for(int j=0;j<3;j++){
            printf("matrice[%d][%d] :",i,j);
            scanf("%d",&matrice[i][j]);
        }
    }
}
void remplisageAutomatique(int matrice[][]){
    srand(time(NULL));
    int i,j;
    for(i=0 ;i<3;i++){
        for(j=0;j<3;j++){
            matrice[i][j]=rand()%10;
        }
    }
}


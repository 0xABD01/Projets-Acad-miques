#include<stdio.h>
#include<stdbool.h>

void remplisage(int tab[], int N);
void afichage(int tab[], int N);
void permutation(int *num1, int *num2);
void trie(int tab[], int N);

int main(){
    int tab[50],N;
    do{
        printf("saisir la taille eff du tableau :");
        scanf("%d", &N);
    }while(N<0||N>50);
    printf("vaillez saisir les valeur du tableau :\n");
    remplisage(tab, N);
    printf("voilla les valeur saisir :\n");
    afichage(tab, N);
    printf("apree le tri par ordre croissant :\n");
    trie(tab, N);
    afichage(tab, N); 
    return 0;
}
void remplisage(int tab[], int N){
    for(int *P=tab; P<tab+N; P++){
        printf("T[%d] : ",P-tab);
        scanf("%d",P);
    }
}
void afichage(int tab[], int N){
    for (int *P=tab; P<tab+N; P++){
        printf("T[%d] : %d elle est stoke dans l'adresse : %d\n",P-tab,*P,P);
    }
}
void permutation(int *num1, int *num2){
    int num3 = *num1;
    *num1 = *num2;
    *num2 = num3; 
}
void trie(int tab[], int N){
    bool trie = false;
    while(trie==false){
        trie = true;
        for (int *P=tab; P<tab+N-1; P++){
            if(*P>*(P+1)){
                trie = false;
                permutation(P,P+1);
            } 
        }
    }
}




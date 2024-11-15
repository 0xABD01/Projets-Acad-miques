#include<stdio.h>
#include<string.h>

int compteurOccurence(char ch[],char caracter);

int main(){
    char ch1[100],caracter;
    printf("saisir une chaine de caractere  : ");
    gets(ch1);
    printf("saisir le caractere a recherche : ");
    scanf("%c",&caracter);
    printf("le nombre d ocurence de %c dans la chaine %s:\n=>%d: ",caracter, ch1,compteurOccurence(ch1,caracter));
}

int compteurOccurence(char ch[],char caracter){
    char *P;
    int nombreOccurence=0;
    for(P = ch;*P !='\0';P++){
        if(*P == caracter){
            nombreOccurence ++;
        }
    }
    return nombreOccurence;
}

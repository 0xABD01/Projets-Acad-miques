#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

bool exist(FILE *file,char motRecherche[]);
int compteurMots(FILE *file,char motRecherche[]);
void convertionMajuscule(FILE *sorce,FILE *destination);

int main(){
    FILE *file = fopen("fileEX1.txt", "r");
    FILE *destination = fopen("fileDestination.txt", "w");
    char motRecherche[20];
    printf("saisir le mot recherche : ");
    gets(motRecherche);
    if(exist(file, motRecherche))
        printf("Le mot %s existe dans le fichier ",motRecherche);
    else 
        printf("Le mot %s n'existe pas dans le fichier ",motRecherche);
    printf("\nLe mot %s existe %d fois dans le fichier",motRecherche,compteurMots(file,motRecherche));
    rewind(file);
    convertionMajuscule(file,destination);
    fclose(file);
    fclose(destination);

}
bool exist(FILE *file,char motRecherche[]){
    char mot[20];
    while(fscanf(file, "%s",&mot) != EOF){
        if(strcmp(mot, motRecherche)==0)
            return true;
    }
    return false;
}
int compteurMots(FILE *file,char motRecherche[]){
    int compteurMots=0;
    char mot[20];
    while(fscanf(file, "%s",&mot) != EOF){
        if(strcmp(mot, motRecherche)==0)
           compteurMots++;
    }
    return compteurMots;
}
void convertionMajuscule(FILE *sorce,FILE *destination){
    int caractere;
    while((caractere=fgetc(sorce))!=EOF){
        caractere=toupper(caractere);
        fputc(caractere,destination);
    }
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int main() {
	char nomFile[20];
	printf("saisir le nom du fichier a ouvrir : ");
	gets(nomFile);

	FILE *f = fopen(nomFile, "r");
	if(f == NULL) {
		printf("Error le fichier %s n'existe pas  \n",nomFile);
		exit(1);
	}
	FILE *destination = fopen("destination.txt","w");
    char wordFile[20],word[20];
    bool existe = false;
    printf("saisir le mot a suprimer : "); 
    scanf("%s",word);
    while(fscanf(f,"%s",&wordFile) != EOF) {
        if(strcmp(word,wordFile) != 0) {
            fprintf(destination,"%s ",wordFile);
        }
        else
            existe = true;
    }
    if(existe)
       printf("le mots %s a ete suprimer avec suxee");
    else 
       printf("le mots %s n'existe pas dans le fichier ");

}
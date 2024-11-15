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
	FILE *destination = fopen("destinationEx1.txt","w");
    fseek(f,0, SEEK_END);
    int tailleFichier = ftell(f);
    int i=0;
    while(i<tailleFichier){
        i++;
        fseek(f,tailleFichier-i,SEEK_SET);
        char caracter=fgetc(f);
        fprintf(destination,"%c",caracter);
    }
}
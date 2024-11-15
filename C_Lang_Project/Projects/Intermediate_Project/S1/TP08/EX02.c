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
	char caracter[50];
    int cmpteur=1;
	while(fgets(caracter,sizeof(caracter),f) != NULL) {
        fprintf(destination, "%d-%s",cmpteur,caracter);
        cmpteur++;
	}
    fclose(f);
    fclose(destination);
	

}

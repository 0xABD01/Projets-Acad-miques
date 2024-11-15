#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int main() {
	char nomFile[20];
	int ligne,cmpLigne=1;
	printf("saisir le nom du fichier a ouvrir : ");
	gets(nomFile);

	FILE *f = fopen(nomFile, "r");
	if(f == NULL) {
		printf("Error le fichier %s n'existe pas  \n",nomFile);
		exit(1);
	}
	FILE *distanation = fopen("distination.txt","w");
	int caractere;
	printf("saisir la ligne a supprimer : ");
	scanf("%d",&ligne);
	while((caractere = fgetc(f))!=EOF) {
		if(caractere == '\n')
			cmpLigne++;
		if(cmpLigne!=ligne)
			fputc(caractere,distanation);

	}
    fclose(f);
    fclose(distanation);

}

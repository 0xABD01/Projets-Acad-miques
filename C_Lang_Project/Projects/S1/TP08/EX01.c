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
	FILE *fileNPaire = fopen("paire.txt","w");
    FILE *fileNImpair = fopen("impair.txt","w");

	int number;
	while(fscanf(f,"%d",&number)!=EOF) {
		if(number%2==0) 
            fprintf(fileNPaire,"%d ",number);
		else
			fprintf(fileNImpair,"%d ",number);

	}
    fclose(f);
    fclose(fileNPaire);
    fclose(fileNImpair);

}
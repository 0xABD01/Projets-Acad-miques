#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

void impaire(FILE *file,int N);
void paire(FILE *file,int N);
void premier(FILE *file,int N);
void parfait(FILE *file,int N);

int main() {
	int N;
	printf("saisir l'entier N : ");
	scanf("%d",&N);
	FILE *file = fopen("fileEx1.txt", "w");
	if (file == NULL) {
		printf("error d'overture de fichier : ");
		exit(1);
	}
	fprintf(file,"les Nombre impaire < %d sont : ",N);
	impaire(file,N);
	fprintf(file,"\nles Nombre paire < %d sont : ",N);
	paire(file,N);
	fprintf(file,"les Nombre premier < %d sont : ",N);
	premier(file,N);
	fprintf(file,"les Nombre parfait < %d sont : ",N);
	parfait(file,N);
	fclose(file);

}

void impaire(FILE *file,int N) {
	int i;
	for(i=0; i<N; i++) {
		if(i%2!=0) {
			fprintf(file,"%d ",i);
		}
	}
}

void paire(FILE *file,int N) {
	int i;
	for(i=0; i<N; i++) {
		if(i%2==0) {
			fprintf(file,"%d ",i);
		}
	}
}

void premier(FILE *file,int N) {
	bool estPremier;
	int i;
	int j;
	for(i=2; i<N; i++) {
		estPremier = true;
		for(j=2; j<i; j++) {
			if(i%j==0) {
				estPremier = false;
			}

		}
		if(estPremier)
			fprintf(file,"%d ",i);
	}
}

void parfait(FILE *file,int N) {
	int i;
	int j;
	for(i=2; i<N ; i++) {
		int somme = 0;
		for(j=1; j<i; j++)
			if(i%j==0)
				somme = somme+j;
		if(somme==i)
			fprintf(file,"%d ",i);
	}
}

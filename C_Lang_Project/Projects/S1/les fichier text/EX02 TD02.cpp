#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

int main() {
	FILE *fileVariable = fopen("fileVariable.txt", "a");
	if (fileVariable == NULL) {
		printf("error d'overture de fichier : ");
		exit(1);
	}
	FILE *fileSolution = fopen("fileSolution.txt","w");
    if (fileSolution == NULL) {
		printf("error d'overture de fichier : ");
		exit(2);
	}
	int A,B,C;
	fscanf(fileVariable,"%d %d %d",A,B,C);
	float X0,X1,X2,dt;
	fprintf(fileSolution,"l'equation est : %dX²+%dX+%d = 0\n la solution : ",A,B,C);
	if(A==0) {
		if(B==0) {
			if(C==0) {
				fprintf(fileSolution,"la solution est l'ensemble IR");
			}
			fprintf(fileSolution,"l'equation n'admet acune solution dans IR");
		}
		X0=-C/B;
		fprintf(fileSolution,"cette equation admet une seule solution dans IR:\nX = %f",X0);
	} else {
		dt=pow(B,2)-4*A*C;
		fprintf(fileSolution,"dt = %f donc ",dt);
		if(dt<0) {
			fprintf(fileSolution,"l'equation n'admet aucune solution dans IR");
		} else if(dt==0) {
			X0=-B/2*A;
			fprintf(fileSolution,"l'equation admet une seule solution dans IR :\nX = %f",X0);
		} else {
			X1=(-B-sqrt(dt))/2*A;
			X2=(-B+sqrt(dt))/2*A;
			fprintf(fileSolution,"l'equation admet deux solution dans IR :\nX1 = %f\nX2 = %f",X1,X2);
		}
	}
	fclose(fileSolution);
	fclose(fileVariable);

}

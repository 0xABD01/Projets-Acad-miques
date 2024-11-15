#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef struct{
    float abscisse;
    float ordonnee;
}point;

typedef struct{
    float a;
    float b;
}droite;

typedef struct{
    point centre;
    float rayon;
}cercle;

point SaisiePoint();
droite SaisieDroite();
cercle SaisieCercle();
point *saisieTabPoints();
int pointInDroite(point p,droite d);
int pointInCercle(point p,cercle c);


int main() {
    int n;
    FILE *f = fopen("fileTP.bin", "wb+");
    printf("saisir le nombre des points :");
    scanf("%d", &n);
    fwrite(saisieTabPoints(n), sizeof(point),n,f);
    rewind(f);
    droite droiteX = SaisieDroite();
    point pointX;
    while(fread(&pointX, sizeof(point),1,f)!=0){
        if(pointInDroite(pointX,droiteX)==1)
           printf("le point P(%f,%f) appartiennent a la droite D ");
        else 
           printf("le point P(%f,%f) n'appartiennent pas a droite D ");
    }
    printf("\n----------------------------------------------------------------\n");
    rewind(f);
    cercle cercleX = SaisieCercle();
    while(fread(&pointX, sizeof(point),1,f)!=0){
        if(pointInCercle(pointX,cercleX)==1)
           printf("le point P(%f,%f) appartiennent au cercle C ");
        else 
           printf("le point P(%f,%f) n'appartiennent au cercle C ");
    }
    
}
point SaisiePoint(){
    point pointX;
    printf("saisir les deux points :\n");
    printf("Abscisse :");
    scanf("%f",&pointX.abscisse);
    printf("Ordonnee :");
    scanf("%f",&pointX.ordonnee);
    return pointX;
}
droite SaisieDroite(){
    droite droiteX;
    printf("saisir les deux points du droite :\n");
    printf("A :");
    scanf("%f",&droiteX.a);
    printf("B :");
    scanf("%f",&droiteX.b);
    return droiteX;
}
cercle SaisieCercle(){
    cercle cercleX;
    printf("saisir le :\n");
    printf("Centre .Abscisse :");
    scanf("%f",&cercleX.centre.abscisse);
    printf("       .Ordonnee :");
    scanf("%f",&cercleX.centre.ordonnee);
    printf("Rayon :");
    scanf("%f",&cercleX.rayon);
    return cercleX;
}
point *saisieTabPoints(int n){
    point *tab=(point*)malloc(n*sizeof(point));
    for(int i=0;i<n;i++){
        printf("point %d :\n",i+1);
        tab[i]=SaisiePoint();
    }
    return tab;
}
int pointInDroite(point p,droite d){
    float Y=(d.a*p.abscisse)+d.b;
    if(Y==p.ordonnee)
       return 1;
    else
       return -1;
}
int pointInCercle(point p,cercle c){
    float AO=sqrt(pow((p.abscisse-c.centre.abscisse),2)+pow((p.ordonnee-c.centre.ordonnee),2));
    if(AO==c.rayon)
       return 1;
    else
       return -1;    
}
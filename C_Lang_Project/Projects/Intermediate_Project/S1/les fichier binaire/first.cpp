#include <stdio.h>
#include <stdlib.h>
main()
{ FILE *f; int posOctet; char nomFichier[24];
printf("entrer le nom du fichier : ");
scanf("%s", nomFichier);
printf("entrer la position d’octet a rechercher \n");
scanf("%d",&posOctet);
if((f= fopen(nomFichier, "r")) == NULL)
{
printf("\nImpossible d’ouvrir le fichier\n");
exit(1);
}
if(fseek(f,posOctet, SEEK_SET))
{
printf("erreur de seek\n");
exit(1);
}
printf("Octet a position %d est %c\n",posOctet,fgetc(f));
printf("la position du pointeur est %ld\n",ftell(f));
rewind(f);
printf("la position du pointeur est %ld\n",ftell(f));
}

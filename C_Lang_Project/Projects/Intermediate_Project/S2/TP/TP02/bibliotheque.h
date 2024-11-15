
typedef struct cellule{
    char valeur[30];
    struct cellule *next;
} cellule ,*liste;


liste AjouterAlaFin(liste l, char valeur[]);
void AfficherCellule(liste l);
liste trieOrdreAlpha(liste l);
liste supprimerValeur(liste l, char valeur[]);




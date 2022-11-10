#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

int main()
{
    reclamation r1= {1,2,3,4,"rouge","vert",15},r2= {1,2,3,4,"noir","bbbbcs",20},r3;
    int x=ajouter("reclamation.txt", r1);

    if(x==1)
        printf("\najout de point avec succ�s");
    else printf("\nechec ajout");

    x=modifier("reclamation.txt",15,r2 );

   if(x==1)
        printf("\nModification de reclamation avec succ�s");
    else printf("\nechec Modification");
    x=supprimer("reclamation.txt",20);
    if(x==1)
        printf("\nSuppression de reclamation avec succ�s");
    else printf("\nechec Suppression");
    r3=chercher("reclamation.txt",20 );
    if(r3.id_reclamation==-1)
        printf("\nintrouvable");
    return 0;
}


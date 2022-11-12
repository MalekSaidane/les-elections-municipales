#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main()
{
    user p1={"saidane","malek",3,"electeur",21,11,2001,114,"fff"},p2= {"jarraya","mahmoud",3,"electeur",5,5,5,074,"eee"},p3;
    int x=ajouter("user.txt", p1);

    if(x==1)
        printf("\najout de user avec succés");
    else printf("\nechec ajout");

    x=modifier("user.txt",114,p2 );

    if(x==1)
        printf("\nModification de user avec succés");
    else printf("\nechec Modification");
    x=supprimer("user.txt",7);
    if(x==1)
        printf("\nSuppression de user avec succés");
    else printf("\nechec Suppression");

    p3=chercher("user.txt", 558);
    if(p3.id==-1)
        printf(" \nintrouvable\n");
    return 0;
}




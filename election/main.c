#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

int main()
{
    election rec, rc,r1= {1,2,3,4,"rouge","vert",15,44},r2= {1,2,3,4,"noir","bbbbcs",20,44},r3;
    int choix_fonctionnalites, x, id_rec;


do
    {
do
{

        printf("Choisir une fonctionnalites : Quitter (0), Ajouter election (1), modifier election (2),  Afficher election (3), Supprimer election (4).\n");
        scanf("%d",&choix_fonctionnalites);
        if (choix_fonctionnalites==1)
        {
                creation_election(&rec);
                int x= ajouter("election.txt", rec);
                if(x==1)
                printf("\n ajout election avec succes \n");
                else printf("\n echec ajout");
        }
        if (choix_fonctionnalites==2)
        {
           	printf("Donner ID de l'election a modifier \n");
		    scanf("%d",&id_rec);
                x= modifier("election.txt",id_rec,rec);
                if(x==1)
                printf("\n Modification de l'election avec succes \n");
                else printf("\n echec Modification");
        }
        if (choix_fonctionnalites==3)
        {
           	printf("Donner ID de l'election a chercher \n");
		    scanf("%d",&id_rec);
            rc= chercher("election.txt",id_rec );
        if(rc.ID_election==-1)
            printf("\n introuvable \n");
	    else
	    printf("\n %d %d %d %d %d %d %s \n ",rc.de.jour,rc.de.mois,rc.de.annee,rc.ID_election,rc.nb_habitants,rc.nb_conseillers,rc.municipalite);
        }

        if (choix_fonctionnalites==4)
        {
		printf("Donner ID de l'election a supprimer \n");
		scanf("%d",&id_rec);

                x= supprimer("election.txt",id_rec);
                if(x==1)
                printf("\n Suppression de l'election avec succ�s \n");
                else printf("\n echec Suppression \n");
        }
	}
	while ((choix_fonctionnalites<0) || (choix_fonctionnalites>4));
    }
    while ((choix_fonctionnalites!=0));

   printf("\n Au revoir. \n");

    return 0;
}


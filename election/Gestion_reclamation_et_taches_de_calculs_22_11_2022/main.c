#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

int main()
{
    reclamation rec, rc,r1= {1,2,3,4,"rouge","vert",15,44},r2= {1,2,3,4,"noir","bbbbcs",20,44},r3;
    int choix_fonctionnalites, x, id_rec;
    int nr;
    float vb;
    int nb[50];


   do
    {
        do
        {

            printf("Choisir une fonctionnalites : Quitter (0), Ajouter reclamation (1), modifier reclamation (2),  Afficher reclamation (3), Supprimer reclamation (4).\n");
            scanf("%d",&choix_fonctionnalites);
            if (choix_fonctionnalites==1)
            {
                creation_reclamation(&rec);
                int x= ajouter("reclamation.txt", rec);
                if(x==1)
                    printf("\najout reclamation avec succ�s \n");
                else printf("\nechec ajout");
            }
            if (choix_fonctionnalites==2)
            {
                printf("Donner ID de la reclamation a modifier \n");
                scanf("%d",&id_rec);
                x= modifier("reclamation.txt",id_rec,rec);
                if(x==1)
                    printf("\nModification de la reclamation avec succ�s \n");
                else printf("\n echec Modification");
            }
            if (choix_fonctionnalites==3)
            {
                printf("Donner ID de la reclamation a chercher \n");
                scanf("%d",&id_rec);
                rc= chercher("reclamation.txt",id_rec );
                if(rc.id_reclamation==-1)
                    printf("\nintrouvable \n");
                else
                    printf("\n %d %d %d %d %s %s %d %d \n ",rc.ID_bureau_de_vote,rc.ID_liste_electorale,rc.hm.heure,rc.hm.minute,rc.type_reclamation,rc.texte_reclamation,rc.id_reclamation,rc.id_observateur);
            }
            if (choix_fonctionnalites==4)
            {
                printf("Donner ID de la reclamation a supprimer \n");
                scanf("%d",&id_rec);

                x= supprimer("reclamation.txt",id_rec);
                if(x==1)
                    printf("\nSuppression de reclamation avec succ�s \n");
                else printf("\nechec Suppression \n");
            }
        }
        while ((choix_fonctionnalites<0) || (choix_fonctionnalites>4));
    }
    while ((choix_fonctionnalites!=0));


    nr= nbreclamation(nb, "reclamation.txt", "listeelectorale.txt");
    vb=TVB ("user.txt");
    printf("nombre reclamation : %d \n",nr);
    printf("Pourcentage votes blanc : %f \n",vb);

    printf("\nAu revoir.\n");

    return 0;
}


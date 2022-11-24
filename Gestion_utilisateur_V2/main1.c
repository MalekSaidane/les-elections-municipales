#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main()
{
user  u1,p;
int x,choix_fonctionnalites,id;
float taux, moy;
user nouv;

do
     {
do
     {
        printf("Choisir une fonctionnalites : Quitter (0), Ajouter un utilisateur (1), modifier un utilisateur (2), chercher un utilisateur (3), Supprimer un utilisateur (4).\n");
        scanf("%d",&choix_fonctionnalites);
        if (choix_fonctionnalites==1)
           {
        creation_utilisateur(&u1);



	x=ajouter("user.txt",u1);
	if (x==1)
	    printf("ajout d'un utilisateur avec succes\n");
	else
	    printf("echec de l'ajout\n");
            }


        if (choix_fonctionnalites==2)
         {
        printf("donner l'id de l'utilisateur a modifier");
        scanf("%d",&id);
	x=modifier("user.txt",id,nouv);
	if (x==1)
	    printf("modification d'un utilisateur avec succees\n");
	else
	    printf("echec de modifier\n");

           }
        if (choix_fonctionnalites==4)
        {
        printf("donner l'id de l'utilisateur a supprimer");
        scanf("%d",&id);
        x=supprimer("user.txt",id);
	if (x==1)
	    printf("suppression d'un utilisateur avec succees\n");
	else
	    printf("echec de suppression\n");
        }


        if (choix_fonctionnalites==3)
        {
        printf("donner l'id de l'utilisateur a chercher");
        scanf("%d",&id);

	p=chercher("user.txt",id);
	if (p.id==-1)
	    printf("introuvable\n");
	else
	    printf("%d %s %s %s %s %s %d %d %d %d %d %d \n",p.id,p.nom,p.prenom,p.sexe,p.role,p.pwd,p.numbv,p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee,p.vote,p.id_list);
       }




    }
       while ((choix_fonctionnalites<0) && (choix_fonctionnalites>4));
        }

       while ((choix_fonctionnalites!=0));

        printf("\n Au revoir. \n");

	taux=TPE("user.txt");
	printf("taux de participation d'electeur est %f \n",taux);

	moy=agemoyen("user.txt");
	printf("la moyenne d'age est %f \n",moy);



	return 0;
}


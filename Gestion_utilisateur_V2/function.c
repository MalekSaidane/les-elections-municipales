#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int ajouter(char * filename, user p )
{
    FILE *f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %s %s %s %d %d %d %d %d %d\n",p.id,p.nom,p.prenom,p.sexe,p.role,p.pwd,p.numbv,p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee,p.vote,p.id_list);
        fclose(f);

        return 1;
    }
    else
        return 0;
}
int modifier( char * filename, int id,user nouv )
{
    int tr=0;
    user p;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d %d\n",&p.id,p.nom,p.prenom,p.sexe,p.role,p.pwd,&p.numbv,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,&p.vote,&p.id_list)!=EOF)
        {
            if(p.id== id)
            {
                fprintf(f2,"%d %s %s %s %s %s %d %d %d %d %d %d\n",nouv.id,nouv.nom,nouv.prenom,nouv.role,nouv.pwd,nouv.numbv,nouv.date_de_naissance.jour,nouv.date_de_naissance.mois,nouv.date_de_naissance.annee,nouv.vote,nouv.id_list);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %s %s %s %s %d %d %d %d %d %d\n",p.id,p.nom,p.prenom,p.sexe,p.role,p.pwd,p.numbv,p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee,p.vote,p.id_list);


        }
    }

    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}

void creation_utilisateur(user *e)
{
    printf("Donner l'id \n");
    scanf("%d",&e->id);
    printf("Donner le nom \n");
    scanf("%s",e->nom);
    printf("Donner le prenom\n");
    scanf("%s",e->prenom);
    printf("Donner le sexe \n");
    scanf("%s",e->sexe);
    printf("Donner le role \n");
    scanf("%s",e->role);
    printf("Donner le mot de passe \n");
    scanf("%s",e->pwd);
    printf("Donner le numero de bureau de vote \n");
    scanf("%d",&e->numbv);
    printf("Donner le jour de naissance \n");
    scanf("%d",&e->date_de_naissance.jour);
    printf("Donner le mois de naissance \n");
    scanf("%d",&e->date_de_naissance.mois);
    printf("Donner l'annee de naissance \n");
    scanf("%d",&e->date_de_naissance.annee);

	e->vote=-1;
        e->id_list=-1;
}

int supprimer(char * filename, int id)
{
    int tr=0;
    user p;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d %d\n",&p.id,p.nom,p.prenom,p.sexe,p.role,p.pwd,&p.numbv,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,&p.vote,&p.id_list)!=EOF)
        {
            if(p.id== id)
                tr=1;
            else
                fprintf(f2,"%d %s %s %s %s %s %d %d %d %d %d %d\n",p.id,p.nom,p.prenom,p.sexe,p.role,p.pwd,p.numbv,p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee,p.vote,p.id_list);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

 user chercher(char * filename, int id)

{
    user p;
    int tr=0;
    FILE * f=fopen(filename, "r");

    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d %d\n",&p.id,p.nom,p.prenom,p.sexe,p.role,p.pwd,&p.numbv,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,&p.vote,&p.id_list)!=EOF)
        {
            if(p.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        p.id=-1;

    return p;
}



float agemoyen(char * fichierusers)
{ user p;
int nb_age=0;
int nb_elec=0;
float moy;


  FILE *f=fopen(fichierusers, "r");
  if(f!=NULL )
    {
          while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d %d \n",&p.id,p.nom,p.prenom,p.sexe,p.role,p.pwd,&p.numbv,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,&p.vote,&p.id_list)!=EOF)
        {
             if (strcmp(p.role,"Electeur")==0)
               {
                  nb_elec++;

                  nb_age =(2022 - p.date_de_naissance.annee) + nb_age;
               }
        }
          
              
               moy=(float)nb_age/nb_elec;

    }
fclose(f);
    return moy;
}




float TPE( char * filename)
{
    int nb_elec=0;
    int nb_elec_vote=0;
    float taux;
    user p;


FILE *f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d %d\n",&p.id,p.nom,p.prenom,p.sexe,p.role,p.pwd,&p.numbv,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,&p.vote,&p.id_list)!=EOF)
        {
    if (strcmp("Electeur",p.role)==0)
    {
        nb_elec++;
    }
    if ((strcmp("Electeur",p.role)==0)&&(p.vote!=-1))
    {
        nb_elec_vote++;
    }
    }

    printf(" nb electeur %d \n",nb_elec_vote);
        printf(" nb vote %d \n",nb_elec);


  taux= (float)nb_elec_vote/nb_elec ;
    fclose(f);
    return taux;
}


}







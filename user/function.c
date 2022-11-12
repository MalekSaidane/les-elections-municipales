#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int ajouter(char * filename, user p )
{
    FILE *f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %s %s %d %d %d %d\n",p.id,p.nom,p.prenom,p.role,p.pwd,p.numbv,p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee);
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
        while(fscanf(f,"%d %s %s %s %s %d %d %d %d\n",&p.id,p.nom,p.prenom,p.role,p.pwd,&p.numbv,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee)!=EOF)
        {
            if(p.id== id)
            {
                fprintf(f2,"%d %s %s %s %s %d %d %d %d\n",nouv.id,nouv.nom,nouv.prenom,nouv.role,nouv.pwd,nouv.numbv,nouv.date_de_naissance.jour,nouv.date_de_naissance.mois,nouv.date_de_naissance.annee);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %s %s %s %d %d %d %d\n",p.id,p.nom,p.prenom,p.role,p.pwd,p.numbv,p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee);


        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimer(char * filename, int id)
{
    int tr=0;
    user p;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %s %s %d %d %d %d\n",&p.id,p.nom,p.prenom,p.role,p.pwd,&p.numbv,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee)!=EOF)
        {
            if(p.id== id)
                tr=1;
            else
                fprintf(f2,"%d %s %s %s %s %d %d %d %d\n",p.id,p.nom,p.prenom,p.role,p.pwd,p.numbv,p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee);
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
        while(tr==0 && fscanf(f,"%d %s %s %s %s %d %d %d %d\n",&p.id,p.nom,p.prenom,p.role,p.pwd,&p.numbv,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee)!=EOF)
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



   

#include <stdio.h>
#include<stdlib.h>
#include "fonction.h"

////////////////////////////////////////////////////////////////////////////////////////////////

int ajouter(char * filename, election e )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %d %d %s \n",e.de.jour,e.de.mois,e.de.annee,e.ID_election,e.nb_habitants,e.nb_conseillers,e.municipalite);
        fclose(f);
        return 1;
    }
    else return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////

int modifier( char * filename, int id, election e_modifier )
{
    int tr=0;
    election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d %d %s \n",&e.de.jour,&e.de.mois,&e.de.annee,&e.ID_election,&e.nb_habitants,&e.nb_conseillers,e.municipalite)!=EOF)
        {
            if(e.ID_election== id)
            {
                creation_election(&e_modifier);
                e_modifier.ID_election=id;
                fprintf(f2,"%d %d %d %d %d %d %s \n",e.de.jour,e.de.mois,e.de.annee,e.ID_election,e.nb_habitants,e.nb_conseillers,e.municipalite);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %d %d %d %s \n",e.de.jour,e.de.mois,e.de.annee,e.ID_election,e.nb_habitants,e.nb_conseillers,e.municipalite);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}

////////////////////////////////////////////////////////////////////////////////////////////////

int supprimer(char * filename, int id)
{
    int tr=0;
    election e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");

    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d %d %s \n",&e.de.jour,&e.de.mois,&e.de.annee,&e.ID_election,&e.nb_habitants,&e.nb_conseillers,e.municipalite)!=EOF)
        {
            if(e.ID_election== id)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %d %d %s \n",e.de.jour,e.de.mois,e.de.annee,e.ID_election,e.nb_habitants,e.nb_conseillers,e.municipalite);
        }
    }

    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

////////////////////////////////////////////////////////////////////////////////////////////////

election chercher(char * filename, int id)
{
    election e;
    int tr;
    tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %d %d %d %s \n",&e.de.jour,&e.de.mois,&e.de.annee,&e.ID_election,&e.nb_habitants,&e.nb_conseillers,e.municipalite)!=EOF)
        {
            if(e.ID_election== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        e.ID_election=-1;
    return e;

}


////////////////////////////////////////////////////////////////////////////////////////////////

void creation_election(election *e)
{
    printf("Donner le jour de l'election \n");
    scanf("%d",&e->de.jour);
    printf("Donner le mois de l'election \n");
    scanf("%d",&e->de.mois);
    printf("Donner l'anne de l'election\n");
    scanf("%d",&e->de.annee);
    printf("Donner ID de l'election \n");
    scanf("%d",&e->ID_election);
    printf("Donner le nb des habitants \n");
    scanf("%s",&e->nb_habitants);
    if (e->nb_habitants<=5000);
    {
        e->nb_conseillers=10;
    }
        if ( (5000<e->nb_habitants) && (e->nb_habitants<=10000));
    {
        e->nb_conseillers=12;
    }
        if ( (10000<e->nb_habitants) && (e->nb_habitants<=25000));
    {
        e->nb_conseillers=16;
    }
        if ( (25000<e->nb_habitants) && (e->nb_habitants<=50000));
    {
        e->nb_conseillers=22;
    }
        if ( (50000<e->nb_habitants) && (e->nb_habitants<=100000));
    {
        e->nb_conseillers=30;
    }
    if ( (100000<e->nb_habitants) && (e->nb_habitants<=500000));
    {
        e->nb_conseillers=40;
    }
    if (500000<e->nb_habitants);
    {
        e->nb_conseillers=60;
    }

    //printf("Donner le texte de la reclamation \n");
    //scanf("%d",&e->nb_conseillers);
    printf("Donner la municipalite de l'election \n");
    scanf("%s",e->municipalite);
}

////////////////////////////////////////////////////////////////////////////////////////////////


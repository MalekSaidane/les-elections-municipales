#include <stdio.h>
#include<stdlib.h>
#include "fonction.h"

int ajouter(char * filename, reclamation r )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %s %s %d \n",r.ID_bureau_de_vote,r.ID_liste_electorale,r.hm.heure,r.hm.minute,r.type_reclamation,r.texte_reclamation,r.id_reclamation);
        fclose(f);
        return 1;
    }
    else return 0;
}


int modifier( char * filename, int id, reclamation r_modifier )
{
    int tr=0;
    reclamation r;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %s %s %d \n",&r.ID_bureau_de_vote,&r.ID_liste_electorale,&r.hm.heure,&r.hm.minute,r.type_reclamation,r.texte_reclamation,&r.id_reclamation)!=EOF)
        {
            if(r.id_reclamation== id)
            {
                fprintf(f2,"%d %d %d %d %s %s %d \n",r_modifier.ID_bureau_de_vote,r_modifier.ID_liste_electorale,r_modifier.hm.heure,r_modifier.hm.minute,r_modifier.type_reclamation,r_modifier.texte_reclamation,r_modifier.id_reclamation);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %d %s %s %d \n",r.ID_bureau_de_vote,r.ID_liste_electorale,r.hm.heure,r.hm.minute,r.type_reclamation,r.texte_reclamation,r.id_reclamation);

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
    reclamation r;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");

    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %s %s %d \n",&r.ID_bureau_de_vote,&r.ID_liste_electorale,&r.hm.heure,&r.hm.minute,r.type_reclamation,r.texte_reclamation,&r.id_reclamation)!=EOF)
        {
            if(r.id_reclamation== id)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %s %s %d \n",r.ID_bureau_de_vote,r.ID_liste_electorale,r.hm.heure,r.hm.minute,r.type_reclamation,r.texte_reclamation,r.id_reclamation);
        }
    }

    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
reclamation chercher(char * filename, int id)
{
    reclamation r;
    int tr;
    tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %s %d %d\n",&r.ID_bureau_de_vote,&r.ID_liste_electorale,&r.hm.heure,&r.hm.minute,r.type_reclamation,r.texte_reclamation,&r.id_reclamation)!=EOF)
        {
            if(r.id_reclamation== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        r.id_reclamation=-1;
    return r;

}


#include <stdio.h>
#include<stdlib.h>
#include "fonction.h"

int ajouter(char * filename, reclamation r )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %s %s %d %d \n",r.ID_bureau_de_vote,r.ID_liste_electorale,r.hm.heure,r.hm.minute,r.type_reclamation,r.texte_reclamation,r.id_reclamation,r.id_observateur);
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
        while(fscanf(f,"%d %d %d %d %s %s %d %d \n",&r.ID_bureau_de_vote,&r.ID_liste_electorale,&r.hm.heure,&r.hm.minute,r.type_reclamation,r.texte_reclamation,&r.id_reclamation,&r.id_observateur)!=EOF)
        {
            if(r.id_reclamation== id)
            {
                creation_reclamation(&r_modifier);
		r_modifier.id_reclamation=id;
                fprintf(f2,"%d %d %d %d %s %s %d %d \n",r_modifier.ID_bureau_de_vote,r_modifier.ID_liste_electorale,r_modifier.hm.heure,r_modifier.hm.minute,r_modifier.type_reclamation,r_modifier.texte_reclamation,r_modifier.id_reclamation,r.id_observateur);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %d %s %s %d %d \n",r.ID_bureau_de_vote,r.ID_liste_electorale,r.hm.heure,r.hm.minute,r.type_reclamation,r.texte_reclamation,r.id_reclamation,r.id_observateur);

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
        while(fscanf(f,"%d %d %d %d %s %s %d %d \n",&r.ID_bureau_de_vote,&r.ID_liste_electorale,&r.hm.heure,&r.hm.minute,r.type_reclamation,r.texte_reclamation,&r.id_reclamation,&r.id_observateur)!=EOF)
        {
            if(r.id_reclamation== id)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %s %s %d %d \n",r.ID_bureau_de_vote,r.ID_liste_electorale,r.hm.heure,r.hm.minute,r.type_reclamation,r.texte_reclamation,r.id_reclamation,r.id_observateur);
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
        while(tr==0&& fscanf(f,"%d %d %d %d %s %s %d %d  \n",&r.ID_bureau_de_vote,&r.ID_liste_electorale,&r.hm.heure,&r.hm.minute,r.type_reclamation,r.texte_reclamation,&r.id_reclamation,&r.id_observateur)!=EOF)
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


void creation_reclamation(reclamation *r)
{
	printf("Donner ID du bureau de vote \n");
	scanf("%d",&r->ID_bureau_de_vote);
	printf("Donner ID de la liste electorale \n");
	scanf("%d",&r->ID_liste_electorale);
	printf("Donner heure reclamation \n");
	scanf("%d",&r->hm.heure);
	printf("Donner minute de la reclamation \n");
	scanf("%d",&r->hm.minute);
	printf("Donner le type de la reclamation \n");
	scanf("%s",r->type_reclamation);
	printf("Donner le texte de la reclamation \n");
	scanf("%s",r->texte_reclamation);
	printf("Donner ID de la reclamation \n");
	scanf("%d",&r->id_reclamation);
	printf("Donner ID observateur \n");
	scanf("%d",&r->id_observateur);
}




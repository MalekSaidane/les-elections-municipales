#include <stdio.h>
#include<stdlib.h>
#include "fonction.h"

////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////


//Atelier interface graphique

/*int tableau_reclamation(reclamation tab[])
{
    int n;
    FILE * f=fopen(reclamation.txt, "r");
    if (f!=NULL)
    {
        while (fscanf(f,"%d %d %d %d %s %s %d %d \n",&r.ID_bureau_de_vote,&r.ID_liste_electorale,&r.hm.heure,&r.hm.minute,r.type_reclamation,r.texte_reclamation,&r.id_reclamation,&r.id_observateur)!=EOF)
        {
            n++;
        }
        fclose(f);
    }
    return n;
}


*/


//retourner les reclamations de l'observateur obi
int reclamation_par_observateur(reclamation rec, char filereclamation)
{
    reclamation r;
    int i=0;
    int nrc=0;
    FILE * f2=fopen("file_reclamation_observateur.txt", "w");
    FILE * f=fopen(filereclamation, "r");
    if (f!=NULL)
    {
        while (fscanf(f,"%d %d %d %d %s %s %d %d \n",&r.ID_bureau_de_vote,&r.ID_liste_electorale,&r.hm.heure,&r.hm.minute,r.type_reclamation,r.texte_reclamation,&r.id_reclamation,&r.id_observateur)!=EOF)
        {
            if (r.id_observateur==rec.id_observateur)
            {
                fprintf(f2,"%d %d %d %d %s %s %d %d \n",r.ID_bureau_de_vote,r.ID_liste_electorale,r.hm.heure,r.hm.minute,r.type_reclamation,r.texte_reclamation,r.id_reclamation,r.id_observateur);
                nrc++;

            }
        }
        fclose(f);
        fclose(f);
    }

    return nrc;
}


////////////////////////////////////////////////////////////////////////////////////////////////
//Tache calcul
////////////////////////////////////////////////////////////////////////////////////////////////

//1-Le nombre de réclamations par liste électorale

/*
int nbreclamation(int nb[], char * fichierreclamation, char *  fichierlisteelectorale)
{
    int nb_total=0;
    int idl[50]={0};
    int ir[50]={0};
    int k=0;
    int i=0;
    int nrt=0;
    int j,h;
    reclamation r;
    ListeElectorale l;


    FILE * f=fopen(fichierlisteelectorale, "r");
    FILE * f2=fopen(fichierreclamation, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %s %d %d %d %d %d/%d/%d\n",&l.id_liste,l.orientation,&l.candidats[0],&l.candidats[1],&l.candidats[2],&l.nbVote,&l.dateDeCreation.jour,&l.dateDeCreation.mois,&l.dateDeCreation.annee)!=EOF)
        {
            *(idl+i)=l.id_liste;
          i++;
        }

    }


k=i;

for (j=0;j<i;j++)
{


    *(nb+j)=0;
    if(f2!=NULL)
        {
                while((k!=0) && (fscanf(f2,"%d %d %d %d %s %s %d %d \n",&r.ID_bureau_de_vote,&r.ID_liste_electorale,&r.hm.heure,&r.hm.minute,r.type_reclamation,r.texte_reclamation,&r.id_reclamation,&r.id_observateur)!=EOF))
                {
                    if (*(idl+j)==r.ID_liste_electorale)
                    {
                        *(nb+j)=*(nb+j) + 1 ;
                    }
                }
                k--;
        }
}

    for (j=0;j<i;j++)
    {
        printf("le nombre de reclamationde de la liste electorale qui a l'ID %d est : %d \n",*(idl+j),*(nb+j));
        nrt=*(nb+j) + nrt;
    }


    fclose(f);
    fclose(f2);
    return nrt;
}


*/
// a demander pourquoi la fonction ne fait qu'une seule iteration de for pour le while de fscanf


int nbreclamation(int nb[], char * fichierreclamation, char *  fichierlisteelectorale)
{
    int nb_total=0;
    int idl[50]={0};
    int ir[50]={0};
    int k=0;
    int i=0;
    int nrt=0;
    int j,h;
    reclamation r;
    ListeElectorale l;


    FILE * f=fopen(fichierlisteelectorale, "r");
    FILE * f2=fopen(fichierreclamation, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %s %d %d %d %d %d/%d/%d\n",&l.id_liste,l.orientation,&l.candidats[0],&l.candidats[1],&l.candidats[2],&l.nbVote,&l.dateDeCreation.jour,&l.dateDeCreation.mois,&l.dateDeCreation.annee)!=EOF)
        {

            *(idl+i)=l.id_liste;

          i++;

        }
    }



       if(f2!=NULL)
        {


                while(fscanf(f2,"%d %d %d %d %s %s %d %d \n",&r.ID_bureau_de_vote,&r.ID_liste_electorale,&r.hm.heure,&r.hm.minute,r.type_reclamation,r.texte_reclamation,&r.id_reclamation,&r.id_observateur)!=EOF)
                {
                    *(ir+k)=r.ID_liste_electorale;
                    k++;

                }
        }


    for (j=0;j<i;j++)
    {
        *(nb+j)=0;
        for (h=0;h<k;h++)
        {
            if (*(idl+j) == *(ir+h))
            {
                *(nb+j)=*(nb+j) + 1 ;
            }
        }
    }



    for (j=0;j<i;j++)
    {
        printf("le nombre de reclamationde de la liste electorale qui a l'ID %d est : %d \n",*(idl+j),*(nb+j));
        nrt=*(nb+j) + nrt;
    }


    fclose(f);
    fclose(f2);
    return nrt;
}



////////////////////////////////////////////////////////////////////////////////////////////////

//2-Le taux de votes blancs
float TVB (char * nom_Fichier) //fichier user avec p.vote modifier apres election
{
    int nb_total=0;
    int nb_voteblanc=0;
    float vb=0, rb;
    user p;

    FILE * f=fopen(nom_Fichier, "r"); //fichier user
    if(f!=NULL)
    {
        while(fscanf(f,"%d %s %s %s %s %d %d %d %d %d\n",&p.id,p.nom,p.prenom,p.role,p.pwd,&p.numbv,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,&p.vote)!=EOF)
        {
            if (strcmp(p.role,"Electeur")==0)//strcmp(p.role,"Electeur" (p.role=="Electeur")
            {
                nb_total++;
                if (p.vote==0)
                {
                    nb_voteblanc++;
                }
            }


        }
        vb=(float)nb_voteblanc*100/nb_total;
    }
    fclose(f);
    return vb;
}














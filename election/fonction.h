#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED


typedef struct
{
    int jour;
    int mois;
    int annee;

}date_election;


typedef struct
{
    date_election de;
    int ID_election;
    int nb_habitants;
    int nb_conseillers;
    char municipalite[20];
}election;


int ajouter(char * filename, election e );
int modifier( char * filename, int id, election e_modifier );
int supprimer(char * filename, int id);
election chercher(char * filename, int id);
void creation_election(election *e);

#endif // FONCTION_H_INCLUDED

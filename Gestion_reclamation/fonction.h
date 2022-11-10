#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

typedef struct
{
    int heure;
    int minute;

}heure_reclamation;


typedef struct
{
    int ID_bureau_de_vote;
    int ID_liste_electorale;
    heure_reclamation hm;
    char type_reclamation[150];
    char texte_reclamation[150];
    int id_reclamation;
}reclamation;


int ajouter(char * filename, reclamation r );
int modifier( char * filename, int id, reclamation r_modifier );
int supprimer(char * filename, int id);
reclamation chercher(char * filename, int id);


#endif // FONCTION_H_INCLUDED


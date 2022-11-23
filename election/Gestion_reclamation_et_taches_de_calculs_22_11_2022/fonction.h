#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

//////////////////////////////////////////////////////////////////
//struct reclamation
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
    int id_observateur;
}reclamation;


//////////////////////////////////////////////////////////////////
//struct utilisateur
typedef struct
{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct
{
    char nom [10];
    char prenom [10];
    int numbv;
    char role[50];
    Date date_de_naissance;
    int id;
    char pwd[50];
    int vote;
}user;

//////////////////////////////////////////////////////////////////
//struct liste_electorale

typedef struct DateListe{
	int jour;
	int mois;
	int annee;
}DateListe;

typedef struct ListeElectorale{
	int id_liste;
	char orientation[10];
	int candidats[3];
	int nbVote;
	DateListe dateDeCreation;
}ListeElectorale;


//////////////////////////////////////////////////////////////////
//fonctions

int ajouter(char * filename, reclamation r );
int modifier( char * filename, int id, reclamation r_modifier );
int supprimer(char * filename, int id);
reclamation chercher(char * filename, int id);
void creation_reclamation(reclamation *r);



int nbreclamation(int nb[], char * fichierreclamation, char *  listeelectorale);
float TVB (char * nom_Fichier);

#endif // FONCTION_H_INCLUDED

#include <gtk/gtk.h>
typedef struct
{
	int jour;
	int mois;
	int annee;
}Date;
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
typedef struct{
	char nom [10];
	char prenom [10];
	char sexe [10];
	int numbv;
	char role[50];
	Date date_de_naissance;
	int id;
	char pwd[50];
	int vote;
}user;
int ajouterListeElectorale(ListeElectorale listeElectorale, char nomfichier[20]);
int modifierListeElectorale(int id_modifier,ListeElectorale listeElectorale_modifier);
int supprimerListeElectorale(int id_supprimer);
ListeElectorale rechercheListeElectorale(int id_recherche);
int afficherListeElectoraleTerminal();
void afficherListeElectorale(char nom_ficher[20],GtkWidget *liste);
void triListeElectoraleParnbVote();
void afficherListeElectorale(char nom_ficher[20],GtkWidget *liste);
void vote(int id_user,int id_liste);

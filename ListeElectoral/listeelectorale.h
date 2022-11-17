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

int ajouterListeElectorale(ListeElectorale listeElectorale);
int modifierListeElectorale(int id_modifier,ListeElectorale listeElectorale_modifier);
int supprimerListeElectorale(int id_supprimer);
int rechercheListeElectorale(int id_recherche);
int afficherListeElectorale();

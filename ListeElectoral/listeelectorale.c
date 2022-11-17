#include<stdio.h>
#include<stdlib.h>
#include "listeelectorale.h"

int ajouterListeElectorale(ListeElectorale listeElectorale){
	FILE *f;
	f=fopen("listeelectorale.txt","a+");
	if(f==NULL){
		return 0;
	}
	else{
		fprintf(f,"%d %s %d %d %d %d %d/%d/%d\n",
							listeElectorale.id_liste,
							listeElectorale.orientation,
							listeElectorale.candidats[0],
							listeElectorale.candidats[1],
							listeElectorale.candidats[2],
							listeElectorale.nbVote,
							listeElectorale.dateDeCreation.jour,
							listeElectorale.dateDeCreation.mois,
							listeElectorale.dateDeCreation.annee);
		fclose(f);
		return 1;
	}
}
int modifierListeElectorale(int id_modifier,ListeElectorale listeElectorale_modifier){
	ListeElectorale listeElectorale;
	FILE *f,*f1;
	f=fopen("listeelectorale.txt","r");
	f1=fopen("tmp.txt","a+");
	if(f==NULL || f1==NULL){
		return 0;
	}
	else{
		while(fscanf(f,"%d %s %d %d %d %d %d/%d/%d\n",
							&listeElectorale.id_liste,
							listeElectorale.orientation,
							&listeElectorale.candidats[0],
							&listeElectorale.candidats[1],
							&listeElectorale.candidats[2],
							&listeElectorale.nbVote,
							&listeElectorale.dateDeCreation.jour,
							&listeElectorale.dateDeCreation.mois,
							&listeElectorale.dateDeCreation.annee)!=EOF)
		{
			if(listeElectorale.id_liste==id_modifier){
				fprintf(f1,"%d %s %d %d %d %d %d/%d/%d\n",
									listeElectorale_modifier.id_liste,
									listeElectorale_modifier.orientation,
									listeElectorale_modifier.candidats[0],
									listeElectorale_modifier.candidats[1],
									listeElectorale_modifier.candidats[2],
									listeElectorale_modifier.nbVote,
									listeElectorale_modifier.dateDeCreation.jour,
									listeElectorale_modifier.dateDeCreation.mois,
									listeElectorale_modifier.dateDeCreation.annee);
			}
			else{
				fprintf(f1,"%d %s %d %d %d %d %d/%d/%d\n",
									listeElectorale.id_liste,
									listeElectorale.orientation,
									listeElectorale.candidats[0],
									listeElectorale.candidats[1],
									listeElectorale.candidats[2],
									listeElectorale.nbVote,
									listeElectorale.dateDeCreation.jour,
									listeElectorale.dateDeCreation.mois,
									listeElectorale.dateDeCreation.annee);
			}
		}
		fclose(f);
		fclose(f1);
		remove("listeelectorale.txt");
		rename("tmp.txt","listeelectorale.txt");
		return 1;
	}
	
}
int supprimerListeElectorale(int id_supprimer){
	ListeElectorale listeElectorale;
	FILE *f,*f1;
	f=fopen("listeelectorale.txt","r");
	f1=fopen("tmp.txt","a+");
	if(f==NULL || f1==NULL){
		return 0;
	}
	
	else{
		while(fscanf(f,"%d %s %d %d %d %d %d/%d/%d\n",
							&listeElectorale.id_liste,
							listeElectorale.orientation,
							&listeElectorale.candidats[0],
							&listeElectorale.candidats[1],
							&listeElectorale.candidats[2],
							&listeElectorale.nbVote,
							&listeElectorale.dateDeCreation.jour,
							&listeElectorale.dateDeCreation.mois,
							&listeElectorale.dateDeCreation.annee)!=EOF)
		{
			if(listeElectorale.id_liste!=id_supprimer){
				fprintf(f1,"%d %s %d %d %d %d %d/%d/%d\n",
									listeElectorale.id_liste,
									listeElectorale.orientation,
									listeElectorale.candidats[0],
									listeElectorale.candidats[1],
									listeElectorale.candidats[2],
									listeElectorale.nbVote,
									listeElectorale.dateDeCreation.jour,
									listeElectorale.dateDeCreation.mois,
									listeElectorale.dateDeCreation.annee);
			}
			
		}
		fclose(f);
		fclose(f1);
		remove("listeelectorale.txt");
		rename("tmp.txt","listeelectorale.txt");
		return 1;
	}
}
int rechercheListeElectorale(int id_recherche){
	int trouve=0;
	ListeElectorale listeElectorale;
	FILE *f;
	f=fopen("listeelectorale.txt","r");
	if(f==NULL){
		return 0;
	}
	else{
		while(fscanf(f,"%d %s %d %d %d %d %d/%d/%d\n",
							&listeElectorale.id_liste,
							listeElectorale.orientation,
							&listeElectorale.candidats[0],
							&listeElectorale.candidats[1],
							&listeElectorale.candidats[2],
							&listeElectorale.nbVote,
							&listeElectorale.dateDeCreation.jour,
							&listeElectorale.dateDeCreation.mois,
							&listeElectorale.dateDeCreation.annee)!=EOF)
		{
			if(id_recherche==listeElectorale.id_liste)
				trouve= 1;
		}
		fclose(f);
		return trouve;
	}
}
int afficherListeElectorale(){
	ListeElectorale listeElectorale;
	FILE *f;
	f=fopen("listeelectorale.txt","r");
	if(f==NULL){
		return 0;
	}
	else{
		while(fscanf(f,"%d %s %d %d %d %d %d/%d/%d\n",
							&listeElectorale.id_liste,
							listeElectorale.orientation,
							&listeElectorale.candidats[0],
							&listeElectorale.candidats[1],
							&listeElectorale.candidats[2],
							&listeElectorale.nbVote,
							&listeElectorale.dateDeCreation.jour,
							&listeElectorale.dateDeCreation.mois,
							&listeElectorale.dateDeCreation.annee)!=EOF)
		{
			printf("%d %s %d %d %d %d %d/%d/%d\n",
							listeElectorale.id_liste,
							listeElectorale.orientation,
							listeElectorale.candidats[0],
							listeElectorale.candidats[1],
							listeElectorale.candidats[2],
							listeElectorale.nbVote,
							listeElectorale.dateDeCreation.jour,
							listeElectorale.dateDeCreation.mois,
							listeElectorale.dateDeCreation.annee);
		}
		fclose(f);
		return 1;
	}
}

}


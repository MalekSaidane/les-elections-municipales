#include <stdio.h>
#include <stdlib.h>
#include "listeelectorale.h"

int main(){
	int choix,id_modifier,id_supprimer;
int resultat_afficher;
	ListeElectorale listeElectorale,listeElectoralemodifier;
	do{
		do{
			printf("----------------MENU--------------------\n");
			printf("1) Ajouter une liste electorale\n");
			printf("2) Modifier une liste electorale\n");
			printf("3) Supprimer une liste electorale\n"); 
			printf("4) Afficher les listes electorales\n");
			printf("0) Quitter\n");
			printf("Donner votre choix:");
			scanf("%d",&choix);
		}while(choix<0 || choix>4);
		switch(choix){
			case 1:
				printf("Donner l'id du liste:");
				scanf("%d",&listeElectorale.id_liste);
				printf("Orientation:");
				scanf("%s",listeElectorale.orientation);
				printf("1er candidat:");
				scanf("%d",&listeElectorale.candidats[0]);
				printf("2eme candidat:");
				scanf("%d",&listeElectorale.candidats[1]);
				printf("3eme candidat:");
				scanf("%d",&listeElectorale.candidats[2]);
				listeElectorale.nbVote=0;
				printf("Date de creation\n");
				printf("jour:");
				scanf("%d",&listeElectorale.dateDeCreation.jour);
				printf("mois:");
				scanf("%d",&listeElectorale.dateDeCreation.mois);
				printf("annee:");
				scanf("%d",&listeElectorale.dateDeCreation.annee);
				int resulat_ajouter=ajouterListeElectorale(listeElectorale);
				if(resulat_ajouter==0){
					printf("erreur \n");
				}
				else{
					printf("Ajout avec succes\n");
				}
				break;
			case 2:
				printf("Donner l'id du liste a modifier:");
				scanf("%d",&id_modifier);
				if(rechercheListeElectorale(id_modifier)==0){
					printf("liste introuvable\n");
				}
				else{
					printf("Orientation:");
					scanf("%s",listeElectoralemodifier.orientation);
					printf("1er candidat:");
					scanf("%d",&listeElectoralemodifier.candidats[0]);
					printf("2eme candidat:");
					scanf("%d",&listeElectoralemodifier.candidats[1]);
					printf("3eme candidat:");
					scanf("%d",&listeElectoralemodifier.candidats[2]);
					printf("Date de creation\n");
					printf("jour:");
					scanf("%d",&listeElectoralemodifier.dateDeCreation.jour);
					printf("mois:");
					scanf("%d",&listeElectoralemodifier.dateDeCreation.mois);
					printf("annee:");
					scanf("%d",&listeElectoralemodifier.dateDeCreation.annee);
					listeElectoralemodifier.id_liste=id_modifier;
					int resulat_modification=modifierListeElectorale(id_modifier,listeElectoralemodifier);
					if(resulat_modification==0){
						printf("erreur \n");
					}
					else{
						printf("Modification avec succes\n");
					}
				}
				break;
			case 3:
				printf("Donner l'id du liste a supprimer:");
				scanf("%d",&id_supprimer);
				if(rechercheListeElectorale(id_supprimer)==0){
					printf("liste introuvable\n");
				}
				else{
					int resulat_supprimer=supprimerListeElectorale(id_supprimer);
					if(resulat_supprimer==0){
						printf("erreur \n");
					}
					else{
						printf("Methode a supprimer avec succes\n");
					}
				}
				break;
			case 4:
				resultat_afficher=afficherListeElectorale();
				if(resultat_afficher==0){
						printf("erreur \n");
				}
				break;
		}
	}while(choix!=0);
	

	return 0;
}

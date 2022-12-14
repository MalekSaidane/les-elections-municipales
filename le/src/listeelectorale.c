#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>
#include "listeelectorale.h"
enum{
	EID,
	EORIENTATION,
	ECANDIDAT1,
	ECANDIDAT2,
	ECANDIDAT3,
	EVOTE,
	EJOUR,
	EMOIS,
	EANNEE,
	COLUMNS
};
int ajouterListeElectorale(ListeElectorale listeElectorale, char nomfichier[20]){
	FILE *f;
	f=fopen(nomfichier,"a+");
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
							0,
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
ListeElectorale rechercheListeElectorale(int id_recherche){

	ListeElectorale listeElectorale;
	FILE *f;
	f=fopen("listeelectorale.txt","r");
	if(f!=NULL){
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
				return listeElectorale;
		}
		fclose(f);
		listeElectorale.id_liste=-1;
		return listeElectorale;
	}
}
int afficherListeElectoraleTerminal(){
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
void afficherListeElectorale(char nom_ficher[20],GtkWidget *liste){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkListStore *store;
	GtkTreeIter iter;
	ListeElectorale listeElectorale;
	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Orientation",renderer,"text",EORIENTATION,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Candidat 1",renderer,"text",ECANDIDAT1,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Candidat 2",renderer,"text",ECANDIDAT2,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Candidat 3",renderer,"text",ECANDIDAT3,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Vote",renderer,"text",EVOTE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",EJOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",EMOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",EANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}

	store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
		
	FILE *f;
	f=fopen(nom_ficher,"r");
	if(f==NULL){
		return;
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
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,EID,listeElectorale.id_liste,
							EORIENTATION,listeElectorale.orientation,
							ECANDIDAT1,listeElectorale.candidats[0],
							ECANDIDAT2,listeElectorale.candidats[1],
							ECANDIDAT3,listeElectorale.candidats[2],
							EVOTE,listeElectorale.nbVote,
							EJOUR,listeElectorale.dateDeCreation.jour,
							EMOIS,listeElectorale.dateDeCreation.mois,
							EANNEE,listeElectorale.dateDeCreation.annee,-1);
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}
}


void triListeElectoraleParnbVote(){
	ListeElectorale listeElectorale,tmp;
	ListeElectorale tableau[100];
	int index=0,i,j,min;
	FILE *f,*f1;
	f=fopen("listeelectorale.txt","r");
	if(f==NULL){
		return;
	}
	else{
		//remplire tableau 
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
			tableau[index]=listeElectorale;
			index++;
		}
		fclose(f);
		//tri par selection
		
		for(i=0;i<index-1;i++){
			min=i;
			for(j=i+1;j<index;j++){
				if(tableau[min].nbVote>tableau[j].nbVote)
					min=j;
			}
			if(min!=i){
				tmp=tableau[i];
				tableau[i]=tableau[min];
				tableau[min]=tmp;
			}
		}
		f1=fopen("listeelectrolatriee.txt","w");
		if(f1==NULL)
			return;
		else{
			for(i=0;i<index;i++){
				fprintf(f1,"%d %s %d %d %d %d %d/%d/%d\n",
									tableau[i].id_liste,
									tableau[i].orientation,
									tableau[i].candidats[0],
									tableau[i].candidats[1],
									tableau[i].candidats[2],
									tableau[i].nbVote,
									tableau[i].dateDeCreation.jour,
									tableau[i].dateDeCreation.mois,
									tableau[i].dateDeCreation.annee);
			}
			fclose(f1);
		}
	}
}

void vote(int id_user,int id_liste){
	ListeElectorale l;
    user p;
    FILE * f=fopen("user.txt","r");
	FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
       while(fscanf(f,"%d %s %s %s %s %s %d %d %d %d %d\n",&p.id,p.nom,p.prenom,p.sexe,p.role,p.pwd,&p.numbv,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,&p.vote)!=EOF)
        {
            	if(p.id==id_user)
			fprintf(f2,"%d %s %s %s %s %s %d %d %d %d %d\n",p.id,p.nom,p.prenom,p.sexe,p.role,p.pwd,p.numbv,p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee,id_liste);
		else
			fprintf(f2,"%d %s %s %s %s %s %d %d %d %d %d\n",p.id,p.nom,p.prenom,p.sexe,p.role,p.pwd,p.numbv,p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee,p.vote);


        }
		if(id_liste>=1){
			l=rechercheListeElectorale(id_liste);
			if(l.id_liste!=-1){
				l.nbVote++;
				modifierListeElectorale(l.id_liste,l);
			}
		}	
		fclose(f);
		fclose(f2);
		remove("user.txt");
		rename("nouv.txt", "user.txt");
    }
	
}



























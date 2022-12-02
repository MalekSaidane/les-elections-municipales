#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "listeelectorale.h"
void
on_treeview_listeelecotrale_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	gint id;
	GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
		supprimerListeElectorale(id);
		afficherListeElectorale("listeelectorale.txt",treeview);
	}
}


void
on_buttonrefresh_listeelectorale_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	
	GtkWidget *treeview,*window;
	
	window=lookup_widget(objet_graphique,"interface_listeelectorale");
	

	treeview=lookup_widget(window,"treeview_listeelecotrale");
	
	afficherListeElectorale("listeelectorale.txt",treeview);
	
	
	
}


void
on_buttonajouter_listeelectorale_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	ListeElectorale listeelectorale;

	GtkWidget *id_liste,*orientation_liste,*candidat1_liste,*candidat2_liste,*candidat3_liste,*jour_liste,*mois_liste,*annee_liste;


	id_liste=lookup_widget(objet_graphique,"entryid_listeelectorale");
	orientation_liste=lookup_widget(objet_graphique,"comboboxorientation_listeelectorale");
	candidat1_liste=lookup_widget(objet_graphique,"entrycandidat1_listeelectorale");
	candidat2_liste=lookup_widget(objet_graphique,"entrycandidat2_listeelectorale");
	candidat3_liste=lookup_widget(objet_graphique,"entrycandidat3_listeelectorale");
	jour_liste=lookup_widget(objet_graphique,"spinbuttonjour_listeelectorale");
	mois_liste=lookup_widget(objet_graphique,"spinbuttonmois_listeelectorale");
	annee_liste=lookup_widget(objet_graphique,"spinbuttonannee_listeelectorale");
	 
	//listeelectorale.id_liste=(int)strtol(id, (char **)NULL, 10)
	listeelectorale.id_liste=atoi(gtk_entry_get_text(GTK_ENTRY(id_liste)));
	listeelectorale.candidats[0]=atoi(gtk_entry_get_text(GTK_ENTRY(candidat1_liste)));
	listeelectorale.candidats[1]=atoi(gtk_entry_get_text(GTK_ENTRY(candidat2_liste)));
	listeelectorale.candidats[2]=atoi(gtk_entry_get_text(GTK_ENTRY(candidat3_liste)));

	listeelectorale.dateDeCreation.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour_liste));
	listeelectorale.dateDeCreation.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois_liste));
	listeelectorale.dateDeCreation.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee_liste));

	strcpy(listeelectorale.orientation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(orientation_liste)));

	ajouterListeElectorale(listeelectorale);
}


void
on_buttonmodifier_listeelectorale_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	ListeElectorale listeelectorale;
	ListeElectorale l;
	char id[20];
	GtkWidget *id_liste,*orientation_liste,*candidat1_liste,*candidat2_liste,*candidat3_liste,*jour_liste,*mois_liste,*annee_liste;
	id_liste=lookup_widget(objet_graphique,"entryid_listeelectorale");
	orientation_liste=lookup_widget(objet_graphique,"comboboxorientation_listeelectorale");
	candidat1_liste=lookup_widget(objet_graphique,"entrycandidat1_listeelectorale");
	candidat2_liste=lookup_widget(objet_graphique,"entrycandidat2_listeelectorale");
	candidat3_liste=lookup_widget(objet_graphique,"entrycandidat3_listeelectorale");
	jour_liste=lookup_widget(objet_graphique,"spinbuttonjour_listeelectorale");
	mois_liste=lookup_widget(objet_graphique,"spinbuttonmois_listeelectorale");
	annee_liste=lookup_widget(objet_graphique,"spinbuttonannee_listeelectorale");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(id_liste))); 
	listeelectorale.id_liste=atoi(id);
	//listeelectorale.id_liste=(int)strtol(id, (char **)NULL, 10)
	listeelectorale.candidats[0]=atoi(gtk_entry_get_text(GTK_ENTRY(candidat1_liste)));
	listeelectorale.candidats[1]=atoi(gtk_entry_get_text(GTK_ENTRY(candidat2_liste)));
	listeelectorale.candidats[2]=atoi(gtk_entry_get_text(GTK_ENTRY(candidat3_liste)));
	listeelectorale.dateDeCreation.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour_liste));
	listeelectorale.dateDeCreation.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois_liste));
	listeelectorale.dateDeCreation.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee_liste));
	strcpy(listeelectorale.orientation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(orientation_liste)));
	l=rechercheListeElectorale(listeelectorale.id_liste);
	if(l.id_liste!=-1){
		modifierListeElectorale(listeelectorale.id_liste,listeelectorale);
	}
	
	
}


void
on_buttontri_listeelectorale_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	triListeElectoraleParnbVote();
	GtkWidget *treeview,*window;
	
	window=lookup_widget(objet_graphique,"interface_listeelectorale");
	

	treeview=lookup_widget(window,"treeview_listeelecotrale");
	
	afficherListeElectorale("listeelectrolatriee.txt",treeview);
	
}

int x=0;
void
on_buttongotovote_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *interface_vote;
	if(x<1)	
		vote(5,x);
	else{
		interface_vote=create_interface_vote();
		gtk_widget_show(interface_vote);
	}
		
}


void
on_radiobuttonvoteblanc_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		x=0;
}


void
on_radiobuttonpasdevote_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		x=-1;
}


void
on_radiobuttonvoteliste_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		x=1;
}


void
on_buttonvote_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *id_liste,*interface;
	id_liste=lookup_widget(objet_graphique,"entryidlistevote");
	vote(5,atoi(gtk_entry_get_text(GTK_ENTRY(id_liste))));
	interface=lookup_widget(objet_graphique,"interface_vote");
	gtk_widget_destroy(interface);
	
	
}


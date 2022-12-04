#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"bureau.h"
#include"bureau.c"


int choix=1;


void
on_ajout_bureau_vote_confirmer_clicked (GtkWidget *objet_graphique, gpointer         user_data)
{
GtkWidget* idbv;
GtkWidget* municipalite;
GtkWidget* idagent;
GtkWidget* capelec;
GtkWidget* capob1;
GtkWidget* capob2;
GtkWidget* capob3;
bv bureau;
int n=0;
char f[30];
char s[30];
int v;
int ss;
char msg[20];
int bn;



//

idbv=lookup_widget(objet_graphique,"ajout_bureau_vote_id_bv") ;
municipalite=lookup_widget(objet_graphique, "ajout_bureau_vote_municipalite");
idagent=lookup_widget(objet_graphique,"entry2");
capelec=lookup_widget(objet_graphique,"ajout_bureau_vote_cap_electeur");
capob1=lookup_widget(objet_graphique,"ajout_bureau_vote_1_ob");
capob2=lookup_widget(objet_graphique,"ajout_bureau_vote_2_ob");
capob3=lookup_widget(objet_graphique,"ajout_bureau_vote_3_ob");
//
strcpy(f,gtk_entry_get_text(GTK_ENTRY(idbv)));
v=atoi(f);
bureau.id_bv=v;
strcpy(bureau.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalite)));
strcpy(s,gtk_entry_get_text(GTK_ENTRY(idagent)));
ss=atoi(s);
bureau.id_agent=ss;

//strcpy(bureau.id_agent,gtk_combo_box_get_active_text(GTK_COMBO_BOX(idagent)));

bureau.cap_electeur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capelec));



bureau.cap_observateur=choix;





//
n=ajout("bis.txt",bureau);



}


void
on_ajout_bureau_vote_annuler_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *window_ajout;
GtkWidget *window_interface_b;


window_ajout=lookup_widget(button,"Ajout_bureau_vote");
window_interface_b=lookup_widget(button,"window_interface_bv");

window_interface_b=create_window_interface_bv ();
gtk_widget_show(window_interface_b);

gtk_widget_hide(window_ajout);



}











void
on_ajout_bureau_vote_1_ob_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=1;
}


void
on_ajout_bureau_vote_2_ob_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=2;
}


void
on_ajout_bureau_vote_3_ob_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=3;
}

// boutton affichage de bureau de vote
/*
void
on_button_affihcher_bv_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeviewbv,*window;
window=lookup_widget(button,"window_interface_bv");
treeviewbv=lookup_widget(window,"treeview2_admin_gbv");
afficher_bv("bureau.txt",treeviewbv);

}*/


void
on_button7_admin_gbv_modifier_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button2_admin_gbv_spprimer_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button3_admin_gbv_recherche_clicked (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button6_actualiser_bv_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}













void
on_button6_admin_gbv_creer_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_ajout;
GtkWidget *window_interface_b;


window_ajout=lookup_widget(button,"Ajout_bureau_vote");
window_interface_b=lookup_widget(button,"window_interface_bv");



window_ajout=create_Ajout_bureau_vote ();
gtk_widget_show(window_ajout);
gtk_widget_hide(window_interface_b);
}






void
on_button_affihcher_bv_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview,*window;
window=lookup_widget(button,"window_interface_bv");
gtk_widget_destroy(window);
window=lookup_widget(button,"window_interface_bv");
window=create_window_interface_bv ();
gtk_widget_show(window);
treeview=lookup_widget(window,"treeview2_admin_gbv");

//gtk_widget_show(window);
//supprimer(5);
afficher_bv(treeview);


}


void
on_treeview2_admin_gbv_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
guint id;

bv bur;
GtkTreeIter iter;


GtkTreeModel *model=gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);

/*bur.id_bv=idbv;
strcpy(bur.municipalite,municipalite);
bur.id_agent=idagent;
bur.cap_electeur=capelec;
bur.cap_observateur=capob;
*/


/*bur.id_bv=*idbv;
strcmp(bur.municipalite,municipalite);
bur.id_agent=*idagent;
bur.cap_electeur=*capelec;
bur.cap_observateur=*capob;
//supprimer(bur.id_bv);*/
//supprimer(id);
afficher_bv(treeview);

}}


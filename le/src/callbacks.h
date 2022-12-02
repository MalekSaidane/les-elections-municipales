#include <gtk/gtk.h>


void
on_treeview_listeelecotrale_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonrefresh_listeelectorale_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonajouter_listeelectorale_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonmodifier_listeelectorale_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttontri_listeelectorale_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttongotovote_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonvoteblanc_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonpasdevote_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonvoteliste_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_buttonvote_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

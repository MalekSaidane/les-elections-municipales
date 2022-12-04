#include <gtk/gtk.h>
#ifndef BUREAU_H_INCLUDED
#define BUREAU_H_INCLUDED




typedef struct  {
int id_bv;
char municipalite[20];
int  id_agent;

int cap_electeur;
int cap_observateur;

}bv;

typedef struct {
int jour;
int mois;
int annee;
}Date;
typedef struct{
int id;
char nom [20];
char prenom[20];
char role [20];
char pwd[20];
int numbv;
Date date_de_naissance;
int vote;
}user;

typedef struct {
char nom[20];
char prenom[20];
int id;
char municipalite[20];
char nationalite[20];
char appartence[20];
char sexe[20];

}g_observateurs;

void taux (char *user ,float *tn,float *te);
int ajout(char *filename,bv r1);
int modifier (char *filename,int id ,bv neww);
//int supprimer (char *filename,int id);
int supprimer (int id);
bv recherche (char *filename,int id);
//void afficher_bv(GtkWidger *liste);
int nbe(char *filename, int id);
int cob(int choix,char msg[]);
void afficher_bv(GtkWidget *liste);
//afficher_bv(GtkWidget *liste,char file[20]);
//void afficher_bv(char nom_ficher[20],GtkWidget *liste);
#endif

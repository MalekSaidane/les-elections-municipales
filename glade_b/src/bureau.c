#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include<gtk/gtk.h>
#include"bureau.h"
#include "callbacks.h"

/*typedef struct ebv{
int  EID_BV;
char EMUNICIPALITE[20];
int EID_AGENT;
int ECAP_ELEC;
int ECAP_OBS;
*/

enum{
EID_BV,
EMUNICIPALITE,
EID_AGENT,
ECAP_ELEC,
ECAP_OBS,
COLUMNS


};


int ajout(char *filename,bv r1){
GtkWidget *pQuestion;
gpointer user_data;
int b=0;
FILE *f=fopen(filename,"a");

if(f!=NULL){
fprintf(f,"%d %s %d %d %d\n",r1.id_bv,r1.municipalite,r1.id_agent,r1.cap_electeur,r1.cap_observateur);
//
pQuestion=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,b==0?GTK_MESSAGE_INFO:GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,b==0?"Utilisateur ajouté avec succès !":"Utilisateur déja existant !");
switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pQuestion);
	break;
	}
//


fclose(f);
return 1;
}
else
return 0;
}

/////////////////////////////////////
///////////////////////////////////////
//////////////////////////////////////////
//debut 
/*
void afficher_bv(GtkWidget *liste){


GtkCellRenderer *renderer;
GtkTreeViewColumn * column;
GtkTreeIter iter;
GtkListStore *store;




bv bur;

store=NULL;
store=gtk_tree_view_get_model(liste);
gint idb;
gchar municipalite[20];
gint iga;
gint cape;
gint capo;

FILE *f;

//store=gtk_tree_view_get_model(liste);

if(store==NULL){

//id bureau
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("id bureau",renderer,"text",EID_BV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


//municipalite
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("municipalite",renderer,"text",EMUNICIPALITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


//id_agent

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("id agent",renderer,"text",EID_AGENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

//capacité electeurs
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("capacite electeurs",renderer,"text",ECAP_ELEC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


//capacité observateurs
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("capacite observateurs",renderer,"text",ECAP_OBS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

//
store=gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

//FILE *f=fopen(nom_ficher,"r");
//FILE *f;
//
f=fopen("bis.txt","r");

if(f==NULL){
return;}

else{

f=fopen("bis.txt","a+");
while(fscanf(f,"%d %s %d %d %d",&(bur.id_bv),bur.municipalite,&(bur.id_agent),&(bur.cap_electeur),&bur.cap_observateur)!=EOF)
{
//
sprintf(idb,bur.id_bv);
sprintf(municipalite,bur.municipalite);
sprintf(iga,bur.id_agent);
sprintf(cape,bur.cap_electeur);
sprintf(capo,bur.cap_observateur);
//
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EID_BV,bur.id_bv,EMUNICIPALITE,municipalite,EID_AGENT,bur.id_agent,ECAP_ELEC,bur.cap_electeur,ECAP_OBS,bur.cap_observateur,-1);

}
fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
}
}

*/
//fin
/*
int modifier (char *filename,int id ,bv neww){
bv r1;
int tr=0;
FILE *f=fopen(filename,"r");
FILE *f2=fopen("new.txt","w");

if(f!= NULL && f2!=NULL){
while(fscanf(f,"%d %s %d %d %d",&r1.id_bv,r1.municipalite,&r1.id_agent,&r1.cap_electeur,&r1.cap_observateur)!=EOF){

if(id == r1.id_bv){
fprintf(f2,"%d %s %d %d %d\n",neww.id_bv,neww.municipalite,neww.id_agent,neww.cap_electeur,neww.cap_observateur);
tr=1;
}
else {
fprintf(f2,"%d %s %d %d %d\n",r1.id_bv,r1.municipalite,r1.id_agent,r1.cap_electeur,r1.cap_observateur);

tr=0;
}
}
fclose(f);
fclose(f2);
remove(filename);
rename("new.txt",filename);
return tr;
}
}
//////////////////////////////////////////
///////////////////////////////////////////
//////////////////////////////////////////////
*/
int supprimer (int id){

int tr=0;
bv b;

FILE *f=fopen("bis.txt","r");
FILE *f2=fopen("new.txt","w");

if (f!=NULL && f2!=NULL){
while(fscanf(f,"%d %s %d %d %d",&b.id_bv,b.municipalite,&b.id_agent,&b.cap_electeur,&b.cap_observateur)!=EOF){

if(id==b.id_bv){
 tr=1;
}

else{
fprintf(f2,"%d %s %d %d %d\n",b.id_bv,b.municipalite,b.id_agent,b.cap_electeur,b.cap_observateur);
}
}
fclose(f);
fclose(f2);
remove("bis.txt");


rename("new.txt","bis.txt");
return tr;
}



}


//////////////////////////////////////
/////////////////////////////////////
////////////////////////////////////////

 bv recherche (char *filename,int id){
int tr=0;
bv b;

FILE *f =fopen(filename,"r");

if(f!=NULL){

while(tr==0 && fscanf(f,"%d %s %d %d %d",&b.id_bv,b.municipalite,&b.id_agent,&b.cap_electeur,&b.cap_observateur)!=EOF){

if(id==b.id_bv){

tr=1;
}
}
}
fclose(f);
if(tr==0){
b.id_bv=-1;
}

return b;





}

///////////////
///////////////
//////////////////////////////////////
/*

void afficher_bv(GtkWidget *liste){
GtkCellRender *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

int id_bv;
char municipalite[20];
int  id_agent;
int cap_electeur;
int cap_observateur;
store=NULL;

if(store==NULL){

//id bureau
render =gtk_cell_renderer_text_new();
column = gtk_tree_view_new_with_attributes("id bureau",renderer,"text",EID_BV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


//municipalite
render =gtk_cell_renderer_text_new();
column = gtk_tree_view_new_with_attributes("municipalite",renderer,"text",EMUNICIPALITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


//id_agent

render =gtk_cell_renderer_text_new();
column = gtk_tree_view_new_with_attributes("id agent",renderer,"text",EID_AGENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

//capacité electeurs
render =gtk_cell_renderer_text_new();
column = gtk_tree_view_new_with_attributes("capacite electeurs",renderer,"text",ECAP_ELEC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


//capacité observateurs
render =gtk_cell_renderer_text_new();
column = gtk_tree_view_new_with_attributes("capacite observateurs",renderer,"text",ECAP_OBS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *f=fopen("bureau.txt","r");

if(f!=NULL){

FILE *f=fopen("bureau.txt","a");

while(fscanf(f,"%d %s %d %d %d",&r1.id_bv,r1.municipalite,&r1.id_agent,&r1.cap_electeur,&r1.cap_observateur)!=EOF){
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EID_BV,EMUNICIPALITE,EID_AGENT,ECAP_ELEC,ECAP_OBS,-1);

}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store)

}





}
}










///////////////////////////////////////
///////////////////////////////////////
/////////////////////////////////////////
int nbe(char *filename, int id){
    int n=0;
   FILE *f =fopen(filename,"r");
   user p;
   
   if(f!= NULL){
       
    while(fscanf(f,"%d %s %s %s %s %d %d %d %d %d\n",&p.id,p.nom,p.prenom,p.role,p.pwd,&p.numbv,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,&p.vote)!=EOF){
   
  
    if((p.numbv==id) &&(strcmp(p.role,"electeur")==0)){
        n+=1;
    }

   }}
    return n;

}
///////////////////////////////////////
/////////////////////////////////////////
///////////////////////////////////////////



void taux (char *observateur ,float *tn,float *te){
    int tun=0;
    int etr=0;
    FILE *f=fopen("observateur.txt","r");
    g_observateurs ob;
    if(f!=NULL){
        while(fscanf(f,"%s %s %d %s %s %s %s",ob.nom,ob.prenom,&ob.id,ob.municipalite,ob.nationalite,ob.appartence,ob.sexe)!= EOF){
            if(strcmp(ob.nationalite,"tunisien")==0){
                tun+=1;
            }
            else if(strcmp(ob.nationalite,"etrange")==0){
                etr+=1;


            }

        }

    }


printf(" le nombre des tunisiens est %d\n",tun);
printf("le nombre des etranges est %d\n",etr);
*tn=(float)tun/(tun+etr);
*te=(float)etr/(tun+etr);

}
*/

void afficher_bv(GtkWidget *liste){

bv p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar municipalite[20];
FILE *f;
store=gtk_tree_view_get_model(liste);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" ID Bureau de vote", renderer,"text",EID_BV, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Municipalite", renderer,"text",EMUNICIPALITE, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ID Agent", renderer,"text",EID_AGENT, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_resizable(column,TRUE);
gtk_tree_view_column_set_expand(column,TRUE);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Capacité electeur", renderer,"text",ECAP_ELEC, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Capacité observateur", renderer,"text",ECAP_OBS, NULL);
if (store==NULL)
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
gtk_tree_view_column_set_expand(column,TRUE);




store=gtk_list_store_new(COLUMNS, G_TYPE_UINT, G_TYPE_STRING, G_TYPE_UINT, G_TYPE_INT, G_TYPE_UINT);

f=fopen("bis.txt","r");
if(f!=NULL)
{ f = fopen("bis.txt","a+");
		while(fscanf(f,"%d %s %d %d %d",&p.id_bv,p.municipalite,&p.id_agent,&p.cap_electeur,&p.cap_observateur)!=EOF)
	{
sprintf(municipalite,"%s",p.municipalite);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EID_BV,p.id_bv,EMUNICIPALITE,municipalite,EID_AGENT,p.id_agent,ECAP_ELEC,p.cap_electeur,ECAP_OBS,p.cap_observateur-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}

else{
f=fopen("bis.txt","r");
if(f!=NULL)
{ f = fopen("bis.txt","a+");
		while(fscanf(f,"%d %s %d %d %d")!=EOF)
	{

sprintf(municipalite,"%s",p.municipalite);

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EID_BV,p.id_bv,EMUNICIPALITE,municipalite,EID_AGENT,p.id_agent,ECAP_ELEC,p.cap_electeur,ECAP_OBS,p.cap_observateur-1);

	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}}
/*
gtk_tree_view_set_reorderable(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_search_column(GTK_TREE_VIEW(liste),0);
gtk_tree_view_set_enable_tree_lines(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_grid_lines(GTK_TREE_VIEW(liste),GTK_TREE_VIEW_GRID_LINES_BOTH);
}

}
*/

 

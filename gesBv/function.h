#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED


typedef struct  {
int id_bv;
char municipalite[20];
int  id_agent;
int cap_electeur;
int cap_observateur;

}bv;
int ajout(char *filename,bv r1);
int modifier (char *filename,int id ,bv neww);
int supprimer (char *filename,int id);
bv recherche (char *filename,int id);
#endif

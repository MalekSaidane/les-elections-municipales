#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED


typedef struct
{
int jour;
int mois;
int annee;
}Date;
typedef struct{
char nom [10];
char prenom [10];
char sexe [10];
int numbv;
char role[50];
Date date_de_naissance;
int id;
char pwd[50];
int vote;
int id_list;
}user;
int ajouter(char * filename, user p );
int modifier( char * filename, int id,user nouv );
void creation_utilisateur(user*e);
int supprimer(char * filename, int id);
user chercher(char * filename, int id);
float agemoyen(char * fichierusers);
float TPE( char * filename);

#endif 





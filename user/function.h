#ifndef FUNCTION_H_
#define FUNCTION_H_

typedef struct
{
int jour;
int mois;
int annee;
}Date;
typedef struct{
char nom [10];
char prenom [10];
int numbv;
char role[50];
Date date_de_naissance;
int id;
char pwd[50];
}user;
int ajouter(char * filename, user p );
int modifier( char * filename, int id,user nouv );
int supprimer(char * filename, int id);
int supprimer(char * filename, int id);
user chercher(char * filename, int id);

#endif


#ifndef FONCTION_H_
#define FONCTION_H_

#include <stdio.h>
typedef struct {
int jours;
int mois;
int annee;
}Date; 


typedef struct  {

int ID_bv;
char governement[20];
char municipalite[20];
int nbr_agents;
int ID_agents [3];
int nbr_observateurs;
int ID_observateurs[3];
Date  date_creation;
}bv;
#endif

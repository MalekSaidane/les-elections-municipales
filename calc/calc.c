#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int nbe(char *filename , int id){
    int n=0;
   FILE *f =fopen(filename,"r");
   user p;
   if(f != NULL){
    while(fscanf(f,"%d %s %s %s %s %d %d %d %d\n",&p.id,p.nom,p.prenom,p.role,p.pwd,&p.numbv,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee)!=EOF)){

    if(p.idbv==id){
     if(strcmp("electeur",p.role)==0){
        n+=1;
    }}

   }}
    return n;

}





void taux (char *user ,float *tn,float *te){
    int tun=0;
    int etr=0;
    FILE *f=fopen("observateur.txt","r");
    g_observateurs ob;
    if(f!=NULL){
        while(fscanf(f,"%s %s %s %s %s %s %s ",ob.nom,ob.prenom,ob.id,ob.municipalite,ob.nationalite,ob.appartence,ob.sexe)!= EOF){
            if(strcmp(ob.nationalite,"tunisien")==0){
                tun+=1;
            }
            else if(strcmp(ob.nationalite,"etrange")==0){
                etr+=1;


            }

        }

    }

*tn=(float)tun/(tun+etr);
*te=(float)etr(tun/etr);

}




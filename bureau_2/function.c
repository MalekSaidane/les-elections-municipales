#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"function.h"


int ajout(char *filename,bv r1){

FILE *f=fopen(filename,"a");
if(f!=NULL){
fprintf(f,"%d %s %d %d %d\n",r1.id_bv,r1.municipalite,r1.id_agent,r1.cap_electeur,r1.cap_observateur);
fclose(f);
return 1;
}
else
return 0;
}


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

int supprimer (char *filename,int id){

int tr=0;
bv b;

FILE *f=fopen(filename,"r");
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
remove(filename);


rename("new.txt",filename);
return tr;
}



}


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
int nbe(char *filename, int id){
    int n=0;
   FILE *f =fopen(filename,"r");
   user p;
   
   if(f!= NULL){
       
    while(fscanf(f,"%d %s %s %s %s %d %d %d %d\n",&p.id,p.nom,p.prenom,p.role,p.pwd,&p.numbv,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee)!=EOF){
   
  
    if((p.numbv==id) &&(strcmp(p.role,"electeur")==0)){
        n+=1;
    }

   }}
    return n;

}
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
printf("id est %d",ob.id);

printf("tun %d\n",tun);
printf("etr %d\n",etr);
*tn=(float)tun/(tun+etr);
*te=(float)etr/(tun+etr);

}



 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "function.h"

int main(){

char ch [5];
bv b1;
bv b2;


do{
printf("pour l ajout print aj \npour la suppression print supp \npour la modification print mod\npour le recherche print rech\n");
scanf("%s",ch) ;

}while(((strcmp(ch,"mod"))!=0)&&((strcmp(ch,"rech")!=0))&&(strcmp(ch,"supp")!=0)&&(strcmp(ch,"aj")!=0));



if((strcmp(ch,"aj"))==0){
printf("entrer l id de bureau de vote\n");
scanf("%d",&b1.id_bv);
printf("entrer la  municipalité\n");
scanf("%s",b1.municipalite);
printf("entrer l id de l agent\n");
scanf("%d",&b1.id_agent);
printf("entrer la capacite d electeurs\n");
scanf("%d",&b1.cap_electeur);
printf("entrer la capacite d observateurs\n");
scanf("%d",&b1.cap_observateur);


int x=ajout("listebv.txt",b1);
if(x==1){
printf("ajoutee avec succes");
}
else{
printf("echec ajout ");
}
}


else if((strcmp(ch,"mod"))==0){
int m;
printf("entrer l id de bureau a modifier");
scanf("%d",&m);
printf("entrer le nouveau id de bureau de vote\n");
scanf("%d",&b2.id_bv);
printf("entrer la nouvelle municipalité\n");
scanf("%s",b2.municipalite);
printf("entrer l nouveau id de l agent\n");
scanf("%d",&b2.id_agent);
printf("entrer la nouvelle capacite d electeurs\n");
scanf("%d",&b2.cap_electeur);
printf("entrer la nouvelle capacite d observateurs\n");
scanf("%d",&b2.cap_observateur);


int a=modifier("listebv.txt",m,b2);
printf("%d",a);
if(a==1){
printf(" \n modif avec sucees");
}
else {
printf(" \n echec de modification"); 

}
}

else if((strcmp(ch,"supp"))==0){
int e;
printf("entrer l id a supprimer");
scanf("%d",&e);
int b=supprimer ("listebv.txt",e);
if(b==1){
printf(" \n supprime effectuer \n");

}
else{
printf("\n echec de supprimer");

}}


 if((strcmp(ch,"rech"))==0){
bv c;
int e;
printf("entrer l id de bureau a rechercher");
scanf("%d",&e);

 c = recherche ("listebv.txt",e);
if(c.id_bv==-1){
printf("introuvable");
}
else{
printf("%d %s %d %d %d",c.id_bv,c.municipalite,c.id_agent,c.cap_electeur,c.cap_observateur);
}
}

return 0;



}

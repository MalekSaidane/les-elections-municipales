#include<stdio.h>
#include<stdlib.h>
#include "function.h"

int main(){
bv b1={3,"manouba",1,2,3},b2={5,"tunis",5,6,7},b3;

int x=ajout("listebv.txt",b1);
if(x==1){
printf("ajoutee avec succes");
}
else{
printf("ajout echec");
}

int a=modifier("listebv.txt",3,b2);
if(a==1){
printf(" \n modif avec sucees");
}
else {
printf(" \n echec de modification"); 

}


/*int b=supprimer ("listebv.txt",5);
if(b==1){
printf(" \n supprime effectuer \n");

}
else{
printf("\n echec de supprimer");

}
*/
bv c = recherche ("listebv.txt",5);
if(c.id_bv==-1){
printf("introuvable");
}
return 0;



}

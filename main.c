#include <stdio.h>
#include <stdlib.h>
#include "parking.h"
#include <string.h>
void main()
{
int c;
parking p;
do
{
printf("donner votre choix\n");
printf("1-ajouter un parking\n");
printf("2-afficher la liste des parking\n");
printf("3-modifier un parking\n");
printf("4-supp un parking\n");
printf("5-Affecter un agent a un parking\n");
scanf("%d",&c);

switch(c)
{
case 1:
ajouter_parking("parkings.txt");
break;
case 2:
afficher_parking("parkings.txt");
break;
case 3:
modifier_parking("parkings.txt","t_parkings.txt");
break;
case 4:
supp_parking("parkings.txt","t_parkings.txt");
break;
case 5:
affecter_agent("agents.txt","t_agents.txt");
default:
printf("choix invalide \n");
break;
}
}while(c>1||c<=5);
}

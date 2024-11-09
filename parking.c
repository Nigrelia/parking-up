#include <stdio.h>
#include <stdlib.h>
#include "parking.h"
#include <string.h>
//saisie
void saisir_parking(parking *p)
{

printf("donner l'id du parking\n");
scanf("%s",p->id_parking);

printf("donner le prix\n");
scanf("%f",&p->prix);

printf("donner le nombre de place du parking\n");
scanf("%d",&p->nbr_place);

printf("donner la localisation du parking\n");
scanf("%s",p->loc_parking);
}




//ajout
void ajouter_parking(char *parkings)
{
parking p;
int trouve=0;
FILE *f=fopen(parkings,"a+");
if(f==NULL)
{
printf("erreur d'ouverture de fichier \n");
return;
}
parking p1;
saisir_parking(&p1);
while(fscanf(f,"%s %f %d %s \n",p.id_parking,&p.prix,&p.nbr_place,p.loc_parking)!=EOF)
{
if(strcmp(p1.id_parking,p.id_parking)==0)
{
	trouve=1;
	break;
}
}


if(trouve==1)
{
printf("l'id deja existe donner saisir a nouveau \n");
}


else
{
fprintf(f,"%s %f %d %s \n",p1.id_parking,p1.prix,p1.nbr_place,p1.loc_parking);
printf("DONE\n");
}

fclose(f);

}



//affichage
void afficher_parking(char *parkings)
{
parking p;
FILE *f=fopen(parkings,"r");
if(f==NULL)
{
printf("erreur d'ouverture de fichier \n");
return;
}
while(fscanf(f,"%s %f %d %s \n",p.id_parking,&p.prix,&p.nbr_place,p.loc_parking)!=EOF)
{
printf("%s %.2f %d %s \n",p.id_parking,p.prix,p.nbr_place,p.loc_parking);
}

}


//modification
void modifier_parking(char *parkings,char *t_parkings)
{
char  x [20];
parking p;
int c;
int trouve=0;
FILE *f=fopen(parkings,"r");
if(f==NULL)
{
printf("erreur d'ouverture de fichier \n");
return;
}
FILE *f1=fopen(t_parkings,"w");
if(f==NULL)
{
printf("erreur d'ouverture de fichier \n");
return;
}
printf("donner l'id a modifier\n");
scanf("%s",x);
while(fscanf(f,"%s %f %d %s \n",p.id_parking,&p.prix,&p.nbr_place,p.loc_parking)!=EOF)
{

if(strcmp(x,p.id_parking)==0)
{
trouve=1;
do{
printf("donner le champs a modifier \n");
printf("1 - prix\n");
printf("2 - nombre de place\n");
printf("3 - localisation\n");
scanf("%d",&c);
}while(c<1||c>3);
switch(c)
{
case 1:
printf("donner le nouveau prix\n");
scanf("%f",&p.prix);
break;
case 2:
printf("donner le nouveau nbr place\n");
scanf("%d",&p.nbr_place);
break;
case 3:
printf("donner le nouveau loc\n");
scanf("%s",p.loc_parking);
break;
}
}

fprintf(f1,"%s %f %d %s \n",p.id_parking,p.prix,p.nbr_place,p.loc_parking);
}

	fclose(f);
		fclose(f1);
if(trouve==0)
{
printf("l'id n'existe pas \n");
remove(t_parkings);
}
else
{
remove(parkings);
rename(t_parkings,parkings);
printf("done\n");
}
}


//supp
void supp_parking(char *parkings,char *t_parkings)
{
char x[20];
parking p;
FILE *f=fopen(parkings,"r");
if(f==NULL)
{
printf("erreur d'ouverture de fichier \n");
return;
}
FILE *f1=fopen(t_parkings,"w");
if(f==NULL)
{
printf("erreur d'ouverture de fichier \n");
return;
}
printf("donner l'id a modifier\n");
scanf("%s",x);
while(fscanf(f,"%s %f %d %s ",p.id_parking,&p.prix,&p.nbr_place,p.loc_parking)!=EOF)
{
if(strcmp(x,p.id_parking)!=0)
{
fprintf(f1,"%s %f %d %s \n",p.id_parking,p.prix,p.nbr_place,p.loc_parking);
}
}
		fclose(f);
		fclose(f1);
remove(parkings);
rename(t_parkings,parkings);
printf("done\n");
}

//affecter
void affecter_agent(char *agents,char*t_agents)
{
char a1[20],p[20];
FILE *f=fopen(agents,"r");
if(f==NULL)
{
printf("erreur d'ouverture de fichier \n");
return;
}
FILE *f1=fopen(t_agents,"w");
if(f==NULL)
{
printf("erreur d'ouverture de fichier \n");
return;
}
printf("donner l ID de l agent a affecter \n");
scanf("%s",a1);
printf("donner l ID de parking a affecter \n");
scanf("%s",p);
agent a;
while (fscanf(f, "%s %s %s %s %f %s %s %s %s", a.id_agent, a.nom_agent, a.prenom_agent,a.sexe_agent, &a.sal_agent, a.type_contact, a.contact,a.moyen_agent,a.park) !=EOF) 
{
if(strcmp(a1,a.id_agent)==0)
{
strcpy(a.park,p);
}
fprintf(f1, "%s %s %s %s %.2f %s %s %s %s \n", a.id_agent, a.nom_agent, a.prenom_agent, a.sexe_agent, a.sal_agent, a.type_contact, a.contact,a.moyen_agent,a.park);
}
fclose(f);
fclose(f1);
remove(agents);
rename(t_agents,agents);

}


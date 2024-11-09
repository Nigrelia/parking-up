#ifndef PARKING_H_INCLUDED
#define PARKING_H_INCLUDED


typedef struct
{
char id_parking[50];
float prix;
int nbr_place;
char loc_parking[50];
}parking;

typedef struct
{

char id_agent[20];
char nom_agent[20];
char prenom_agent[20];
char sexe_agent[10];
float sal_agent;
char type_contact[20];
char contact[50];
char moyen_agent[20];
char park[20];

} agent ;


void saisir_parking(parking *p);
void ajouter_parking(char *parkings);
void afficher_parking(char *parkings);
void modifier_parking(char *parkings,char *t_parkings);
void supp_parking(char *parkings,char *t_parkings);
void affecter_agent(char *agents,char*t_agents);







#endif 

#ifndef SYSTEMEREVENUSEVENEMENTS
#define SYSTEMEREVENUSEVENEMENTS
#define NOMBRE_DE_VILLES   27


float cout_au_hasard();
char* nom_au_hasard();
int prix_evenement_aleatoire(int n);
char* evenement_aleatoire(int n);
char* entreprise();
int prix_contrat( int a);
void init_random ();
int int_random (void);
void tirage_des_contracts(int nb_contract, char *liste_entreprise[], int *revenu_de_contr, int *km, int * destination, int emplacement, int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES]);
void gestion_evenement_aleatoire(float *pointeur_du_capital);
#endif

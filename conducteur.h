#ifndef CONDUCTEUR_H
#define CONDUCTEUR_H
#define NOMBRE_DE_VILLES   16
struct conducteur {
int id;
int position;
int compteur_km;
float cout_au_km;
int jour_de_repos;
char nom[30];
};

int calcule_repos(int comp);
struct conducteur init_repos(struct conducteur cpt);
struct conducteur soustraction_par_tour_du_repos(struct conducteur cpt); 
struct conducteur deplacement(struct conducteur conducteur_a_deplacer, int id_arrivee, int deplacement_en_km);
struct conducteur reset_compteur (struct conducteur cpt);
int calcule_cout (struct conducteur cpt);
struct conducteur ville_aleatoire (struct conducteur cpt,int nombre_ville);
int djistra(int matrice[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES], int id_depart, int id_arrive);

#endif

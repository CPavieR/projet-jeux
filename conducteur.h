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
struct conducteur deplacement(struct conducteur conducteur_a_deplacer, int id_arrivee, int deplacement_en_km, float* pointeur_du_capital);
struct conducteur reset_compteur (struct conducteur cpt);
float calcule_cout (int km, float coutKm);
struct conducteur ville_aleatoire (struct conducteur cpt,int nombre_ville);

#endif

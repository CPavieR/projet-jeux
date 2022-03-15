#include <stdio.h>
#include <stdlib.h>
#include "conducteur.h"
#include "systemeRevenusEvenements.h"

// initalisation d'une nouvelle structure, cette structure peut avoir à des changements dans le future.
// Pour l'instant cette structure possède un id, une position dans le graphe, un compteur de kilomètres et le cout au KM du
// conducteur. J'ai essayé de compiler avec une chaine de caractère (pour un nom) mais la chaine de char empêchait la compilation (elle est en commentaire),
// sinon le structure fonctionne.

/* Calcule le nombre de jour de repos
Entrée : un entier comp, nombre de KM effectué par le conducteur pour une mission
Sortie : un entier repos, nombre de jours de repos accordés
*/
int calcule_repos(int comp)
{
    int repos = comp / 100;
    return repos;
}

// Initialise le nombre de jour de repos sur conducteur
/*struct conducteur init_repos(struct conducteur cpt)
    {
        cpt.jour_de_repos = calcule_repos(cpt);
        return cpt;
    }*/

/* Permet de soustraire le nombre de jour de repos du conducteur (on l'utilise au début de chaque tour)
Entrée/sortie : une structure conducteur cpt
*/
struct conducteur soustraction_par_tour_du_repos(struct conducteur cpt)
{
    cpt.jour_de_repos = cpt.jour_de_repos - 1;
    return cpt;
};

/* cette fonction permet de déplacer le conducteur dans le graphe, attention cette fonction vérifie si elle peut
faire le déplacement. Il faudra aussi rajouter une fonction afin de prévoir les déplacements à faire. 
Entrée : un conducteur (conducteur_a_deplacer), id de la ville d'arrivée (id_arrivee), nombre de KM requis (deplacement_en_km)
et le capital (pointeur_du_capital)
Sortie : la structure conducteur avec modification de son compteur, nouvelle position, nouveau nombre de jour de repos. Dans le cas où 
le conducteur avait encore des jours, aucune modification n'est faite. 
*/
struct conducteur deplacement(struct conducteur conducteur_a_deplacer, int id_arrivee, int deplacement_en_km, float *pointeur_du_capital) // Fonction operationnel
{                                                                                                                                         // on incrémente le compteur de KM vers l'endroit où on va faire le déplacement
    if (conducteur_a_deplacer.jour_de_repos != 0)
    {
        return conducteur_a_deplacer;
    }
    conducteur_a_deplacer.compteur_km = conducteur_a_deplacer.compteur_km + deplacement_en_km;
    // on fait le déplacemnt
    conducteur_a_deplacer.position = id_arrivee;
    int jour_de_rep = calcule_repos(deplacement_en_km);
    printf("NB JOUR DE REPOS : %d", calcule_repos(deplacement_en_km));
    conducteur_a_deplacer.jour_de_repos = jour_de_rep;
    printf("cout conduc :%f\n", conducteur_a_deplacer.cout_au_km);
    *pointeur_du_capital = *pointeur_du_capital - calcule_cout(deplacement_en_km, conducteur_a_deplacer.cout_au_km);
    printf("%f\n", calcule_cout(deplacement_en_km, conducteur_a_deplacer.cout_au_km));

    return (conducteur_a_deplacer); // on retourne la struct aprés le déplacement
}

/* Fonction basique qui reset le compteur de KM
Entrée/sortie : une structure conducteur cpt
*/
struct conducteur reset_compteur(struct conducteur cpt) // Fonction operationnel
{
    cpt.compteur_km = 0; // Orandn réinitialise simplement de compteur en le mettant à 0
    return cpt;          // on retourne de résultat
};

/* Permet de calculer le cout du compteur de KM du conducteur
Entrée : le nombre de km effectué (un entier km), le cout par KM (un float coutKm) 
*/
float calcule_cout(int km, float coutKm) // Fonction operationnel
{
    return km * coutKm; // on retoure simplement le cout au KM fois le nombre de KM
};

// Cette Fonction permet de générer des nombres aléatoire grace à l'import de la bibliothèque stdlib.h
// Cette fonction est utile pour la génération/initialisation alétoire de conducteur
// Nombre ville est le nombre exact de ville (et non le nombre de ville-1 comme si on était dans une liste)
struct conducteur ville_aleatoire(struct conducteur cpt, int nombre_ville) // Fonction operationnel
{
    int nombre = int_random() % nombre_ville + 1; // on génère un nombre entre 0 et le nombre de villes, si il y a 4 villes l'intervalle sera [0,3]
    cpt.position = nombre;                        // change la position dans la structure concernée
    return cpt;                                   // on retourne notre résulat
};

// int trajet_un_hop(int matrice[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES], int id_depart, int id_arrive)
/**
*
*
*
{

}
*/

/*
int main()//fonction main qui permet d'éffectuer les tests
{
    int ma_matrice_test[4][4] = {{1,6,8,4},{2,6,4,9},{8,5,1,6},{7,9,4,1}};//initialisatoin d'une matrice en 4*4
    struct conducteur cfgh ;//initialisation d'une struct conducteur
    cfgh.id = 0;
    cfgh.position=0;
    cfgh.compteur_km=0;
    cfgh.cout_au_km = 1;
    cfgh = deplacement(cfgh,3,ma_matrice_test);//déplacement d'un conducteur
    printf("%d\n",cfgh.compteur_km);//verif que le compteur se soit bien incrémenter
    printf("%d",cfgh.position);//verif que le positoin se soit bien changer
    for (int i=0; i<=50;i++)//test pour voir si la foncction ville_aleatoire fonctionne bien
    {
        ville_aleatoire(cfgh,4);
    }


}
*/

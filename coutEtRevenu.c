#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "coutEtRevenu.h"


float cout_au_hasard_de_coutRevenu() { //Fonction pour génerer le coût total d'un camionneur à l'entreprise (basé sur le coût réel -> essence + salaire + impôt)
    float j=0;
    j=(rand()%9)+7; //on veut un coût entre 0.7 et 1.5 euros par kilomètres par conducteur, on prend un nombre random entre 0 et 8 compris, on ajoute 7 (pour avoir entre 7 et 15)
    return j/10.0; //et pour finir on divise par 10 pour avoir entre 0.7 et 1.5
}

char* nom_au_hasard() { //Fonction pour génerer un nom "au hasard" parmis les 30 suivants :
    char* noms[30] = {"Michel","Josué","Anguerrande","Josselin","Foulque","Frederic","David","Jean-Gertrude","Liam","Vladimir", // on commence par créer le tableau noms
    "William","Sophia","Nathan","Léo","Emma","Logan","Florence", "Thomas","Noah","Félix",
    "Edouard","Victor","Dylan","Louis","James","Ethan","Benjamin","Gabriel","Rose","Nolan"}; 
    return noms[rand()%30]; //On prend un nombre au hasard entre 0 et 29 compris qui nous permet de prendre un nombre au hasard dans le tableau
}

float chiffre_affaire(float cout_conducteur, int cpt_compteur_km) { //Fonction pour créer le chiffre d'affaire selon le cout choisi pour ce conducteur et le nombre de kilomètres du contrat
    srand(time(NULL));
    float multiplieur=(rand()%4)+11.0; //on crée un multiplicateur qui mettra toujours l'entreprise en position de rentabilité sur tous les contrats (entre 1.1 et 1.4 fois le cout de chaque contrat)
    multiplieur = multiplieur/10.0; //même méthode que pour le coût, on met le multiplicateur entre 11 et 14 puis on divise par 10 (pour avoir entre 1.1 et 1.4 comme multiplicateur)
    return (cout_conducteur * cpt_compteur_km * multiplieur); //on a donc le cout total de la mission (cout par km x nombre de kilomètres) multiplié par le gain
}

/*int main() {
    printf("%s coûtera %f euros par kilomètre et le contrat actuel rapportera %f à l'entreprise\n",nom_au_hasard(), cout_au_hasard(), chiffre_affaire(cout_au_hasard(),(rand()%300)+50));
    //for (int i=0; i <= 20; i++) {
        //printf("%s coûtera %f euros par kilomètre et le contrat actuel rapportera %f à l'entreprise\n",nom_au_hasard(), cout_au_hasard(), chiffre_affaire(cout_au_hasard(),(rand()%300)+50));
    //};
    return 0;
}*/

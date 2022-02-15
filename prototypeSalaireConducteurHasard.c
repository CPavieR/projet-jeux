#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float cout_au_hasard() {
    float j=0;
    j=(rand()%9)+7;
    return j/10.0;
}

char* nom_au_hasard() {
    char* noms[30] = {"Michel","Josué","Anguerrande","Josselin","Foulque","Frederic","David","Jean-Gertrude","Liam","Vladimir",
    "William","Sophia","Nathan","Léo","Emma","Logan","Florence", "Thomas","Noah","Félix",
    "Edouard","Victor","Dylan","Louis","James","Ethan","Benjamin","Gabriel","Rose","Nolan"}; 
    return noms[rand()%30];
}

float chiffre_affaire(float cout_conducteur, int cpt_compteur_km) {
    srand(time(NULL));
    float multiplieur=(rand()%6)+13.0;
    multiplieur = multiplieur/10.0;
    return (cout_conducteur * cpt_compteur_km * multiplieur);
}

int main() {
    printf("%s coûtera %f euros par kilomètre et le contrat actuel rapportera %f à l'entreprise\n",nom_au_hasard(), cout_au_hasard(), chiffre_affaire(cout_au_hasard(),(rand()%300)+50));
    //for (int i=0; i <= 20; i++) {
        //printf("%s coûtera %f euros par kilomètre et le contrat actuel rapportera %f à l'entreprise\n",nom_au_hasard(), cout_au_hasard(), chiffre_affaire(cout_au_hasard(),(rand()%300)+50));
    //};
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float revenu_au_hasard() {
    float j=0;
    j=(rand()%20);
    return j/10.0;
}



char* nom_au_hasard() {
    char* noms[30] = {"Michel","Josué","Anguerrande","Josselin","Foulque","Frederic","David","Jean-Gertrude","Jépadnom","Liam",
    "William","Sophia","Nathan","Léo","Emma","Logan","Florence", "Thomas","Noah","Félix",
    "Edouard","Victor","Dylan","Louis","James","Ethan","Benjamin","Gabriel","Rose","Nolan"}; 
    return noms[rand()%30+0];
}

int main() {
    srand(time(NULL));
    for (int i=0; i <= 50; i++) {
        char* nom = nom_au_hasard();
        printf("le revenu sera de %f euro par kilomètre pour %s \n",revenu_au_hasard(),nom);
    };
    return 0;
}

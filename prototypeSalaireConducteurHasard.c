#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float revenu_au_hasard() {
    float j=0;
    j=(rand()%9)+7.0;
    return j/10;
}

char* nom_au_hasard() {
    char* nom = "";
    srand(time(NULL));
    switch(rand()%10) {
        case 1:
            nom = "Michel";
        break;
        case 2:
            nom = "Josué";
        break;
        case 3:
            nom = "Anguerrande";
        break;
        case 4:
            nom = "Josselin";
        break;
        case 5:
            nom = "Foulque";
        break;
        case 6:
            nom = "Frederic";
        break;
        case 7:
            nom = "David";
        break;
        case 8:
            nom = "Jean-Gertrude";
        break;
        case 9:
            nom = "Jépadnom";
        break;
    }
    return nom;
}

int main() {
    printf("le revenu sera de %f euro par kilomètre pour %s\n",revenu_au_hasard(), nom_au_hasard());
    return 0;
}

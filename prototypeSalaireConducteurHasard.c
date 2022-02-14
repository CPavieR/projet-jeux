#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char nom = "";
float revenu_au_hasard() {
    srand(time(NULL));
    switch(rand()%10) {
        case 1:{
            return 1.5;
        } break;
        case 2:{
            return 1.2;
        } break;
        case 3:{
            return 1.1;
        } break;
        case 4:{
            return 1.;
        } break;
        case 5:{
            return 0.9;
        } break;
        case 6:{
            return 0.8;
        } break;
        case 7:{
            return 1.2;
        } break;
        case 8:{
            return 1.3;
        } break;
        case 9:{
            return 1.4;
        } break;
    }
    return 1;
}

char nom_au_hasard() {
    srand(time(NULL));
    switch(rand()%10) {
        case 1:{
            nom = "Michel";
            return "Michel";
        } break;
        case 2:{
            nom = "Josué";
            return "Josué";
        } break;
        case 3:{
            nom = "Anguerrande";
            return "Anguerrande";
        } break;
        case 4:{
            nom = "Josselin";
            return "Josselin";
        } break;
        case 5:{
            nom = "Foulque";
            return "Foulque";
        } break;
        case 6:{
            nom = "Frederic";
            return "Frederic";
        } break;
        case 7:{
            nom = "David";
            return "David";
        } break;
        case 8:{
            nom = "Jean-Gertrude";
            return "Jean-Gertrude";
        } break;
        case 9:{
            nom = "Jépadnom";
            return "Jépadnom";
        } break;
    }
    return 1;
}

int main() {
    srand(time(NULL));
    printf("le revenu sera de %f euro par kilomètre pour %c ou %c\n",revenu_au_hasard(),nom, nom_au_hasard());
    return 0;
}
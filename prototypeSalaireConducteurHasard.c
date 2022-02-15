#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//char nom = "";
float revenu_au_hasard() {
    float j=0;
    j=(rand()%20);
    return j/10.0;
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
    for (int i; i <= 50; i++) {
    printf("le revenu sera de %f euro par kilomètre pour c ou c\n",revenu_au_hasard());};
    return 0;
}
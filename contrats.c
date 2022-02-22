#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//retourne le nom d'une entreprise de fa9on aléatoire
char* entreprise() {
    char* listeEnt[25] = {"Aldi", "Amazon", "Apple", "Auchan", "Candia", 
    "Casino", "Cdiscount", "Chaussea", "Decathlon", "Fnac", 
    "Foot locker", "Fromageries Bel Production", "Froudis", "Gifi", "Gucci", 
    "IKEA", "Jardiland", "Kiko", "Leroy Merlin", "Maisons du monde", 
    "Micromania", "Nosibe", "Panzani", "Primark", "Stokomani"};
    return listeEnt[rand()%25+0];
}

//retourne un revenu aléatoire compris entre 2 000 et 102 000€ 
int prix(){
    return 6000+(rand()%3000);
}

int main() {
    srand(clock()*3.14);
    for (int i=0; i<=30; i++) {
        printf("%s propose un contrat à %d €.\n", entreprise(),prix()); //print le nom d'une entreprise et le prix qu'elle propose
    }
    return 0;
} 

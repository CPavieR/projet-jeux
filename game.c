/*Pour un premier essai je vais modeliser la carte par un graphe, 
ceux ci seront modeliser de la maniere suivante :
chaque lieu est representé par un noeud
un noeud possede 
une liste de voisin et une liste correspondant au couts de trajets vers ses voisins
chaque ville possedera un indice, id, la definissant
cette premiere approche n'est pas "bonne" et doit et sera ameliorer
https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/16119-creez-vos-propres-types-de-variables
*/
typedef struct Ville Ville;

#include <stdio.h>

struct Ville
{
    int id;               //id
    int voisin[100];      // liste de voisin sous forme d'une liste de id d'autres ville
    int cout_voisin[100]; // liste de cout de voyage vers voisin sous forme d'une liste de cout
};

Ville* import_villes_from_file()
{
}
void test_villes()
{

    Ville villes_europe[20];

    Ville toulouse;

    toulouse.id = 0;
    toulouse.voisin[0] = 0;
    toulouse.voisin[1] = 3;
    toulouse.cout_voisin[0] = 0;
    toulouse.cout_voisin[1] = 2;

    Ville marseille;

    marseille.id = 1;
    marseille.voisin[0] = 1;
    marseille.voisin[1] = 2;
    marseille.cout_voisin[0] = 0;
    marseille.cout_voisin[1] = 2;

    Ville nice;

    nice.id = 2;
    nice.voisin[0] = 2;
    nice.cout_voisin[0] = 0;

    Ville lyon;

    lyon.id = 3;
    lyon.voisin[0] = 3;
    lyon.cout_voisin[0] = 0;

    villes_europe[0] = toulouse;
    villes_europe[1] = marseille;
    villes_europe[2] = nice;
    villes_europe[3] = lyon;
    printf("test\n");

    printf("la ville Toulouse a pour id : %d et as pour voisin :%d pour un cout de %d\n", toulouse.id, toulouse.voisin[1], toulouse.cout_voisin[1]);
    printf("la ville Marseille a pour id : %d et as pour voisin :%d pour un cout de %d\n", marseille.id, marseille.voisin[1], marseille.cout_voisin[1]);
}
int main()
{
    test_villes();

    return 0;
}


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
    int id;
    int voisin[100];
    int cout_voisin[100];

};



int main(){
    printf("test\n");
    struct Ville Toulouse;

    Toulouse.id = 1;
   /* Toulouse.voisin;
    Toulouse.cout_voisin;*/

    printf("la ville Toulouse a pour id : %d",Toulouse.id);

    return 0;
}

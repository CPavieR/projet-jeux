/*Pour un premier essai je vais modeliser la carte par un graphe, 
ceux ci seront modeliser de la maniere suivante :
chaque lieu est representé par un noeud
un noeud possede 
une liste de voisin et une liste correspondant au couts de trajets vers ses voisins
chaque ville possedera un indice, id, la definissant
cette premiere approche n'est pas "bonne" et doit et sera ameliorer
https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/16119-creez-vos-propres-types-de-variables
*/
typedef struct Ville Ville; // simplification d'utilisation du type ville

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Ville // on creer un nouveau type (type somme) nommé ville
{
    int id;               //id
    char nom[25];         // nom de la ville
    int voisin[100];      // liste de voisin sous forme d'une liste de id d'autres ville
    int cout_voisin[100]; // liste de cout de voyage vers voisin sous forme d'une liste de cout
};

int import_csv()
{
    FILE *document;
    document = fopen("villes.csv", "r");
    char tab[1024];
    fgets(tab, sizeof(tab), document);
    char *ligne = strtok(tab, ";");
    while (ligne != "F" && ligne != NULL)
    {
        printf("%s\n", ligne);
        ligne = strtok(NULL, ";");
    }
    return 0; //function à compléter
};

int* get_list_of_int_from_list_of_char(char char_list[])
// fonction permetant d'obtenir
// une liste de int a partir d'une liste de char
// la liste doit etre sous la forme [nbr][nbr][nbr]...
{
    int k = strlen(char_list); // on prends la longueur de la liste de charac a convertir
    int list_of_int[20];       // contient la liste de int final
    short i = 0;               // numero de la case que l'on regarde
    short number_number = 0;   // numero du nombre que l'on ecrit dans la liste de int finale
    int somme_case = 0;        // est la somme de la casse que l'on observe
    while (i < k)
    {
        if (char_list[i] == '[')
        {
            i++;
            somme_case = 0;
            while (isdigit(char_list[i]))
            {
                somme_case = somme_case * 10 + char_list[i] - 48;
                i++;
            }
            list_of_int[number_number] = somme_case;
            number_number++;
        }
        i++;
    }
    return list_of_int;
}

void test_villes() //test basiques sur le type villes
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
    int *list;
    char test[40] = "fdrf[45][43];[43]";
    import_csv();
    list = get_list_of_int_from_list_of_char(test);
    printf("test 1 : %d \n test 2 : %d \n test 3 : %d \n", list[0], list[1], list[2]);

    return 0;
}

/*Pour un premier essai je vais modeliser la carte par un graphe,
ceux ci seront modeliser de la maniere suivante :
chaque lieu est representé par un noeud
un noeud possede
une liste de voisin et une liste correspondant au couts de trajets vers ses voisins
chaque ville possedera un indice, id, la definissant
cette premiere approche n'est pas "bonne" et doit et sera ameliorer
https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/16119-creez-vos-propres-types-de-variables
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// on vas implementer le graphe pondéré des ville grace a une matrice pour les distance et liaison
//  et une liste de nom ou l'id de la ville est l'index de son nom
// int matrice_europe[50][50];
// char **nom_ville;

int get_num_from_charac(char characters[])
{
    int k = strlen(characters);
    int somme = 0;
    for (int i = 0; i < k; i++)
    {
        somme = somme * 10 + characters[i] - 48; // on convertit ceux ci (-48) et on ajoute ceux ci a la somme en prenant en compte les puissance de dix
    }
    return somme;
}

int *get_list_of_int_from_list_of_char(char char_list[])
// fonction permetant d'obtenir
// une liste de int a partir d'une liste de char
// la liste doit etre sous la forme [nbr][nbr][nbr]...
{

    int k = strlen(char_list);  // on prends la longueur de la liste de charac a convertir
    static int list_of_int[20]; // contient la liste de int final
    short i = 0;                // numero de la case que l'on regarde
    short number_number = 0;    // numero du nombre que l'on ecrit dans la liste de int finale
    int somme_case = 0;         // est la somme de la casse que l'on observe
    while (i < k)               // boucle sur les indice de char_list
    {
        if (char_list[i] == '[') // si il y as une ouverture de bracket (c'est a dirte le debut d'un nr)
        {
            i++;
            somme_case = 0;
            while (isdigit(char_list[i])) // tant que les caractere sont des nombres
            {
                somme_case = somme_case * 10 + char_list[i] - 48; // on convertit ceux ci (-48) et on ajoute ceux ci a la somme en prenant en compte les puissance de dix
                i++;
            }
            list_of_int[number_number] = somme_case; // quand un nombre est fini on l'ajoute a la liste d'entier et on recommence
            number_number++;
        }
        i++;
    }
    return list_of_int;
}

/*void insert_voisin(int id, char *li_voisin, char *voisin_cout)
{
    char **nom_ville;
    printf("hit");
    int *liste_des_voisins = get_list_of_int_from_list_of_char(li_voisin);
    int *cout_des_voisin = get_list_of_int_from_list_of_char(voisin_cout);
    int k = strlen(liste_des_voisins);// <- ligne produisant warning a corriger
    for(int i = 0; i<k; i++){
            matrice_europe[id][(liste_des_voisins[i])]= cout_des_voisin[i];
    }
}*/
char **import_csv()
{
    static char *nom_ville[] = {""};
    int id = 0; // initialisations des variables propres aux villes
    int voisin[50];
    int cout_voisin[50];
    FILE *document;
    document = fopen("villes.csv", "r");
    char tab[4096];
    while (fgets(tab, sizeof(tab), document))
    {          
                              // on lit le fichier jusqu'a que la lecture echoue
        char *mots = strtok(tab, ";"); // on delimite la str
                                       // while (mots != NULL)// on attends 4 champs id, nom, voisin, cout voisin
        printf("%s\n", mots);
        id = get_num_from_charac(mots);
        // printf("hit1");
        mots = strtok(NULL, ";"); // on passe au mots suivant
        printf("%s\n", mots);

        nom_ville[id] = mots; // <- ligne ne marchant pas
        // printf("hit3");
        mots = strtok(NULL, ";");
        printf("%s\n", mots);
        mots = strtok(NULL, ";");
        printf("%s\n", mots);
        // on passe au mots suivant
        // char *voisin_cout = strtok(NULL, ";");
        // printf("hit5"); // on passe au mots suivant
        // insert_voisin(id, mots, voisin_cout);
        fflush(NULL);
    }
    //printf("hit");
    return nom_ville; // function à compléter
};

int main()
{
    /*    int *list;
        char test[40] = "fdrf[45][43];[43]";
        import_csv();
        list = get_list_of_int_from_list_of_char(test);


        printf("test 1 : %d \n test 2 : %d \n test 3 : %d \n", list[0], list[1], list[2]);
    */
    printf("hit\n");
    char **noms = import_csv();
    printf("test\n");
    /*for (int j = 0; j < 50; j++)
    {
        for (int i = 0; i < 50; i++)
        {
            printf("charac\n");
            printf("%c", noms[j][i]);
        }
        printf("\n");
    }
    printf("hit");*/

    /*for(int i = 0; i<50;i++){
        for(int j =0; j<50; j++){
            printf("%d ",matrice_europe[i][j]);

        }
        printf("\n");

    }*/
    return 0;
}

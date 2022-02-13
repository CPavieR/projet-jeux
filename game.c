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
#define NOMBRE_DE_VILLES   16//on construit par la suite des arrays dont la taille est égale au nombre de villes, a modif aux besoins





struct list_of_int_with_len{
    int *liste;
    int len;
};//structure contenant une liste et sa taille, pratique pour plus tard


// on vas implementer le graphe pondéré des ville grace a une matrice pour les distance et liaison
//  et une liste de nom ou l'id de la ville est l'index de son nom


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

struct list_of_int_with_len get_list_of_int_from_list_of_char(char char_list[])
/**
 * @brief fonction permetant d'obtenir
* une liste de int a partir d'une liste de char
* la liste doit etre sous la forme nbr,nbr,nbr,...
*/
{

    int k = strlen(char_list);  // on prends la longueur de la liste de charac a convertir
    static int list_of_int[20]; // contient la liste de int final
    short i = 0;                // numero de la case que l'on regarde
    short number_number = 0;    // numero du nombre que l'on ecrit dans la liste de int finale
    int somme_case = 0;         // est la somme de la casse que l'on observe
    while (i < k)               // boucle sur les indice de char_list
    {
        if (char_list[i] == '[' || char_list[i]==',') // si il y as une ouverture de bracket (c'est a dirte le debut d'un nr)
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
            printf("get list of int, int courant :%d\n", somme_case);
        }
        else{
        i++;}

    }
    printf("fin de getlist of int\n");
    struct list_of_int_with_len liste_entiers_avec_longueur = {list_of_int,number_number};
    return liste_entiers_avec_longueur;
}

void insert_voisin(int id, char *li_voisin, char *voisin_cout, int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES])
/**
 * @brief cette fonction prends en parametre, un id de ville, deux liste de caractere contenant des listes de int et un pointeur vers la matrice d'adjacence
 * elle vas ecrire dans la matrice les couts de deplacement d'un ville a une autre
 * 
 * 
 * STATUT ACTUELLE : NE FONCTIONNE "PAS", erreur a voir plus bas
 */
{
    printf("rentre insert voisin\n");
    struct list_of_int_with_len liste_des_voisins = get_list_of_int_from_list_of_char(li_voisin);
    int* listeIdVoisin = liste_des_voisins.liste;
    for(int i = 0; i < liste_des_voisins.len;i++){
        printf("%d ", listeIdVoisin[i]);//test, a enlever quand debuggé
    }//ok
    struct list_of_int_with_len cout_des_voisin = get_list_of_int_from_list_of_char(voisin_cout);
    for(int i = 0; i < cout_des_voisin.len;i++){
        printf("%d ", cout_des_voisin.liste[i]);//test, a enlever quand debuggé
    }//ok
    int k = (liste_des_voisins.len);//
    int *listeCout = cout_des_voisin.liste;//
    printf("debut affectation matrice dans insert_voisin\n");//
    for(int i = 0; i<k; i++){//
            printf("affectation :%d ",listeIdVoisin[i]);//
            printf("%d\n",listeCout[i]);// d'une maniere ou d'une autre, entre ok et cette ligne les tab listeCout et listeIdVoisin on la meme valeur !
            //matrice_adja[id][listeIdVoisin[i]]= listeCout[i];//(listeIdVoisin[i])
    }
}
void import_csv(char *nom_ville[NOMBRE_DE_VILLES], int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES])//A DEBBUGGER
/**
 * @brief cette fonction importera toute les variables stocké dans le fichier .csv
 * elle prends en entrée les pointeur a l'endroit ou l'on voudrat stocké le resultat
 * 1 pointeur tableau noms des ville
 * 2 pointeur matrice d'adjacence pondéré
 */
{
    int id = 0; // initialisations des variables propres aux villes
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
        printf("%d\n",id);
        mots = strtok(NULL, ";"); // on passe au mots suivant
        printf("%s\n", mots);
        nom_ville[id] = (char*)malloc(strlen(mots)+1);
        strcpy(nom_ville[id] ,mots);//on insere le nom de la ville au bon indice
        char *li_voisin = strtok(NULL, ";");

        printf("%s\n", li_voisin);
        char *voisin_cout = strtok(NULL, ";");
        printf("%s\n", voisin_cout);

        insert_voisin(id, li_voisin, voisin_cout, matrice_adja);
        fflush(NULL);
    }
    fclose(document);
    printf("fin de fgets\n");
    //printf("hit");
};

int main()
{
    static char *nom_ville[NOMBRE_DE_VILLES];
    static int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES];
    printf("debut de import csv\n");
    import_csv(nom_ville, matrice_adja);
    printf("test\n");
    for (int j = 1; j < 13; j++)
    {
        printf("%s %d\n",nom_ville[j],j);//test nom des villes
    }

    for(int i = 0; i<15;i++){
        for(int j =0; j<15; j++){
            printf("%d ",matrice_adja[i][j]);//test matrice

        }
        printf("\n");

    }
    return 0;
}

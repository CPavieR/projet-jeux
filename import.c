#include "import.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NOMBRE_DE_VILLES   16//on construit par la suite des arrays dont la taille est égale au nombre de villes, a modif aux besoins




// on vas implementer le graphe pondéré des ville grace a une matrice pour les distance et liaison
//  et une liste de nom ou l'id de la ville est l'index de son nom


int get_num_from_charac(char characters[])
{
    int k = strlen(characters);
    int somme = 0;
    for (int i = 0; i < k; i++)//pour chaque chiffres
    {
        somme = somme * 10 + characters[i] - 48; // on convertit ceux ci (-48) et on ajoute ceux ci a la somme en prenant en compte les puissance de dix
    }
    return somme;
}


float get_float_from_charac(char characters[])
{
    int k = strlen(characters);
    float somme = 0.;
    float cent = 0.;
    int i = 0;
    while(i<k && characters[i] != 46)
    {   

        somme = somme * 10 + characters[i] - 48; // on convertit ceux ci (-48) et on ajoute ceux ci a la somme en prenant en compte les puissance de dix
        i = i +1;
    }
    i = i + 1;
    while(i<k)
    {
        cent = cent * 10 + characters[i] - 48;
        i++;
    }
    cent = cent / 100;
    somme = somme + cent;

    return somme;
}


int get_list_of_int_from_list_of_char(char char_list[], int *liste_a_rendre)
/**
 * @brief fonction permetant d'obtenir
* une liste de int a partir d'une liste de char
* la liste doit etre sous la forme nbr,nbr,nbr,...
*/
{

    int k = strlen(char_list);  // on prends la longueur de la liste de charac a convertir
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
            liste_a_rendre[number_number] = somme_case; // quand un nombre est fini on l'ajoute a la liste d'entier et on recommence
            number_number++;
        }
        else{
        i++;}
    }
    return number_number;
}

void insert_voisin(int id, char *li_voisin, char *voisin_cout, int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES])
/**
 * @brief cette fonction prends en parametre, un id de ville, deux liste de caractere contenant des listes de int et un pointeur vers la matrice d'adjacence
 * elle vas ecrire dans la matrice les couts de deplacement d'un ville a une autre
 * 
 * 
 * 
 */
{
    int listeIdVoisin[NOMBRE_DE_VILLES];
    int k = get_list_of_int_from_list_of_char(li_voisin, listeIdVoisin);//on recupere la liste des id des voisin

    int listeCout[NOMBRE_DE_VILLES];
    get_list_of_int_from_list_of_char(voisin_cout, listeCout);//on recupere la liste des cout des voisin



    for(int i = 0; i<k; i++){//on insere chacun des cout a l'indice correspondant dans la matrice
            matrice_adja[id][listeIdVoisin[i]]= listeCout[i];
    }
}
void import_csv(char *nom_ville[NOMBRE_DE_VILLES], int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES])
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
        id = get_num_from_charac(mots);//on recupere l'id de la ville que l'on est en train de lire
        mots = strtok(NULL, ";"); // on passe au mots suivant
        nom_ville[id] = (char*)malloc(strlen(mots)+1);//on recupere le nom de la ville et on l'enregistre dans un tableau de tableau de caracteres
        strcpy(nom_ville[id] ,mots);//on insere le nom de la ville au bon indice
        char *li_voisin = strtok(NULL, ";");

        char *voisin_cout = strtok(NULL, ";");

        insert_voisin(id, li_voisin, voisin_cout, matrice_adja);//on recupere la liste des id et des couts et on les insere deans la matrice grace a la fonction insert_voisin
        fflush(NULL);//on flush les entrées et sortie pour eviter des problemes
    }
    fclose(document);//on ferme le document
};


void import_sauvegarde(float *capital, int *nbr_conduc, struct conducteur *a[10])
/**
 * @brief cette fonction importera toute les variables stocké dans le fichier .csv
 * elle prends en entrée les pointeur a l'endroit ou l'on voudrat stocké le resultat
 * 1 pointeur tableau noms des ville
 * 2 pointeur matrice d'adjacence pondéré
 */
{   
    
    printf("debut import fct\n");

    FILE *document;
    document = fopen("sauvegarde.txt", "r");
    char tab[4096];
    fgets(tab, sizeof(tab), document);
        printf("fgets passe\n");
                              // on lit le fichier jusqu'a que la lecture echoue
        char *mots = strtok(tab, ";"); // on delimite la str
                                       // while (mots != NULL)// on attends 4 champs id, nom, voisin, cout voisin
        float capita = get_float_from_charac(mots);//on recupere l'id de la ville que l'on est en train de lire
        *capital = capita;
        mots = strtok(NULL, ";"); // on passe au mots suivant
        *nbr_conduc = get_num_from_charac(mots);
        printf("debut import conduc\n");


    for(int i = 0; i<*nbr_conduc; i++){
        fgets(tab, sizeof(tab), document);
        char *mots = strtok(tab, ";");
        a[i].id = get_num_from_charac(mots);
        mots = strtok(NULL, ";");
        a[i].position = get_num_from_charac(mots);
        mots = strtok(NULL, ";");
        a[i].compteur_km = get_num_from_charac(mots);
        mots = strtok(NULL, ";");
        a[i].cout_au_km = get_float_from_charac(mots);
        mots = strtok(NULL, ";");
        a[i].jour_de_repos = get_float_from_charac(mots);
        mots = strtok(NULL, ";");
        strcpy(a[i].nom ,mots);
    }
    fclose(document);//on ferme le document
};







/*
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
            if(matrice_adja[i][j]<100){
                printf("00%d ",matrice_adja[i][j]);//test matrice
            }else{if(matrice_adja[i][j]<10){
                printf("0%d ",matrice_adja[i][j]);//test matrice
            }else{printf("%d ",matrice_adja[i][j]);//test matrice
            } }
            

        }
        printf("\n");

    }
    return 0;
}
*/
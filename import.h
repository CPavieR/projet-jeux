#ifndef IMPORT_H
#define IMPORT_H
#define NOMBRE_DE_VILLES   27
#include "conducteur.h"
#include <stdio.h>

int get_num_from_charac(char characters[]);
int get_list_of_int_from_list_of_char(char char_list[], int *liste_a_rendre);
void insert_voisin(int id, char *li_voisin, char *voisin_cout, int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES]);
void import_csv(char *nom_ville[NOMBRE_DE_VILLES], int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES]);
void import_sauvegarde(float *capital, int *nbr_conduc, struct conducteur (*a)[10],FILE *document);
#endif

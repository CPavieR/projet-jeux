
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "conducteur.h"
#include "coutEtRevenu.h"
#include "import.h"
#define NOMBRE_DE_VILLES   16//on construit par la suite des arrays dont la taille est égale au nombre de villes, a modif aux besoins




/*struct conducteur {
int id;
int position;
int compteur_km;
int cout_au_km;
int jour_de_repos;
char nom[30];
};
*/

int main()
{
    static char *nom_ville[NOMBRE_DE_VILLES];
    static int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES];
    printf("debut de import csv\n");
    import_csv(nom_ville, matrice_adja);
    rnd_srand();



    
    struct conducteur a[3] = {
        {1,1,0,1.1,0,"jean-michel"},
        {2,3,555,1.3,0,"jean-mich"},
        {3,7,0,1.5,2,"pakpak"}};
    
    for(int i = 0; i<3; i++){
        printf("conducteur : id: %d, position : %d, compteur : %d, coutkm : %1.1f, jour de repos : %d\n",a[i].id,a[i].position,a[i].compteur_km, a[i].cout_au_km,a[i].jour_de_repos);
    }
    
    a[0] = deplacement(a[0],5,300);
    a[1] = deplacement(a[1], 9, 910);
    a[2] = deplacement(a[2], 13, 5);


    for(int i = 0; i<3; i++){
        printf("conducteur : id: %d, position : %d, compteur : %d, coutkm : %1.1f, jour de repos : %d\n",a[i].id,a[i].position,a[i].compteur_km, a[i].cout_au_km,a[i].jour_de_repos);
    }







    return 0;
}

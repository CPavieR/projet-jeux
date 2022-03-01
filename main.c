
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "conducteur.h"
#include "systemeRevenusEvenements.h"
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
int get_int_in_input_in_range(int a, int b){
    /***
     * entre : deux int a et b formant un intervalle, avec a<=b
     * sortie : un int entre a et b
     * demande a l'utilisateur de renter un chiffre entre a et b
     * */
    fflush(stdin);
    printf("rentrer un entier entre %d et %d.\n",a,b);
    int reponse = -1;
    scanf("%d",&reponse);
    while(a>=reponse || reponse >= b){
        printf("nous n'avons pas compris votre demande, ressayez.\n");
        fflush(stdin);
        scanf("%d",&reponse);
    }
    return reponse;
}

void tirage_des_contracts(int nb_contract,char *liste_entreprise[], int *revenu_de_contr){
    for(int i = 0; i<nb_contract;i++){
        liste_entreprise[i] = entreprise();
        revenu_de_contr[i] = prix_contrat();
    }
}

int main()
{
    static float capital = 10000;
    float* pointeur_du_capital = &capital;
    static char *nom_ville[NOMBRE_DE_VILLES];
    static int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES];
    printf("debut de import csv\n");
    import_csv(nom_ville, matrice_adja);
    rnd_srand();
    int code_action = -1;
    int nombre_de_conduct = 3;
    struct conducteur a[10] = {
        {1,1,0,1.1,0,"jean-michel"},
        {2,3,555,1.3,0,"patrick"},
        {3,7,0,1.5,2,"pakpak"}};
    
    while(code_action != 0){
        for(int i = 0; i<nombre_de_conduct; i++){
            printf("conducteur : id: %d, position : %d, compteur : %d, coutkm : %1.1f, jour de repos : %d\n",a[i].id,a[i].position,a[i].compteur_km, a[i].cout_au_km,a[i].jour_de_repos);
            if(a[i].jour_de_repos == 0){
                printf("le conducteur %s a finis de se reposer, il peux donc realiser un contract\n", a[i].nom);
                char *liste_entreprise_de_contract[3];
                int revenu_pour_contrat[3];
                tirage_des_contracts(3, liste_entreprise_de_contract, revenu_pour_contrat);
                for(int j = 0; j<3; j++){
                    printf("%s coûtera %1.1f euros par kilometre. L'entreprise %s vous propose un contrat a %d euros.\n",a[i].nom, a[i].cout_au_km, liste_entreprise_de_contract[j], revenu_pour_contrat[j]);
                }


            }
        }
    code_action = 0;
    }
    //code_action = get_int_in_input_in_range(1,5);

    printf("%d\n", code_action);
    
    return 0;
}



    /*struct conducteur a[3] = {
        {1,1,0,1.1,0,"jean-michel"},
        {2,3,555,1.3,0,"patrick"},
        {3,7,0,1.5,2,"pakpak"}};
    
    for(int i = 0; i<3; i++){
        printf("conducteur : id: %d, position : %d, compteur : %d, coutkm : %1.1f, jour de repos : %d\n",a[i].id,a[i].position,a[i].compteur_km, a[i].cout_au_km,a[i].jour_de_repos);
    }
    printf("capital : %f", capital);
    a[0] = deplacement(a[0],5,300,pointeur_du_capital);
    a[1] = deplacement(a[1], 9, 910,pointeur_du_capital);
    a[2] = deplacement(a[2], 13, 5,pointeur_du_capital);


    for(int i = 0; i<3; i++){
        printf("conducteur : id: %d, position : %d, compteur : %d, coutkm : %1.1f, jour de repos : %d\n",a[i].id,a[i].position,a[i].compteur_km, a[i].cout_au_km,a[i].jour_de_repos);
    }
    printf("capital : %f", capital);*/
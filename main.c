
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "conducteur.h"
#include "systemeRevenusEvenements.h"
#include "import.h"
#define NOMBRE_DE_VILLES   16//on construit par la suite des arrays dont la taille est égale au nombre de villes, a modif aux besoins

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}


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
    while(a>reponse || reponse > b){
        printf("nous n'avons pas compris votre demande, ressayez.\n");
        viderBuffer();
        scanf("%d",&reponse);
    }
    return reponse;
}




void tirage_des_contracts(int nb_contract,char *liste_entreprise[], int *revenu_de_contr, int* km){
    for(int i = 0; i<nb_contract;i++){
        liste_entreprise[i] = entreprise();
        revenu_de_contr[i] = prix_contrat();
        km[i] = km_random();
    }
}

int km_random(){
    return (int_random() % 1000);
}
void gestion_contrat(struct conducteur courant, float* pointeur_du_capital){
    printf("le conducteur %s a finis de se reposer, il peux donc realiser un contract\n", courant.nom);
    char *liste_entreprise_de_contract[3];
    int revenu_pour_contrat[3];
    int km_contract[3];
    tirage_des_contracts(3, liste_entreprise_de_contract, revenu_pour_contrat, km_contract);
    printf("%s coûtera %1.1f euros par kilometre.\n",courant.nom, courant.cout_au_km);
    for(int j = 0; j<3; j++){
        printf("L'entreprise %s vous propose un contrat pour %d km a %d euros.\n", liste_entreprise_de_contract[j],km_contract[j], revenu_pour_contrat[j]);
    }
    printf("\n\n veuillez choisir l'un de ces contracts en ecrivant 1, 2 ou 3\n");
    int choix;
    choix = get_int_in_input_in_range(1,3);
    courant = deplacement(courant,int_random()%10,km_contract[choix-1],pointeur_du_capital);
    *pointeur_du_capital = *pointeur_du_capital + revenu_pour_contrat[choix];
    //printf("Votre entreprise possede : %1.2f euros REMUNE\n\n", *pointeur_du_capital);

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
        printf("Votre entreprise possede : %1.2f euros\n\n", capital);
        for(int i = 0; i<nombre_de_conduct; i++){
            
            printf("conducteur : id: %d, position : %d, compteur : %d, coutkm : %1.1f, jour de repos : %d\n",a[i].id,a[i].position,a[i].compteur_km, a[i].cout_au_km,a[i].jour_de_repos);
            if(a[i].jour_de_repos == 0){
                gestion_contrat(a[i], pointeur_du_capital);
            }
            else{
                a[i].jour_de_repos = a[i].jour_de_repos - 1;
            }
            printf("Votre entreprise possede : %1.2f euros\n\n", capital);
        }
    printf("voulez vous continuer ? 0 = non, 1 = oui\n");
    code_action = get_int_in_input_in_range(0,1);
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
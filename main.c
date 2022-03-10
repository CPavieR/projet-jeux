
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "conducteur.h"
#include "systemeRevenusEvenements.h"
#include "import.h"
#include "sauvegarde.h"

#define NOMBRE_DE_VILLES 16 // on construit par la suite des arrays dont la taille est égale au nombre de villes, a modif aux besoins

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
int get_int_in_input_in_range(int a, int b)
{
    /***
     * entre : deux int a et b formant un intervalle, avec a<=b
     * sortie : un int entre a et b
     * demande a l'utilisateur de renter un chiffre entre a et b
     * */
    fflush(stdin);
    printf("rentrer un entier entre %d et %d.\n", a, b);
    int reponse = -1;
    scanf("%d", &reponse);
    while (a > reponse || reponse > b)
    {
        printf("nous n'avons pas compris votre demande, ressayez.\n");
        viderBuffer();
        scanf("%d", &reponse);
    }
    return reponse;
}
int km_random()
{
    // donne un nombre de kilometre aleatoire, temporaire les temps que l'algo de dijsktra soit termine
    return (int_random() % 1000);
}
void tirage_des_contracts(int nb_contract, char *liste_entreprise[], int *revenu_de_contr, int *km)
/***
 * @brief permet de generet un nombre de nombres definis de contrat
 *entre : nb de contrat a generer, tableau de tacleau de char pour les noms d'entreprise, int* pour les revenue associe, int* pour le nombre de km pour chaque contrat
 */
{
    for (int i = 0; i < nb_contract; i++)
    {
        liste_entreprise[i] = entreprise();
        revenu_de_contr[i] = prix_contrat();
        km[i] = km_random();
    }
}

struct conducteur gestion_contrat(struct conducteur courant, float *pointeur_du_capital)
/***
* @brief permet a partir d'un conducteur de luis donner un contrat
entre  : un conducteur, pointeur d'un float, le capital de l'entreprise
*/
{
    printf("le conducteur %s a finis de se reposer, il peux donc realiser un contract\n", courant.nom);
    char *liste_entreprise_de_contract[3];
    int revenu_pour_contrat[3];
    int km_contract[3];
    tirage_des_contracts(3, liste_entreprise_de_contract, revenu_pour_contrat, km_contract);
    printf("%s coûtera %1.1f euros par kilometre.\n", courant.nom, courant.cout_au_km);
    for (int j = 0; j < 3; j++)
    {
        printf("L'entreprise %s vous propose un contrat pour %d km a %d euros.\n", liste_entreprise_de_contract[j], km_contract[j], revenu_pour_contrat[j]);
    }
    printf("\n\n veuillez choisir l'un de ces contracts en ecrivant 1, 2 ou 3\n");
    int choix;
    choix = get_int_in_input_in_range(1, 3);
    courant = deplacement(courant, int_random() % 10, km_contract[choix - 1], pointeur_du_capital);
    *pointeur_du_capital = *pointeur_du_capital + revenu_pour_contrat[choix];
    return courant;
}

void gestion_evenement_aleatoire(float *pointeur_du_capital)
/***
 * @brief gere les evenements aleatoire
 *il ont 10% de chance de se produire lorsque que l'on realise un contract
 *
 */
{
    if (int_random() % 10 == 9)
    {
        int nb_evenement = int_random() % 10;
        printf("%s\n", evenement_aleatoire(nb_evenement));
        *pointeur_du_capital = *pointeur_du_capital - prix_evenement_aleatoire(nb_evenement);
    }
}

void ajout_conducteur(int nombre_de_conduct, struct conducteur (*a)[10])
{
    printf("Tapez 1 si vous voulez engager un nouveau conducteur");
    int var_validation1 = get_int_in_input_in_range(0, 1);
    if (var_validation1 == 1)
    {
        struct conducteur conduct1;
        conduct1.id = nombre_de_conduct + 1;
        // conduct1.nom = nom_au_hasard();
        strcpy(conduct1.nom, nom_au_hasard());
        conduct1.cout_au_km = 0.5 + ((int_random() % 10) / 10);
        conduct1.jour_de_repos = 0;
        conduct1 = ville_aleatoire(conduct1, NOMBRE_DE_VILLES);

        struct conducteur conduct2;
        conduct2.id = nombre_de_conduct + 1;
        // conduct2.nom = nom_au_hasard();
        strcpy(conduct2.nom, nom_au_hasard());
        conduct2.cout_au_km = 0.5 + ((int_random() % 10) / 10);
        conduct2.jour_de_repos = 0;
        conduct2 = ville_aleatoire(conduct2, NOMBRE_DE_VILLES);

        struct conducteur conduct3;
        conduct3.id = nombre_de_conduct + 1;
        // conduct3.nom = nom_au_hasard();
        strcpy(conduct3.nom, nom_au_hasard());
        conduct3.cout_au_km = 0.5 + ((int_random() % 10) / 10);
        conduct3.jour_de_repos = 0;
        conduct3 = ville_aleatoire(conduct1, NOMBRE_DE_VILLES);

        printf("On vous propose 3 conducteur");
        printf("Le premier se nommne %s à un cout de de %f et se trouve actuellement dans la ville %d\n", conduct1.nom, conduct1.cout_au_km, conduct1.position);
        printf("Le second se nommne %s à un cout de de %f et se trouve actuellement dans la ville %d\n", conduct2.nom, conduct2.cout_au_km, conduct2.position);
        printf("Le troisieme se nommne %s à un cout de de %f et se trouve actuellement dans la ville %d\n", conduct3.nom, conduct3.cout_au_km, conduct3.position);

        int var_validation2;
        printf("Tapez 1,2 ou 3 pour choisir un conducteur. Sinon vous ne pourrez pas choisir un nouveau conducteur");
        var_validation2 = get_int_in_input_in_range(1, 3);
        if (var_validation2 == 1)
        {
            // struct conducteur nv = {conduct1.id,conduct1.position,0,conduct1.cout_au_km,0,conduct1.nom};
            (*a)[nombre_de_conduct] = conduct1;
        }
        else
        {
            if (var_validation2 == 2)
            {
                // struct conducteur nv = {conduct2.id,conduct2.position,0,conduct2.cout_au_km,0,conduct2.nom};
                (*a)[nombre_de_conduct] = conduct2;
            }
            else
            {
                if (var_validation2 == 3)
                {
                    // struct conducteur nv = {conduct3.id,conduct3.position,0,conduct3.cout_au_km,0,conduct3.nom};
                    (*a)[nombre_de_conduct] = conduct3;
                }
            }
        }
    }
}

int main()
// boucle principale du jeu
{
    static float capital = 10000;
    float *pointeur_du_capital = &capital;
    static char *nom_ville[NOMBRE_DE_VILLES];
    static int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES];
    printf("debut de import csv\n");
    import_csv(nom_ville, matrice_adja);
    init_random();
    int code_action = -1;
    int nombre_de_conduct = 1; // definitions des variables nessecaire a l'excution de la boucle principale
    struct conducteur a[10] = {// on definit une liste de conducteur avec 10 conducteur maximum
        {1, 1, 0, 1.1, 0, "jean-michel"}};
    printf("souhaitez vous importez une sauvegarde, si celle ci existe ? 1 = oui 0 = non");
    int choix_sauv = get_int_in_input_in_range(0, 1);
    if (choix_sauv == 1)
    {
        import_sauvegarde(pointeur_du_capital, &nombre_de_conduct, &a);
    }

    int nombre_de_tour = 0;
    while (code_action != 0)
    {
        printf("vous etes actuellement au tour numero %d\n", nombre_de_tour); // debut d'ajout de code (matthieu le 08.03.2022)
        nombre_de_tour++;
        if (nombre_de_tour % 20 == 0)
        {
            ajout_conducteur(nombre_de_conduct, &a);
            nombre_de_conduct++;
        } // fin d'ajout de code (matthieu le 08.03.2022)

        printf("Votre entreprise possede : %1.2f\n\n", capital); // on affiche le capital a chaque boucle
        for (int i = 0; i < nombre_de_conduct; i++)
        { // pour chacun des conducteur on teste s'il sont repose si oui, on leur assigne un nouveau contrat
            // sinon on decremente leur jours de repos
            printf("NOMBRE DE JOUR DE REPOS : %d", a[i].jour_de_repos);
            printf("conducteur : %s id: %d, position : %d, compteur : %d, coutkm : %1.1f, jour de repos : %d\n", a[i].nom, a[i].id, a[i].position, a[i].compteur_km, a[i].cout_au_km, a[i].jour_de_repos);
            if (a[i].jour_de_repos == 0)
            {
                a[i] = gestion_contrat(a[i], pointeur_du_capital);
                gestion_evenement_aleatoire(pointeur_du_capital);
            }
            else
            {
                a[i].jour_de_repos = a[i].jour_de_repos - 1;
            }
            printf("Votre entreprise possede : %1.2f euros\n\n", capital);
        }
        printf("voulez vous continuer ? 0 = non, 1 = oui\n");
        code_action = get_int_in_input_in_range(0, 1);
    }
    // code_action = get_int_in_input_in_range(1,5);

    printf("%d\n", code_action);
    sauvegarder(capital, nombre_de_conduct, a);
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

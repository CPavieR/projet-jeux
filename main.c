
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "conducteur.h"
#include "systemeRevenusEvenements.h"
#include "import.h"
#include "sauvegarde.h"
#include "dijkstra.h"

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

    //printf("rentrer un entier entre %d et %d.\n", a, b);
    int reponse = -1;
    scanf("%d", &reponse);
    while (a > reponse || reponse > b)
    {
        printf("Nous n'avons pas compris votre demande, réessayez.\n");
        viderBuffer();
        scanf("%d", &reponse);
    }
    return reponse;
}
/*
void tirage_des_contracts(int nb_contract, char *liste_entreprise[], int *revenu_de_contr, int *km, int * destination, int emplacement, int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES])

 * @brief permet de generet un nombre de nombres definis de contrat
 *entre : nb de contrat a generer, tableau de tacleau de char pour les noms d'entreprise, int* pour les revenue associe, int* pour le nombre de km pour chaque contrat
 
{
    for (int i = 0; i < nb_contract; i++)
    {
        liste_entreprise[i] = entreprise();
        do{
        destination[i] = (int_random()%12) + 1;}
        while(destination[i] == emplacement);
        
        km[i] = dijkstra(matrice_adja, emplacement, destination[i]);
        printf("km : %d\n",km[i]);
        revenu_de_contr[i] = prix_contrat(km[i]);
        
    }
*/

struct conducteur gestion_contrat(struct conducteur courant, float *pointeur_du_capital, int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES], char *nom_ville[NOMBRE_DE_VILLES])
/***
* @brief permet a partir d'un conducteur de luis donner un contrat
entre  : un conducteur, pointeur d'un float, le capital de l'entreprise
*/
{
    printf("Le conducteur %s a fini de se reposer, il peut donc realiser un contrat\n", courant.nom);
    char *liste_entreprise_de_contract[3];
    int revenu_pour_contrat[3];
    int km_contract[3];
    int destination[3];
    tirage_des_contracts(3, liste_entreprise_de_contract, revenu_pour_contrat, km_contract, destination, courant.position, matrice_adja);
    printf("%s coûtera %1.1f euros par kilomètre.\n\n", courant.nom, courant.cout_au_km);
    for (int j = 0; j < 3; j++)
    {
        printf("L'entreprise %s vous propose un contrat pour %d km à %d euros en destination de %s.\n", liste_entreprise_de_contract[j], km_contract[j], revenu_pour_contrat[j], nom_ville[destination[j]]);
    }
    printf("\n\nVeuillez choisir l'un de ces contrats en ecrivant 1, 2 ou 3.\n");
    int choix;
    choix = get_int_in_input_in_range(1, 3);
    courant = deplacement(courant, int_random() % 10, km_contract[choix - 1], pointeur_du_capital);
    *pointeur_du_capital = *pointeur_du_capital + revenu_pour_contrat[choix - 1];
    return courant;
}
/*
void gestion_evenement_aleatoire(float *pointeur_du_capital)

 * @brief gere les evenements aleatoire
 *il ont 10% de chance de se produire lorsque que l'on realise un contract
 *
 
{
    if (int_random() % 10 == 9)
    {
        int nb_evenement = int_random() % 10;
        printf("%s\n", evenement_aleatoire(nb_evenement));
        *pointeur_du_capital = *pointeur_du_capital - prix_evenement_aleatoire(nb_evenement);
    }
}
*/
int salaire (float *capital,struct conducteur (*a)[10], int nombre_de_conduct)
// Dans cette fonction on regarde le nombre de kilomètre que les conducteurs ont parcourus
// Ainsi chaque tranche de 10 000 KM ils perçoivent une augmentation de salaires. 
{
    int salaire = 0;
	for (int y = 0; y <nombre_de_conduct; y ++)	
	{
        
        if (((*a)[y].compteur_km >= 0) && ((*a)[y].compteur_km <= 10000))
        {
            *capital = *capital - 1600;
            salaire = salaire + 1600;
        }
        else{
		if (((*a)[y].compteur_km > 10000) && ((*a)[y].compteur_km <= 20000))
		{
			*capital = *capital - 1800;
            salaire = salaire + 1800;
		}
        else {
		if (((*a)[y].compteur_km > 20000) && ((*a)[y].compteur_km <= 30000))
		{
			*capital = *capital - 2000;
            salaire = salaire + 2000;
		}
        else {
		if (((*a)[y].compteur_km > 30000) && ((*a)[y].compteur_km <= 50000))
		{
			*capital = *capital - 2400;
            salaire = salaire + 2400;
		}
		else 
		{
			*capital = *capital - 2600;
            salaire = salaire + 2600;
		};
        }
        }
        }
	};
    return salaire;
};



void ajout_conducteur(int nombre_de_conduct, struct conducteur (*a)[10],int *nb_conducteur, float *capitale)
{
    printf("Tapez 1 si vous voulez engager un nouveau conducteur (rappel : cela vous coutera 90 000 euros).");
    int var_validation1 = get_int_in_input_in_range(0, 1);
    if (var_validation1 == 1)
    {
        struct conducteur proposition_conduc[3];
        for(int i = 0; i<3; i++){
            proposition_conduc[i].id = nombre_de_conduct + 1;
            // conduct1.nom = nom_au_hasard();
            strcpy(proposition_conduc[i].nom, nom_au_hasard());
            proposition_conduc[i].cout_au_km = 0.5 + ((float)(int_random() % 10) / 10.);
            proposition_conduc[i].jour_de_repos = 0;
            proposition_conduc[i].compteur_km = 0;
            proposition_conduc[i] = ville_aleatoire(proposition_conduc[i], NOMBRE_DE_VILLES);
        }

        printf("On vous propose 3 conducteurs");
        printf("Le premier se nomme %s a un cout par kilomètre de %f et se trouve actuellement dans la ville de %d.\n", proposition_conduc[0].nom, proposition_conduc[0].cout_au_km, proposition_conduc[0].position);
        printf("Le second se nomme %s a un cout par kilomètre de %f et se trouve actuellement dans la ville de %d.\n", proposition_conduc[1].nom, proposition_conduc[1].cout_au_km, proposition_conduc[1].position);
        printf("Le troisieme se nomme %s a un cout par kilomètre de %f et se trouve actuellement dans la ville de %d.\n", proposition_conduc[2].nom, proposition_conduc[2].cout_au_km, proposition_conduc[2].position);

        int var_validation2;
        printf("Tapez 1, 2 ou 3 pour choisir un conducteur. Sinon vous ne pourrez pas choisir un nouveau conducteur.");
        var_validation2 = get_int_in_input_in_range(1, 3);
        *nb_conducteur = *nb_conducteur + 1;
        *capitale = *capitale-90000;
        // struct conducteur nv = {conduct1.id,conduct1.position,0,conduct1.cout_au_km,0,conduct1.nom};
        (*a)[nombre_de_conduct] = proposition_conduc[var_validation2-1];

        
    }
}

void affichage_menu(int * nombre_de_tour, float * capital,int * contract_real)
{
    printf("\n*************************************************\n");
    printf("Votre capital est de %f euros.\n",*capital);
    printf("\nMenu\n");
    if (*contract_real == 0)
        {printf("(A)ttribuer un contrat à vos conducteur\n");}
    else
        {printf("Vous avez déjà attribué des contrats à vos conducteurs.\n");}
    //printf("(L)icencier un conducteur(en DLC)\n");
    if (*nombre_de_tour % 20 != 0)
    {
        printf("Vous pourrez engager un nouveau conducteur dans %d tours.\n",20 - (*nombre_de_tour % 20));
    }
    else
    {
        printf("(E)ngager un nouveau conducteur\n");
    }
    printf("(P)asser au tour suivant\n");
    printf("(Q)uitter le jeu");
  
}

char get_a_char()
{
    char my_result;
    viderBuffer();
    scanf("%c",&my_result);
    return my_result;
}




int main()
// boucle principale du jeu
{
    char reponse1;
    static float capital ;
    float *pointeur_du_capital = &capital;
    int nombre_de_conduct;
    int nombre_de_tour = 0;
    struct conducteur a[10] = {// on definit une liste de conducteur avec 10 conducteur maximum
        {1, 1, 0, 1.1, 0, "jean-michel"}};
    init_random();
    printf("Le jeu va démarrer, voulez vous charger une sauvegarde ? (O)oui/(N)non\n");
    scanf("%c", &reponse1);
    while (reponse1!='N' && reponse1!='O')
    {
        printf("Le choix est invalide.\n");
        printf("Le jeu va démarrer, voulez vous charger une sauvegarde ? (O)oui/(N)non\n");
        scanf("%c", &reponse1);
    }
    if (reponse1 == 'N')
    {
        printf("**********************************************************************************************\n");
        printf("Initialisation des données de base du jeu\n");
        printf("**********************************************************************************************\n");
        capital = 10000.0;

 
        nombre_de_conduct = 1; 

    }
    else 
    {



        FILE * document;
        document = fopen("sauvegarde.txt", "r");
        if(document != NULL){
        import_sauvegarde(pointeur_du_capital, &nombre_de_conduct, &a,document);
        }
        else
        {
            printf("Aucune sauvegarde trouvée\n\n");
            printf("Initialisation des données de base du jeu\n"); 
            *pointeur_du_capital = 10000.0;



        } 
    }
    printf("**********************************************************************************************\n");
    printf("début de import csv\n");
    printf("**********************************************************************************************\n");
    static char *nom_ville[NOMBRE_DE_VILLES];
    static int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES];
    import_csv(nom_ville, matrice_adja);
    printf("**********************************************************************************************\n");
    printf("Initialisation des données du jeu terminé\n");
    printf("************************************************************************************************\n");
    // Début des tours
    int out = 1;

    //int tour_avant_prochain_conducteur =20;
    int prochain_tour=0;
    int contract_real;
    do
    {
        contract_real = 0;
        system("clear");
        printf("Vous êtes au tour %d.\n",nombre_de_tour);
        if (nombre_de_tour == 0 || nombre_de_tour % 30 != 0  )
        {
            printf("Un salaire sera versé à vos conducteurs dans %d tours.\n",30 -(nombre_de_tour % 30));
        }
        else
        {
            int b = salaire (pointeur_du_capital,&a, nombre_de_conduct);
            printf("************************************************************************************************\n");
            printf("Les salaires ont été versé à vos employés, vous avez perdu %d euros.\n", b); 
            printf("************************************************************************************************\n");

        }
        prochain_tour = 0 ;
        for (int i = 0; i < nombre_de_conduct; i++)
        {
            if (a[i].jour_de_repos>0)
                a[i].jour_de_repos = a[i].jour_de_repos - 1;
        }
        
        do
        {
            
            affichage_menu(&nombre_de_tour,&capital,&contract_real);


            char option='O';

            do
            {
                printf("\nEntrez votre choix :\n");
                option = get_a_char();
                

                if (option!='A' /*&& option!='L' */&& option!='E' && option!='P'&& option!='Q')
                {
                    printf("\n --- L'option choisie n'existe pas --- \n ");
                }
            } while (option!='A' /*&& option != 'L' */&& option!='E' && option!='P' && option!='Q');
            //printf("\n%c\n", option);
            switch (option)
            {
            case 'A':
                    if (contract_real == 0)
                    {
                        for (int i = 0; i < nombre_de_conduct; i++)
                        {// pour chacun des conducteur on teste s'il sont repose si oui, on leur assigne un nouveau contrat
                        // sinon on decremente leur jours de repos
                        
                        printf("\nConducteur : %s\n Numero : %d\n Position : %d\n Compteur : %d\n Cout/km : %1.1f\n Jours de repos : %d\n\n", a[i].nom, a[i].id, a[i].position, a[i].compteur_km, a[i].cout_au_km, a[i].jour_de_repos);
                        if (a[i].jour_de_repos == 0)
                        {
                            a[i] = gestion_contrat(a[i], pointeur_du_capital, matrice_adja, nom_ville);
                            gestion_evenement_aleatoire(pointeur_du_capital);
                        }
                        printf("Votre entreprise possède : %1.2f euros.\n\n", capital);
                        }
                        contract_real = 1;
                    }
                    else
                    {
                        printf("Cette option n'est plus disponible pour ce tour.");
                    }
                    break;
            case 'E': 
                    if (nombre_de_conduct<10)
                    {
                        if (capital>= 90000)
                        {
                            ajout_conducteur(nombre_de_conduct, &a, &nombre_de_conduct, &capital);
                        }
                        else
                        {
                            printf("Votre capital n'est pas suffisant pour embaucher un nouveau conducteur.\n");
                            printf("Pour rappel, il faut que votre capital soit d'au moins 90 000 euros pour pouvoir financer un nouveau conducteur et son materiel.");
                        }
                    }
                    else
                    {
                        printf("Vous ne pouvez pas disposer de plus de 10 conducteurs.");
                    }

                    break;
            case 'P':
                prochain_tour = 1;
                    break;
            case 'Q':
                    out = 0;
                    sauvegarder(capital, nombre_de_conduct, a);
                    for(int i = 0; i< NOMBRE_DE_VILLES; i++){
                        free(nom_ville[i]);
                        }
                    return 0;
            
            default:
                break;
            }
            
        } while (prochain_tour==0);
        
    nombre_de_tour++;

    } while (out==1);
    
    system("clear");
    return 0;

    /*
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
    printf("souhaitez vous importez une sauvegarde, si celle ci existe ? 1 = oui 0 = non\n");
    int choix_sauv = get_int_in_input_in_range(0, 1);
    if (choix_sauv == 1)
    {
        FILE * document;
        document = fopen("sauvegarde.txt", "r");
        if(document != NULL){
        import_sauvegarde(pointeur_du_capital, &nombre_de_conduct, &a,document);
        }
        else
        {
            printf("aucune sauvegarde trouvee\n");
        }
    }

    int nombre_de_tour = 0;
    while (code_action != 0)
    {
        printf("vous etes actuellement au tour numero %d\n", nombre_de_tour); // debut d'ajout de code (matthieu le 08.03.2022)
        nombre_de_tour++;
        if (nombre_de_tour % 30 == 0)
        {
            int b = salaire (&capital,&a, nombre_de_conduct);
            printf("Les salaires ont été versée au vos employés, vous avez perdus %d € \n", b); 
        }
        
        if (nombre_de_tour % 20 == 0 && nombre_de_conduct < 10 && capital>= 90000)
        {
            ajout_conducteur(nombre_de_conduct, &a, &nombre_de_conduct, &capital);
            
        } // fin d'ajout de code (matthieu le 08.03.2022)

        printf("Votre entreprise possede : %1.2f\n\n", capital); // on affiche le capital a chaque boucle
        for (int i = 0; i < nombre_de_conduct; i++)
        { // pour chacun des conducteur on teste s'il sont repose si oui, on leur assigne un nouveau contrat
            // sinon on decremente leur jours de repos
            printf("NOMBRE DE JOUR DE REPOS : %d", a[i].jour_de_repos);
            printf("conducteur : %s id: %d, position : %d, compteur : %d, coutkm : %1.1f, jour de repos : %d\n", a[i].nom, a[i].id, a[i].position, a[i].compteur_km, a[i].cout_au_km, a[i].jour_de_repos);
            if (a[i].jour_de_repos == 0)
            {
                a[i] = gestion_contrat(a[i], pointeur_du_capital, matrice_adja, nom_ville);
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
    for(int i = 0; i< NOMBRE_DE_VILLES; i++){
        free(nom_ville[i]);
    }
    return 0;*/
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


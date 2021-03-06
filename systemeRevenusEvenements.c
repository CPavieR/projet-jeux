#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "systemeRevenusEvenements.h"
#include "dijkstra.h"

static int a;
static int *pointeur_rand = &a;
void init_random()
{
    *pointeur_rand = time(NULL);//on creer une graine pour la generation des nombre aleatoire.
    // afaire avant d'utiliser l'aleatoire
}

int int_random(void)
{
    *pointeur_rand = (1103515245 * *pointeur_rand + 12345) % 2147483647;
    if (*pointeur_rand < 0)//on part du dernier nom aleatoire tire et on s'en sert afin d'en generer un nouveau
    {//ce dernier est conserve entre les appels de fonctions car la variable est statique
        *pointeur_rand = -*pointeur_rand;
    }
    return (*pointeur_rand);
}

float cout_au_hasard()
{ // Fonction pour génerer le coût total d'un camionneur à l'entreprise (basé sur le coût réel -> essence + salaire + impôt)
    float j = 0;
    j = (int_random() % 9) + 11; // on veut un coût entre 1.1 et 1.9 euros par kilomètres par conducteur, on prend un nombre random entre 0 et 8 compris, on ajoute 7 (pour avoir entre 7 et 15)
    return j / 10.0;             // et pour finir on divise par 10 pour avoir entre 1.1 et 1.9
}

char *nom_au_hasard()
{                                                                                                                                        // Fonction pour génerer un nom "au hasard" parmis les 30 suivants :
    char *noms[30] = {"Michel", "Josué", "Anguerrande", "Josselin", "Foulque", "Frederic", "David", "Jean-Gertrude", "Liam", "Vladimir", // on commence par créer le tableau noms
                    "William", "Sophia", "Nathan", "Léo", "Emma", "Logan", "Florence", "Thomas", "Noah", "Félix",
                    "Edouard", "Victor", "Dylan", "Louis", "James", "Ethan", "Benjamin", "Gabriel", "Rose", "Nolan"};
    return noms[int_random() % 30]; // On prend un nombre au hasard entre 0 et 29 compris qui nous permet de prendre un nombre au hasard dans le tableau
}

char *evenement_aleatoire(int n)
{ // création d'une fonction pour générer un évènement àléatoire, ces évènements seront liés à leur coût dans la fonction prix_evenement_aleatoire (même variable d'entrée n)
    char *evenements[10] = {"Un de votre camion s'est retrouvé enlisé sur une aire d'autoroute, votre conducteur est obligé d'appeler et de payer un dépanneur car il transportait des denrées périssables. Vous perdez 180€",
                            "Un de vos camions a acquis une conscience et a pris en otage son conducteur et vos marchandises en échange de sa liberté. Vous lui promettez un entretien plus fréquent et un plein d'essence. Il accepte par dépit et vous perdez 300€",
                            "En arrivant ce matin à votre bureau, vous remarquez que des marchandises sont devant vos locaux. Aucun message de l'expéditeur et vous avez effectué toutes vos courses. Vous revendez ces marchandises et gagnez 2500€",
                            "Un de vos camion a un pneu crevé et vous devez le remplacer. Vous perdez 600€",
                            "L'un de vos conducteurs a percuté un sanglier en passant sur une route de nuit et vous devez remplacer le pare-choc et un phare avant. Vous perdez 250€",
                            "L'un de vos donducteurs en situation d'ébriété a conduis votre camion et est rentré dans un platane centenaire. Le conducteur est par miracle indemne mais on ne peut pas en dire autant de votre camion. Les réparations vous coûtent 6000€",
                            "un de vos concurrent a fait faillite, vous gagnez beaucoup de parts sur le marché et empochez un beau pactole. Vous gagnez 8000€",
                            "Vous avez oublié de déclarer 27 centimes de bénéfices, le FISC vous tombe dessus. Vous devez payer 135€ d'amende.",
                            "Suite à une erreur de la banque, il semblerait que vous ayez un moins-perçu et que vous gagnez ainsi 2000€",
                            "Suite à une erreur de la banque, il semblerait que vous ayez un trop-perçu et que vous perdez ainsi 200€"
                            };
    return evenements[n]; // On prend l'un des 10 évènement aléatoire du tableau evenements
}

void tirage_des_contracts(int nb_contract, char *liste_entreprise[], int *revenu_de_contr, int *km, int * destination, int emplacement, int matrice_adja[NOMBRE_DE_VILLES][NOMBRE_DE_VILLES])
/***
 * @brief permet de generet un nombre de nombres definis de contrat
 *entre : nb de contrat a generer, tableau de tacleau de char pour les noms d'entreprise, int* pour les revenue associe, int* pour le nombre de km pour chaque contrat
 */
{
    for (int i = 0; i < nb_contract; i++)
    {
        liste_entreprise[i] = entreprise();
        do{
        destination[i] = (int_random()%12) + 1;}
        while(destination[i] == emplacement);
        
        km[i] = dijkstra(matrice_adja, emplacement, destination[i]);
        //printf("km : %d\n",km[i]);
        revenu_de_contr[i] = prix_contrat(km[i]);
        
    }
}


int prix_evenement_aleatoire(int n)
{ // création d'une fonction pour récupérer le cout de l'évènement aléatoire de la fonction evenement_aleatoire
    int prixEvenement[10] = {-180, -300, +2500, -600, -250, -6000, +8000, -135, +2000, -200};
    return prixEvenement[n]; // On prend l'évènement aléatoire du tableau prixEvenement qui correspond à l'évènement aléatoire généré
}

char *entreprise()
{ // Création d'une fonction pour prendre aléatoirement un nom d'une entreprise ci-dessous pour générer une propostion de contrat
    char *entreprises[34] = {"Aldimanche", "Zonama", "ThunderCrow", "Auchampignons", "ResearchDoor",
                            "Big Pharma & co.", "Ccher", "Chauchea", "Hexathlon", "Boing Boing",
                            "Cognition R&D dept", "Fromageries Bell", "Order Of Seven Angles", "Gigi", "Goose Chasing Ind.",
                            "SPC-3008 ", "Jardiflat", "Singularity Humanity Project co.", "Le roi Martin", "Psiion 3b Project inc.",
                            "Micromaniaque", "Nosilbe", "Pak", "Marque numero 826", "Vim4ever", "Evil Corp", "Reffined Uranium & co.",
                            "Leclaire", "Stalinium steel works", "Vaticannus collegium", "Windaube", "SGF2ZSBhIG5pY2UgZGF5Lg==", "Astaroth cult inc.", "Hunda",
                            };
    return entreprises[int_random() % 34 + 0]; // On prend l'un des 34 noms du tableau entreprises
}

int prix_contrat(int a)
{ // Création d'une fonction pour générer un revenu aléatoire compris entre 6 000 et 9 000€
    return (a * 2.0 + (((int_random()%10) -5) * 50));
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
        *pointeur_du_capital = *pointeur_du_capital + prix_evenement_aleatoire(nb_evenement);
    }
}
/*int main() {
    rnd_srand();
    //printf("%s coûtera %f euros par kilomètre. L'entreprise %s vous propose un contrat à %d. Par ailleurs, %s, %d\n",nom_au_hasard(n), cout_au_hasard(), entreprise(), prix_contrat(), evenement_aleatoire(n), (prix_evenement_aleatoire(n)));
    for (int i=0; i <= 20; i++) {
        int n=int_random()%10;
        printf("%s coûtera %f euros par kilomètre. L'entreprise %s vous propose un contrat à %d. Par ailleurs, %s, %d\n",nom_au_hasard(n), cout_au_hasard(), entreprise(), prix_contrat(), evenement_aleatoire(n), (prix_evenement_aleatoire(n)));
    };
    return 0;
}*/



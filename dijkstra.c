#include <stdio.h>
#include <stdlib.h>
#define NOMBRE_DE_VILLE 16
// Cette fonction permet de connaitre si une valeur représenter par val est présente dans une liste li. Cette fonction renvoie une valeur booleen
_Bool is_not_in(int li[NOMBRE_DE_VILLE], int val)
{
    for (int y = 0; y < NOMBRE_DE_VILLE; y++)
    {
        if (li[y] == val)
        {
            return 0;
        }
    }
    return 1;
}

int dijkstra(int matrice[NOMBRE_DE_VILLE][NOMBRE_DE_VILLE], int depart, int arrivee)
{

    // debut d'initialisation des listes et indices à utiliser dans l'algorithmes
    int lst_V[NOMBRE_DE_VILLE];  // liste des sommets considérés comme vus
    int lst_Av[NOMBRE_DE_VILLE]; // liste des sommets à voir
    int ind_lst_Av = 0;          // Cette valeur est un indice afin de savoir dans quel endroit de la liste en est, en effet, il est embêtant supprimer les éléments d'une liste en C
    // Liste des distances en partant vers le sommets avec le derniers sommet à atteindre
    int lst_D[NOMBRE_DE_VILLE][2];

    // Dans cette boucle for, in initialise tout les valeurs avec le max d'un int et NULL afin de pour voir manipulier plus facilement la liste lst_D par la suite
    for (int i = 0; i < NOMBRE_DE_VILLE; i++)
    {
        // Ce nombre est la limite d'un int, il permet de "simuler" une taille trop grande pour quelle soit emprunter 
        //j'ai décider de mettre ce nombre car une valeur infini n'existe pas en C
<<<<<<< HEAD
        lst_D[i][0] = -1;
=======
        lst_D[i][0] = 2147483647;
>>>>>>> 3d5f8770364807b1a71da86331da11fc7668a74e
        // Ce nombre permet de dire qu'il n'y a pas de voisins. Je n'ai pas pus mette NULL car cela renvoyai des Warnings
        lst_D[i][1] = 0;
    }
    // Initialisation des valeurs de départs
    //Initialisation des valeurs du seul sommet connu pour l'instant qui est le sommet depart
    // Il faut 0 KM pour faire aller de départ à départ
    lst_D[depart][0] = 0;
    //Le derniers sommets avant d'arrivé au départ et lui même
    lst_D[depart][1] = depart;
    // On met depart dans la liste des sommet à voir
    lst_Av[ind_lst_Av] = depart;
    // Tant que la liste des sommets à voir n'est pas vide
    while (ind_lst_Av < NOMBRE_DE_VILLE)
    {
        // permet d'ajouter un element à la liste des vue l'élément
        lst_V[ind_lst_Av] = lst_Av[ind_lst_Av];
        
        int ind_a_ajouter = ind_lst_Av + 1;// cette indice va servir à ajouter des élements dans la liste à voir
        for (int i = 0; i < NOMBRE_DE_VILLE; i++)
        {
            if (matrice[ind_lst_Av][i] != 0)
            {
<<<<<<< HEAD
                if (lst_D[i][0] <0 && lst_D[i][1] == 0)
=======
                if (lst_D[i][0] == 2147483647 && lst_D[i][1] == 0)// en regarde si l'élément est initialiser
>>>>>>> 3d5f8770364807b1a71da86331da11fc7668a74e
                {
                    //si l'élément n'est pas initialiser alors on l'initialise
                    lst_D[i][0] = lst_D[ind_lst_Av][0] + matrice[ind_lst_Av][i];
                    lst_D[i][1] = ind_lst_Av;
                    // printf("Initialisation pour la premiere fois de cette valeur a %d\n",lst_D[i][0]);
                }
                else
                {
                    // si il est initialiser alors on regarde si il doit être mis à jour
                    if (lst_D[ind_lst_Av][0] + matrice[ind_lst_Av][i] < lst_D[i][0])
                    {
                        lst_D[i][0] = lst_D[ind_lst_Av][0] + matrice[ind_lst_Av][i];
                        lst_D[i][1] = ind_lst_Av;
                    }
                }
            }
            // si un élément n'est pas dans la liste des vue ou dans la liste des A voir alors elle est ajouter dans la liste des à voir
            if (is_not_in(lst_Av, ind_lst_Av) && is_not_in(lst_V, ind_lst_Av)) //
            {
                // printf("ligne %d\n",ind_lst_Av);
                // printf("colonne %d\n",i);
                // printf("%d\n",matrice[ind_lst_Av][i]);
                lst_Av[ind_a_ajouter] = ind_lst_Av;
            }
        }

        ind_lst_Av++;//on passe à l'élément suivant
    }
    //printf("%d", lst_D[arrivee][0]);
    return (lst_D[arrivee][0]);
}

/*int main()
{
        int matrice[NOMBRE_DE_VILLE][NOMBRE_DE_VILLE] = {{0,5,8},{5,0,10},{8,10,0}};
        dijkstra(matrice,0,2);
        return 0;
}*/

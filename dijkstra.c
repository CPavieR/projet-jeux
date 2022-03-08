#include <stdio.h>
#include <stdlib.h>
#define NOMBRE_DE_VILLE 16
//Cette fonction permet de connaitre si une valeur représenter par val est présente dans une liste li. Cette fonction renvoie une valeur booleen
_Bool is_not_in(int li[NOMBRE_DE_VILLE],int val)
{
    for (int y=0; y<NOMBRE_DE_VILLE;y++)
    {
        if (li[y]==val)
        {
            return 0;
        }
    }
    return 1;
}

int dijkstra(int matrice[NOMBRE_DE_VILLE][NOMBRE_DE_VILLE],int depart , int arrivee)
{

    //debut d'initialisation des listes et indices à utiliser dans l'algorithmes
    int lst_V [NOMBRE_DE_VILLE];//liste des sommets considérés comme vus
    int lst_Av[NOMBRE_DE_VILLE];// liste des sommets à voir
    int ind_lst_Av = 0;//Cette valeur est un indice afin de savoir dans quel endroit de la liste en est.
    //Liste des distances en partant vers le sommets avec le derniers sommet à atteindre
    int lst_D[NOMBRE_DE_VILLE][2];

    //Dans cette boucle for, in initialise tout les valeurs avec le max d'un int et NULL afin de pour voir manipulier plus facilement la liste lst_D par la suite
    for (int i = 0; i<NOMBRE_DE_VILLE; i++)
    {
        lst_D[i][0]=2147483647;
        lst_D[i][1]=0;
    }
    //Initialisation des valeurs de départs
    lst_D[depart][0]=0;
    lst_D[depart][1]=depart;
    lst_Av[ind_lst_Av] = depart;
    while (ind_lst_Av<NOMBRE_DE_VILLE)
    {
        //permet d'ajouter un element à la liste des vue l'élément
        lst_V[ind_lst_Av] = lst_Av[ind_lst_Av];
        int ind_a_ajouter = ind_lst_Av+1;
        for (int i = 0; i < NOMBRE_DE_VILLE ; i++)
        {
            if (matrice[ind_lst_Av][i]!=0)
            {
                if(lst_D[i][0] == 2147483647 && lst_D[i][1]==0)
                {
                    lst_D[i][0] = lst_D[ind_lst_Av][0] + matrice[ind_lst_Av][i];
                    lst_D[i][1] = ind_lst_Av;
                    //printf("Initialisation pour la premiere fois de cette valeur a %d\n",lst_D[i][0]);
                }
                else
                {
                    if (lst_D[ind_lst_Av][0] + matrice[ind_lst_Av][i] < lst_D[i][0]  )
                    {
                        lst_D[i][0] = lst_D[ind_lst_Av][0] + matrice[ind_lst_Av][i];
                        lst_D[i][1] = ind_lst_Av;
                    }
                }
            }
            //si un élément n'est pas dans la liste des vue ou dans la liste des A voir alors elle est ajouter dans la liste des à voir
            if (is_not_in(lst_Av,ind_lst_Av) && is_not_in(lst_V,ind_lst_Av))//
            {
                //printf("ligne %d\n",ind_lst_Av);
                //printf("colonne %d\n",i);
                //printf("%d\n",matrice[ind_lst_Av][i]);
                lst_Av[ind_a_ajouter] = ind_lst_Av;
            }
        }

        ind_lst_Av++;

    }
printf("%d",lst_D[arrivee][0]);
return (lst_D[arrivee][0]);
}

int main()
{
        int matrice[NOMBRE_DE_VILLE][NOMBRE_DE_VILLE] = {{0,5,8},{5,0,10},{8,10,0}};
        dijkstra(matrice,0,2);
        return 0;
}

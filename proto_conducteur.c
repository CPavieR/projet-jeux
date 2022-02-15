#include <stdio.h>
#include <stdlib.h>
//initalisation d'une nouvelle structure, c'est structure est peut avoir à des changements dans le future.
//Pour l'instant cette structure possède un id, une position dans le graphe, un compteur de kilomètre et le cout au KM du
//conducteur. J'ai essaiyé de compiler avec un chaine de caractère (pour un nom) mais la chaine de char empêchait le compilation (elle est en commentaire)
//sinon le structure fonctionne
struct conducteur {
int id;
int position;
int compteur_km;
//char nom[];
int cout_au_km;
};


//permet de généré un revenue en 0,0 et 2,0 de manière aléatoire
float cout_au_hasard() {
    float j=0;
    j=(rand()%20);
    return j/10.0;
}


//cette fonction permet de déplacement le conducteur dans le graphe attention cette fonctionne fais pas attention si elle peut
//faire le déplacement.Il faudra donc rajouter un fonction afin de prévoir les déplacements à faire.
struct conducteur deplacement(struct conducteur conducteur_a_deplacer, int deplacement,int matrice[4][4])//Fonction operationnel
{   //on incrémenter le compteur de KM vers l'endroit où on va faire le déplacement
    conducteur_a_deplacer.compteur_km = conducteur_a_deplacer.compteur_km + matrice[conducteur_a_deplacer.id][deplacement];
    //on fait le déplacemnt
    conducteur_a_deplacer.position = deplacement;
    return (conducteur_a_deplacer);//on retourne le struct aprés le déplacement
}

//Fonction basique qui reset le compteur de KM
struct conducteur reset_compteur (struct conducteur cpt)//Fonction operationnel
{
    cpt.compteur_km = 0;//On réinitialise simplement de compteur en le mettant à 0
    return cpt; // on retourn de résultat
};


//Permet de calculer le cout du compteur de KM du conducteur
int calcule_cout (struct conducteur cpt)//Fonction operationnel
{
    return cpt.cout_au_km*cpt.compteur_km;// on retoure simplement le cout au KM fois le nombre de KM
};


//Cette Fonction permet de générer des nombres aléatiore grace un l'import de la bibliothèque stdlib.h
//Cette fonction est utile pour la génération/initialisation alétoire de conducteur
//Nombre ville est le nombre exact de ville (est non le nombre de ville-1 comme si on était dans une liste)
struct conducteur ville_aleatoire (struct conducteur cpt,int nombre_ville)//Fonction operationnel
{
   int nombre = rand() % nombre_ville + 1;// on génèrent un nombre en 0 et le nombre de ville si il y a 4 ville l'intervalle sera [0,3]
   cpt.position = nombre;// change le position dans la structure concerné
   printf("%d\n",cpt.position);//un printf pour vérifier le résulatat et bon
   return cpt;//on retourne notre résulat
};


int main()//fonction main qui permet d'éffectuer les tests
{
    int ma_matrice_test[4][4] = {{1,6,8,4},{2,6,4,9},{8,5,1,6},{7,9,4,1}};//initialisatoin d'une matrice en 4*4
    struct conducteur cfgh ;//initialisation d'une struct conducteur
    cfgh.id = 0;
    cfgh.position=0;
    cfgh.compteur_km=0;
    cfgh.cout_au_km = 1;
    cfgh = deplacement(cfgh,3,ma_matrice_test);//déplacement d'un conducteur
    printf("%d\n",cfgh.compteur_km);//verif que le compteur se soit bien incrémenter
    printf("%d",cfgh.position);//verif que le positoin se soit bien changer
    for (int i=0; i<=50;i++)//test pour voir si la foncction ville_aleatoire fonctionne bien
    {
        ville_aleatoire(cfgh,4);
    }


}

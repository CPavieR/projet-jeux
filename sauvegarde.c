#include "sauvegarde.h"
#include "conducteur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sauvegarder(float capital, int nbr_conduc, struct conducteur *a)
{

    FILE *document;
    document = fopen("sauvegarde.txt", "w");

    char str[80];

    sprintf(str, "%1.2f", capital);

    fputs(str, document);

    sprintf(str, ";%d;\n", nbr_conduc);
    fputs(str, document);
    for (int i = 0; i < nbr_conduc; i++)
    {
        sprintf(str, "%d;%d;%d;%f;%d;%s\n", a[i].id, a[i].position, a[i].compteur_km, a[i].cout_au_km, a[i].jour_de_repos, a[i].nom);
        fputs(str, document);
    }
    fclose(document); // on ferme le document
};
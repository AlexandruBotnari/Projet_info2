#include "environnement.h"
#include <string.h>
#include <stdio.h>

Environnement charger_environnement(const char *chemin_fichier) {
    Environnement e;
    FILE* f = fopen(chemin_fichier, "r");

    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier : %s\n", chemin_fichier);
        strcpy(e.nom, "inconnu");
        strcpy(e.element_avantage, "aucun");
        strcpy(e.element_desavantage, "aucun");
        e.bonus = 0.0f;
        e.malus = 0.0f;
        return e;
    }

    fscanf(f, "%s %s %s %f %f",
           e.nom,
           e.element_avantage,
           e.element_desavantage,
           &e.bonus,
           &e.malus);

    fclose(f);
    return e;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "environnement.h"

Environnement charger_environnement(const char *chemin_fichier) {
    Environnement e;
    FILE* f = fopen(chemin_fichier, "r");

    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier : %s\n", chemin_fichier);
        strcpy(e.nom, "inconnu");
        strcpy(e.element_bonus, "aucun");
        strcpy(e.element_malus, "aucun");
        e.bonus = 0.0f;
        e.malus = 0.0f;
        return e;
    }

    fscanf(f, "%s %s %s %f %f",
           e.nom,
           e.element_bonus,
           e.element_malus,
           &e.bonus,
           &e.malus);

    fclose(f);
    return e;
}

Environnement choix_environnement() {
    int p;
    Environnement env;
    do {
        printf("Quel environnement voulez-vous ?\n"
               "0: Etna 🔥\n1: Nysa 🌲\n2: Keraunos ⚡\n3: Thalassa 🌊\n4: Olympe 🏔️\n"
               "5: Aulis 🌪️\n");
        scanf("%d", &p);
        while(getchar() != '\n'); // vide le buffer
    } while (p < 0 || p > 5);
    char *tab_environnement[] = {"etna.txt", "nysa.txt", "keraunos.txt", "thalassa.txt", "olympe.txt",
        "aulis.txt"};
    env = charger_environnement(tab_environnement[p]);
    return env;
}

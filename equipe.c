#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "equipe.h"
#include "menu.h"          
#include "combattant.h" 

extern int choix_personnage(); // fonction définie ailleurs
extern Combattant charger_combattant(const char *chemin_fichier);

Equipe creer_equipe() {
    Equipe e;
    char *tab_personnage[] = {
        "Artémis.txt", "Atlas.txt", "déméter.txt", "gaia.txt", "hélios.txt",
        "Héphaistos.txt", "Ouranos.txt", "poséidon.txt", "téthys.txt", "zeus.txt"
    };

    printf("Entrez le nom de votre équipe : ");
    fgets(e.nom, sizeof(e.nom), stdin);
    e.nom[strcspn(e.nom, "\n")] = 0;

    e.nb_combattants = 0;
    while (e.nb_combattants < 3) {
        int index = choix_personnage();
        e.combattants[e.nb_combattants] = charger_combattant(tab_personnage[index]);
        e.nb_combattants++;
    }
    return e;
}

void afficher_equipe(Equipe *e) {
    clearTerminal();
    printf("Équipe : %s\n", e->nom);
    for (int i = 0; i < e->nb_combattants; i++) {
        printf("Combattant %d : %s\n", i + 1, e->combattants[i].nom);
    }
}

void afficher_equipe_tour(Equipe *e) {
    printf("Équipe : %s\n", e->nom);
    for (int i = 0; i < e->nb_combattants; i++) {
        printf("Combattant %d : %s\n", i + 1, e->combattants[i].nom);
        printf("Vie: %d/%d\n", e->combattants[i].vie_courante, e->combattants[i].vie_max);
        printf("Charge: %d\n", e->combattants[i].charge);
    }
}

int equipe_est_vaincue(Equipe *e) {
    for (int i = 0; i < e->nb_combattants; i++) {
        if (e->combattants[i].vie_courante > 0) {
            return 0;
        }
    }
    return 1;
}



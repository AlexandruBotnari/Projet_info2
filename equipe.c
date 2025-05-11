#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipe.h"
#include "menu.h"        // pour clearTerminal()
#include "combattant.h"  // pour charger_combattant() et la structure Combattant

// 🧠 Crée une équipe avec un nom et 3 combattants choisis par l'utilisateur
Equipe creer_equipe() {
    Equipe e;

    // 📁 Liste des fichiers correspondant aux personnages disponibles
    char *tab_personnage[] = {
        "Artémis.txt", "Atlas.txt", "déméter.txt", "gaia.txt", "hélios.txt",
        "Héphaistos.txt", "Ouranos.txt", "poséidon.txt", "téthys.txt", "zeus.txt"
    };

    // 📝 Demande à l'utilisateur de donner un nom à son équipe
    printf("Entrez le nom de votre équipe : ");
    fgets(e.nom, sizeof(e.nom), stdin);
    e.nom[strcspn(e.nom, "\n")] = 0; // supprime le retour à la ligne

    // 👥 Ajout de 3 combattants choisis
    e.nb_combattants = 0;
    while (e.nb_combattants < 3) {
        int index = choix_personnage(); // menu de choix
        e.combattants[e.nb_combattants] = charger_combattant(tab_personnage[index]); // charge le perso choisi
        e.nb_combattants++;
    }

    return e;
}

// 👀 Affiche le nom de l'équipe et les noms de ses combattants
void afficher_equipe(Equipe *e) {
    clearTerminal(); // Nettoie le terminal avant l'affichage
    printf("Équipe : %s\n", e->nom);
    for (int i = 0; i < e->nb_combattants; i++) {
        printf("Combattant %d : %s\n", i + 1, e->combattants[i].nom);
    }
}

// 🔄 Affiche l'état de chaque combattant pendant le combat (PV et charge)
void afficher_equipe_tour(Equipe *e) {
    printf("Équipe : %s\n", e->nom);
    for (int i = 0; i < e->nb_combattants; i++) {
        printf("Combattant %d : %s\n", i + 1, e->combattants[i].nom);
        printf("Vie: %d/%d\n", e->combattants[i].vie_courante, e->combattants[i].vie_max);
        printf("Charge: %d\n", e->combattants[i].charge);
    }
}

// ☠️ Vérifie si tous les combattants de l'équipe sont morts
int equipe_est_vaincue(Equipe *e) {
    for (int i = 0; i < e->nb_combattants; i++) {
        if (e->combattants[i].vie_courante > 0) {
            return 0; // au moins un combattant est encore en vie
        }
    }
    return 1; // tous les combattants sont morts
}



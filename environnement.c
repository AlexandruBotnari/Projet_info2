#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "environnement.h"

// 📥 Fonction qui charge un environnement depuis un fichier texte
Environnement charger_environnement(const char *chemin_fichier) {
    Environnement e;

    // 📂 Ouvre le fichier en lecture
    FILE* f = fopen(chemin_fichier, "r");

    // ⚠️ Si le fichier ne s'ouvre pas, on renvoie un environnement par défaut
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier : %s\n", chemin_fichier);
        strcpy(e.nom, "inconnu");
        strcpy(e.element_bonus, "aucun");
        strcpy(e.element_malus, "aucun");
        e.bonus = 0.0f;
        e.malus = 0.0f;
        return e;
    }

    // 🧾 Lecture des données depuis le fichier : nom, bonus, malus et coefficients
    fscanf(f, "%s %s %s %f %f",
           e.nom,
           e.element_bonus,
           e.element_malus,
           &e.bonus,
           &e.malus);

    fclose(f); // 🔐 Fermeture du fichier
    return e;  // ✅ On renvoie l’environnement chargé
}

// 🎮 Fonction qui affiche un menu pour choisir l’environnement et le charge
Environnement choix_environnement() {
    int p;
    Environnement env;

    // 🔁 Répète jusqu'à ce que l'utilisateur choisisse un environnement valide
    do {
        printf("Quel environnement voulez-vous ?\n"
               "0: Etna 🔥\n1: Nysa 🌲\n2: Keraunos ⚡\n3: Thalassa 🌊\n4: Olympe 🏔️\n"
               "5: Aulis 🌪️\n");
        scanf("%d", &p);
        while(getchar() != '\n'); // vide le buffer clavier
    } while (p < 0 || p > 5);

    // 🗂️ Tableau contenant les noms de fichiers correspondants
    char *tab_environnement[] = {
        "etna.txt", "nysa.txt", "keraunos.txt", "thalassa.txt", "olympe.txt", "aulis.txt"
    };

    // 📥 Chargement du fichier choisi
    env = charger_environnement(tab_environnement[p]);

    return env; // 🔁 Retourne l’environnement chargé
}

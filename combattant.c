#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "combattant.h"

// 🔎 Affiche toutes les infos du combattant, y compris la technique spéciale
void afficher_combattant_tempo(Combattant c) {
    printf("Nom: %s\n", c.nom);
    printf("Vie: %d/%d\n", c.vie_courante, c.vie_max);
    printf("Attaque: %d\n", c.attaque);
    printf("Defense: %d\n", c.defense);
    printf("Agilité: %d\n", c.agilite);
    printf("Vitesse: %d\n", c.vitesse);
    printf("charge: %d\n", c.charge);
    printf("Élément: %s\n", c.element);
    printf("Nom Technique: %s\n", c.technique.nom);
    printf("Technique valeur: %d\n", c.technique.valeur);
    printf("type effet: %d\n", c.technique.type_effet);
    printf("description: %s\n", c.technique.description);
    printf("tour actifs: %d\n", c.technique.tours_actifs);
}

// 🧾 Affiche uniquement les infos de base du combattant (pour résumé rapide)
void afficher_combattant(Combattant c) {
    printf("Nom: %s\n", c.nom);
    printf("Vie: %d/%d\n", c.vie_courante, c.vie_max);
    printf("Attaque: %d\n", c.attaque);
    printf("Defense: %d\n", c.defense);
    printf("Agilité: %d\n", c.agilite);
    printf("Vitesse: %d\n", c.vitesse);
    printf("Élément: %s\n", c.element);
}

// 📥 Charge un combattant depuis un fichier texte (ex: Artémis.txt)
Combattant charger_combattant(const char *chemin_fichier) {
    Combattant c;

    FILE *f = fopen(chemin_fichier, "r");
    if (f == NULL) {
        // ⚠️ Si erreur d'ouverture du fichier, retourne un combattant vide
        printf("Erreur fopen\n");
        strcpy(c.nom, "inconnu");
        c.vie_max = c.vie_courante = c.attaque = c.defense = c.agilite = c.vitesse = 0;
        strcpy(c.element, "aucun");
        return c;
    }

    // 📖 Lecture des données dans le bon ordre
    fscanf(f,
        "%63s   %d %d %d %d %d %d %d   %31s   %63s   %d %d   \"%255[^\"]\"   %d %d %d",
        c.nom,
        &c.vie_max,
        &c.vie_courante,
        &c.attaque,
        &c.defense,
        &c.agilite,
        &c.vitesse,
        &c.charge,
        c.element,
        c.technique.nom,
        &c.technique.valeur,
        &c.technique.type_effet,
        c.technique.description,
        &c.technique.tours_actifs,
        &c.technique.recharge,
        &c.technique.recharge_restante
    );

    fclose(f);

    // Affiche les infos complètes pour debug/confirmation
    afficher_combattant_tempo(c);

    return c;
}

// 🎮 Menu de sélection de personnage via un index de 0 à 9
int choix_personnage() {
    int p;
    printf("Quel personnage voulez-vous :\n");
    printf("Artémis : 0\nAtlas : 1\nDéméter : 2\nGaia : 3\nHélios : 4\n");
    printf("Héphaïstos : 5\nOuranos : 6\nPoséidon : 7\nTéthys : 8\nZeus : 9\n");
    scanf("%d", &p);

    // ❌ Vérifie si le choix est valide
    if (p < 0 || p > 9) {
        printf("❌ Choix invalide, essayez encore.\n");
        while (getchar() != '\n');
    }

    return p;
}

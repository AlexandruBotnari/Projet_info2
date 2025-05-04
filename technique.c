#include <stdio.h>
#include <string.h>
#include "technique.h"
#include "combattant.h"

Combattant* choisir_cible(Combattant *liste, int nb, const char *type) {
    char nom_cible[50];
    printf("Choisissez une cible %s :\n", type);
    for (int i = 0; i < nb; i++) {
        printf("- %s (PV: %d/%d)\n", liste[i].nom, liste[i].vie_courante, liste[i].vie_max);
    }

    printf("Nom de la cible : ");
    scanf("%s", nom_cible);

    for (int i = 0; i < nb; i++) {
        if (strcmp(liste[i].nom, nom_cible) == 0) {
            return &liste[i];
        }
    }

    printf("Cible introuvable, action annulée.\n");
    return NULL;
}

void utiliser_technique_speciale(Combattant *utilisateur, Combattant *alliés, int nb_alliés, Combattant *ennemis, int nb_ennemis) {
    TechniqueSpeciale *tech = &utilisateur->techniques;

    if (tech->recharge_restante > 0) {
        printf("%s ne peut pas utiliser %s (recharge restante : %d tours)\n", utilisateur->nom, tech->nom, tech->recharge_restante);
        return;
    }

    // Choix de la cible
    Combattant *cible = NULL;
    if (tech->type_effet == 0) {
        cible = choisir_cible(ennemis, nb_ennemis, "ennemie");
    } else {
        cible = choisir_cible(alliés, nb_alliés, "alliée");
    }

    if (cible == NULL) return;

    printf("\n%s utilise %s sur %s !\n", utilisateur->nom, tech->nom, cible->nom);
    printf(">> %s\n", tech->description);

    switch (tech->type_effet) {
        case 0: // Attaque puissante
            cible->vie_courante -= tech->valeur;
            if (cible->vie_courante < 0) cible->vie_courante = 0;
            printf("%s subit %d dégâts ! PV restants : %d/%d\n", cible->nom, tech->valeur, cible->vie_courante, cible->vie_max);
            break;

        case 1: // Buff attaque
            cible->attaque += tech->valeur;
            cible->buff_attaque_tours = tech->tours_actifs;
            printf("%s gagne +%d en attaque pour %d tours !\n", cible->nom, tech->valeur, tech->tours_actifs);
            break;

        case 2: // Buff défense
            cible->defense += tech->valeur;
            cible->buff_defense_tours = tech->tours_actifs;
            printf("%s gagne +%d en défense pour %d tours !\n", cible->nom, tech->valeur, tech->tours_actifs);
            break;

        case 3: // Buff vitesse
            if (cible->vitesse + tech->valeur <= 4)
                cible->vitesse += tech->valeur;
                cible->buff_vitesse_tours = tech->tours_actifs;
            else
                cible->vitesse = 4;
            printf("%s gagne +%d en vitesse pour %d tours !\n", cible->nom, tech->valeur, tech->tours_actifs);
            break;

        case 4: // Soins
            cible->vie_courante += tech->valeur;
            if (cible->vie_courante > cible->vie_max)
                cible->vie_courante = cible->vie_max;
            printf("%s récupère %d PV ! PV actuels : %d/%d\n", cible->nom, tech->valeur, cible->vie_courante, cible->vie_max);
            break;
    }

    tech->recharge_restante = tech->recharge;
}

void fin_tour(Combattant *perso) {
    // Attaque
    if (perso->buff_attaque_tours > 0) {
        perso->buff_attaque_tours--;
        if (perso->buff_attaque_tours == 0) {
            perso->attaque = perso->attaque_base;
            printf("%s perd son bonus d'attaque.\n", perso->nom);
        }
    }

    // Défense
    if (perso->buff_defense_tours > 0) {
        perso->buff_defense_tours--;
        if (perso->buff_defense_tours == 0) {
            perso->defense = perso->defense_base;
            printf("%s perd son bonus de défense.\n", perso->nom);
        }
    }

    // Vitesse
    if (perso->buff_vitesse_tours > 0) {
        perso->buff_vitesse_tours--;
        if (perso->buff_vitesse_tours == 0) {
            perso->vitesse = perso->vitesse_base;
            printf("%s perd son bonus de vitesse.\n", perso->nom);
        }
    }

    // Recharge de la technique spéciale
    if (perso->techniques.recharge_restante > 0) {
        perso->techniques.recharge_restante--;
    }
}


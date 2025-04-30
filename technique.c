#include <stdio.h>
#include <string.h>
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
            printf("%s gagne +%d en attaque pour %d tours !\n", cible->nom, tech->valeur, tech->tours_actifs);
            break;

        case 2: // Buff défense
            cible->defense += tech->valeur;
            printf("%s gagne +%d en défense pour %d tours !\n", cible->nom, tech->valeur, tech->tours_actifs);
            break;

        case 3: // Buff vitesse
            if (cible->vitesse + tech->valeur <= 4)
                cible->vitesse += tech->valeur;
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

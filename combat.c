#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "combat.h"
#include "technique.h"
#include "menu.h" 

int choix_cible_a_attaquer(Equipe *defenseur) {
    int i;
    do {
        printf("Choisissez la cible à attaquer :\n");
        for (int j = 0; j < 3; j++) {
            printf("%d: %s (%d PV)\n", j, defenseur->combattants[j].nom, defenseur->combattants[j].vie_courante);
        }
        scanf("%d", &i);
        while(getchar() != '\n');
    } while ((i != 0 && i != 1 && i != 2) || defenseur->combattants[i].vie_courante <= 0);
    return i;
}

int calculer_degats_generique(int valeur_base, int valeur_defense,
                              const char *element_attaquant, const char *element_defenseur,
                              Environnement *env) {
    float coeff = 1.0;

    if (strcmp(element_attaquant, env->element_bonus) == 0 &&
        strcmp(element_defenseur, env->element_malus) == 0) {
        coeff *= env->bonus;
    } else if (strcmp(element_attaquant, env->element_malus) == 0 &&
               strcmp(element_defenseur, env->element_bonus) == 0) {
        coeff *= env->malus;
    }

    float degats_f = valeur_base - valeur_defense;
    if (degats_f < 1.0f) degats_f = 1.0f;

    return (int)round(degats_f * coeff);
}

void jouer_tour(Equipe *e1, Equipe *e2, Environnement *env) {
    OrdreCombattant ordre[6];
    int index = 0;

    for (int i = 0; i < 3; i++) {
        if (e1->combattants[i].vie_courante > 0) {
            e1->combattants[i].charge += e1->combattants[i].vitesse;
            ordre[index++] = (OrdreCombattant){&e1->combattants[i], e1, e2};
        }
    }
    for (int j = 0; j < 3; j++) {
        if (e2->combattants[j].vie_courante > 0) {
            e2->combattants[j].charge += e2->combattants[j].vitesse;
            ordre[index++] = (OrdreCombattant){&e2->combattants[j], e2, e1};
        }
    }

    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (ordre[i].combattant->agilite < ordre[j].combattant->agilite) {
                OrdreCombattant tmp = ordre[i];
                ordre[i] = ordre[j];
                ordre[j] = tmp;
            }
        }
    }

    for (int i = 0; i < index; i++) {
        Combattant *c = ordre[i].combattant;
        Equipe *att = ordre[i].equipe_att;
        Equipe *def = ordre[i].equipe_def;

        if (c->charge >= 4 && c->vie_courante > 0) {
            c->charge = 0;
            printf("\n✅ %s de l'équipe %s est prêt à attaquer !\n", c->nom, att->nom);

            if (c->technique.recharge_restante == 0) {
                int choix;
                do {
                    printf("Choisir action :\n1 - Attaque normale\n2 - Technique spéciale (%s)\n", c->technique.nom);
                    scanf("%d", &choix);
                    while(getchar() != '\n');
                } while (choix != 1 && choix != 2);

                if (choix == 2) {
                    utiliser_technique_speciale(c, att, def, env);
                    continue;
                }
            }

            int cible_i = choix_cible_a_attaquer(def);
            Combattant *cible = &def->combattants[cible_i];
            int degats = calculer_degats_generique(c->attaque, cible->defense, c->element, cible->element, env);
            if (degats < 0) degats = 0;

            cible->vie_courante -= degats;
            if (cible->vie_courante < 0) cible->vie_courante = 0;

            printf("%s attaque %s et inflige %d dégâts. PV restants : %d\n", c->nom, cible->nom, degats, cible->vie_courante);
        }
    }

    for (int i = 0; i < 3; i++) {
        Combattant *c = &e1->combattants[i];

        if (c->technique.recharge_restante > 0)
            c->technique.recharge_restante--;

        if (c->buff_attaque_tour > 0 && --c->buff_attaque_tour == 0)
            c->attaque = c->attaque_base;

        if (c->buff_defense_tour > 0 && --c->buff_defense_tour == 0)
            c->defense = c->defense_base;

        if (c->buff_agilite_tour > 0 && --c->buff_agilite_tour == 0)
            c->agilite = c->agilite_base;
    }
}

void jouer_combat(Equipe *e1, Equipe *e2, Environnement *env) {
    srand(time(NULL));
    int nb_tours = 0;

    while (!equipe_est_vaincue(e1) && !equipe_est_vaincue(e2)) {
        clearTerminal();
        nb_tours++;
        printf("Tours : %d\n", nb_tours);
        jouer_tour(e1, e2, env);
        sleep(1);
        printf("\n--- État après ce tour ---\n\n");
        sleep(1);
        afficher_equipe_tour(e1);
        afficher_equipe_tour(e2);

        int k = 0;
        do {
            printf("On passe au prochain tour?\n1-Oui✅\n2-Non❌\n");
            scanf("%d", &k);
            while(getchar() != '\n');
        } while (k != 1);
    }

    if (equipe_est_vaincue(e1)) {
        printf("\n🏆 Victoire de l'équipe %s !\n", e2->nom);
    } else {
        printf("\n🏆 Victoire de l'équipe %s !\n", e1->nom);
    }
}

void utiliser_technique_speciale(Combattant *utilisateur, Equipe *equipe_joueur, Equipe *equipe_adverse, Environnement *env) {
    TechniqueSpeciale *tech = &utilisateur->technique;

    if (tech->recharge_restante > 0) {
        printf("%s ne peut pas utiliser %s (recharge restante : %d tours).\n",
               utilisateur->nom, tech->nom, tech->recharge_restante);
        return;
    }

    Combattant *cible = NULL;

    if (tech->type_effet == 0) {
        int index = choix_cible_a_attaquer(equipe_adverse);
        cible = &equipe_adverse->combattants[index];
    } else {
        int k;
        do {
            printf("Sur quel allié appliquer %s ?\n", tech->nom);
            for (int i = 0; i < 3; i++) {
                printf("%d: %s\n%d PV\nAttaque: %d\nDéfense: %d\nAgilité: %d\n",
                    i,
                    equipe_joueur->combattants[i].nom,
                    equipe_joueur->combattants[i].vie_courante,
                    equipe_joueur->combattants[i].attaque,
                    equipe_joueur->combattants[i].defense,
                    equipe_joueur->combattants[i].agilite);
            }
            scanf("%d", &k);
            while(getchar() != '\n');
        } while (k < 0 || k > 2 || equipe_joueur->combattants[k].vie_courante <= 0);
        cible = &equipe_joueur->combattants[k];
    }

    printf("\n🌀 %s utilise %s sur %s !\n", utilisateur->nom, tech->nom, cible->nom);
    printf(">> %s\n", tech->description);

    switch (tech->type_effet) {
        case 0: {
            int degats = calculer_degats_generique(
                tech->valeur,
                cible->defense,
                utilisateur->element,
                cible->element,
                env
            );
            cible->vie_courante -= degats;
            if (cible->vie_courante < 0) cible->vie_courante = 0;
            printf("💥 %s subit %d dégâts ! PV restants : %d/%d\n", cible->nom, degats, cible->vie_courante, cible->vie_max);
            break;
        }
        case 1:
            cible->attaque += tech->valeur;
            cible->buff_attaque_tour = tech->tours_actifs;
            printf("⚔️ %s gagne +%d en attaque pour %d tours !\n", cible->nom, tech->valeur, tech->tours_actifs);
            break;
        case 2:
            cible->defense += tech->valeur;
            cible->buff_defense_tour = tech->tours_actifs;
            printf("🛡️ %s gagne +%d en défense pour %d tours !\n", cible->nom, tech->valeur, tech->tours_actifs);
            break;
        case 3:
            cible->agilite += tech->valeur;
            cible->buff_agilite_tour = tech->tours_actifs;
            printf("💨 %s gagne +%d en agilité pour %d tours !\n", cible->nom, tech->valeur, tech->tours_actifs);
            break;
        case 4:
            cible->vie_courante += tech->valeur;
            if (cible->vie_courante > cible->vie_max)
                cible->vie_courante = cible->vie_max;
            printf("❤️ %s récupère %d PV ! PV actuels : %d/%d\n", cible->nom, tech->valeur, cible->vie_courante, cible->vie_max);
            break;
    }

    tech->recharge_restante = tech->recharge;
}


#include <stdio.h>
#include <string.h>
#include "technique.h"
#include "combattant.h"
#include "environnement.h"

TechniqueSpeciale charger_TechniqueSpeciale(char *chemin_fichier){
	TechniqueSpeciale t;
	FILE* f;
	f=fopen(chemin_fichier,"r");
	if (f == NULL){
		printf("erreur fopen\n");
		strcpy(t.nom, "inconnu");
        strcpy(t.description, "aucun");
		t.valeur = t.type_effet = t.tours_actifs = t.recharge = t.recharge_restante = 0;
		return t;
	}
	fscanf(f, "%s %d %d \"%[^\"]\" %d %d %d",
           t.nom,
           &t.valeur,
           &t.type_effet,
           t.description,
           &t.tours_actifs,
           &t.recharge,
           &t.recharge_restante);
    fclose(f);
	return t;
}

void utiliser_technique_speciale( Combattant *utilisateur,Equipe *equipe_joueur,Equipe *equipe_adverse,Environnement env) {
    TechniqueSpeciale *tech = &utilisateur->technique;

    // Vérification de la recharge
    if (tech->recharge_restante > 0) {
        printf("%s ne peut pas utiliser %s (recharge restante : %d tours).\n",
               utilisateur->nom, tech->nom, tech->recharge_restante);
        return;
    }

    Combattant *cible = NULL;

    // Choix de la cible
    if (tech->type_effet == 0) {
        // Cas attaque → on utilise ta fonction telle quelle
        int index = choix_cible_a_attaquer(*equipe_adverse);
        cible = &equipe_adverse->combattants[index];
    } else {
        // Cas buff/soin → on saisit le nom d’un allié
        char nom_cible[50];
        printf("Sur quel allié appliquer %s ?\n", tech->nom);
        for (int i = 0; i < equipe_joueur->nb_combattants; i++) {
            Combattant *c = &equipe_joueur->combattants[i];
            printf("- %s (PV : %d/%d)\n", c->nom, c->vie_courante, c->vie_max);
        }

        printf("Nom de l'allié ciblé : ");
        scanf("%s", nom_cible);

        for (int i = 0; i < equipe_joueur->nb_combattants; i++) {
            if (strcmp(equipe_joueur->combattants[i].nom, nom_cible) == 0) {
                cible = &equipe_joueur->combattants[i];
                break;
            }
        }

        if (cible == NULL) {
            printf("❌ Cible invalide. Action annulée.\n");
            return;
        }
    }

    // Affichage principal
    printf("\n🌀 %s utilise %s sur %s !\n", utilisateur->nom, tech->nom, cible->nom);
    printf(">> 📝 %s\n", tech->description);

    // Application de l’effet
    switch (tech->type_effet) {
        case 0: { // Attaque puissante
            int degats = calculer_degats_generique(
                tech->valeur,
                cible->defense,
                utilisateur->type,
                cible->type,
                env
            );

            // Affichage des effets environnementaux
            if (strcmp(utilisateur->type, env.type_bonus) == 0 &&
                strcmp(cible->type, env.type_malus) == 0) {
                printf("🔥 L’environnement (%s) renforce l’attaque de %s ! (Bonus ×%.1f)\n",
                       env.nom, utilisateur->nom, env.coeff_bonus);
            }
            else if (strcmp(utilisateur->type, env.type_malus) == 0 &&
                     strcmp(cible->type, env.type_bonus) == 0) {
                printf("🌱 L’environnement (%s) affaiblit l’attaque de %s… (Malus ×%.1f)\n",
                       env.nom, utilisateur->nom, env.coeff_malus);
            }

            cible->vie_courante -= degats;
            if (cible->vie_courante < 0) cible->vie_courante = 0;
            printf("💥 %s subit %d dégâts ! PV restants : %d/%d\n",
                   cible->nom, degats, cible->vie_courante, cible->vie_max);
            break;
        }

        case 1: // Buff attaque
            cible->attaque += tech->valeur;
            cible->buff_attaque_tours = tech->tours_actifs;
            printf("⚔️ %s gagne +%d en attaque pour %d tours !\n",
                   cible->nom, tech->valeur, tech->tours_actifs);
            break;

        case 2: // Buff défense
            cible->defense += tech->valeur;
            cible->buff_defense_tours = tech->tours_actifs;
            printf("🛡️ %s gagne +%d en défense pour %d tours !\n",
                   cible->nom, tech->valeur, tech->tours_actifs);
            break;

        case 3: // Buff vitesse
            cible->vitesse += tech->valeur;
            if (cible->vitesse > 4) cible->vitesse = 4;
            cible->buff_vitesse_tours = tech->tours_actifs;
            printf("💨 %s gagne +%d en vitesse pour %d tours !\n",
                   cible->nom, tech->valeur, tech->tours_actifs);
            break;

        case 4: // Soins
            cible->vie_courante += tech->valeur;
            if (cible->vie_courante > cible->vie_max)
                cible->vie_courante = cible->vie_max;
            printf("❤️ %s récupère %d PV ! PV actuels : %d/%d\n",
                   cible->nom, tech->valeur, cible->vie_courante, cible->vie_max);
            break;
    }

    // Recharge
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


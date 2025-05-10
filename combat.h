#ifndef COMBAT_H
#define COMBAT_H

#include "combattant.h"
#include "equipe.h"
#include "environnement.h"
#include "menu.h"

typedef struct {
    Combattant *combattant;
    Equipe *equipe_att;
    Equipe *equipe_def;
} OrdreCombattant;

void jouer_tour(Equipe *e1, Equipe *e2, Environnement *env);
void jouer_combat(Equipe *e1, Equipe *e2, Environnement *env);
int choix_cible_a_attaquer(Equipe *defenseur);
int calculer_degats_generique(int valeur_base, int valeur_defense,const char *element_attaquant, const char *element_defenseur, Environnement *env);

#endif


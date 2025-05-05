#define COMBAT_H
#include "equipe.h" 
typedef struct {
    Combattant *combattant;
    Equipe *equipe_att;
    Equipe *equipe_def;
}OrdreCombattant;
void jouer_combat(Equipe *e1, Equipe *e2);
void jouer_tour(Equipe *e1, Equipe *e2);
int choix_cible_a_attaquer(Equipe defenseur);

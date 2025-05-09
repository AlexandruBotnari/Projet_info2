#ifdef COMBAT_H
#define COMBAT_H
#include "equipe.h" 
#include "technique.h"
#include "combattant.h"

typedef struct {
    Combattant *combattant;
    Equipe *equipe_att;
    Equipe *equipe_def;
}OrdreCombattant;
void jouer_combat(Equipe *e1, Equipe *e2, Environnement *env);
void jouer_tour(Equipe *e1, Equipe *e2, Environnement *env);
int choix_cible_a_attaquer(Equipe *defenseur);
void fin_tour(Combattant *perso);
int calculer_degats_generique(int valeur_base,int valeur_defense,const char *element_attaquant,const char *element_defenseur, Environnement *env);
void fin_tour(Combattant *perso);


#endif

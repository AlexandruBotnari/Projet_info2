#ifndef INTERFACE_H
#define INTERFACE_H

#include "combat.h"   // contient la struct Combat, Equipe, Combattant, Technique

// Affiche intégralement l’état du combat dans la console
void afficher_interface(const Combat *combat);
void tracer_bordure(const char *gauche, const char *sep, const char *droite);
void afficher_entete(const char *nom);
void afficher_barre(int actuel, int maxi);
void afficher_prochain(int idxEq, int idxCbt, const Combat *c);
void afficher_effets(const Combattant *cbt);
void afficher_ligne_combattant(const Combattant *cbt, int idxEq, int idxCbt, const Combat *c);
void afficher_separateur(void);

#endif // INTERFACE_H


#ifndef INTERFACE_H
#define INTERFACE_H

#include <locale.h>            
#include "combat.h"            
#include "equipe.h"
#include "combattant.h"        
#include "technique.h"         
#include "couleurs_console.h"

// Affiche intégralement l’état du combat dans la console
void afficher_interface(const Combat *combat);

// Tracé des bordures en box-drawing
void tracer_bordure(const char *gauche, const char *sep, const char *droite);

// Divers éléments d’affichage
void afficher_entete(const char *nom);
void afficher_barre(int actuel, int maxi);
void afficher_prochain(int idxEq, int idxCbt, const Combat *c);
void afficher_effets(const Combattant *cbt);
void afficher_ligne_combattant(const Combattant *cbt,
                               int idxEq, int idxCbt,
                               const Combat *c);
void afficher_separateur(void);

#endif // INTERFACE_H

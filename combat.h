#ifndef COMBATTANT_H
#define COMBATTANT_H
#include "technique.h"

typedef struct {
    char nom[50];
    int vie_max;
    int vie_courante;
    int attaque;
    int defense;
    int agilite;
    int vitesse;
    TechniqueSpeciale techniques;
}Combattant;
int choix_personnage();
void afficher_combattant(Combattant c);
Combattant charger_combattant(char *chemin_fichier);
#endif


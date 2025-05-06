#ifdef COMBATTANT_H
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
    TechniqueSpeciale techniques[5];
    int nb_techniques;
    char element[50];
    int charge;
    int attaque_base;
    int defense_base;
    int vitesse_base;
    int buff_attaque_tour;
    int buff_defense_tour;
    int buff_vitesse_tour;
    TechniqueSpeciale technique; 
}Combattant;
int choix_personnage();
void afficher_combattant(Combattant c);
Combattant charger_combattant(char *chemin_fichier);

#endif


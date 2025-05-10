#ifndef COMBATTANT_H
#define COMBATTANT_H

typedef struct {
    char nom[50];
    char description[200];
    int valeur;
    int type_effet;
    int tours_actifs;
    int recharge;
    int recharge_restante;
} TechniqueSpeciale;

typedef struct Combattant {
    char nom[50];
    int vie_max;
    int vie_courante;
    int attaque;
    int defense;
    int agilite;
    int vitesse;
    char element[50];
    int charge;
    int attaque_base;
    int defense_base;
    int agilite_base;
    int buff_attaque_tour;
    int buff_defense_tour;
    int buff_agilite_tour;
    TechniqueSpeciale technique;
} Combattant;

void afficher_combattant(Combattant c);
void afficher_combattant_tempo(Combattant c);
Combattant charger_combattant(const char *chemin_fichier);

#endif



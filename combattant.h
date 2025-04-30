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
    TechniqueSpeciale techniques[5];
} Combattant;

#endif


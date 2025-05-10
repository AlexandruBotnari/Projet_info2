#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

typedef struct {
    char nom[50];
    char element_bonus[20];
    char element_malus[20];
    float bonus;
    float malus;
} Environnement;

Environnement choix_environnement();
Environnement charger_environnement(const char *chemin_fichier);

#endif



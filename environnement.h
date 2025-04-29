#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

typedef struct {
    char nom[20];
    char element_avantage[20];
    char element_desavantage[20];
    float bonus;
    float malus;
} Environnement;

// Déclaration de la fonction de chargement
Environnement charger_environnement(const char *chemin_fichier);

#endif


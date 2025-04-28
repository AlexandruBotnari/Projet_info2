#include <stdio.h>
#include "combattant.h"

void afficher_combattant(Combattant c) {
    printf("Nom: %s\n", c.nom);
    printf("Vie: %d/%d\n", c.vie_courante, c.vie_max);
    printf("Attaque: %d\n", c.attaque);
    printf("Defense: %d\n", c.defense);
    printf("Agilite: %d\n", c.agilite);
    printf("Vitesse: %d\n", c.vitesse);
}


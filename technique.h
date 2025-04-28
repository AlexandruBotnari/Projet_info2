#ifndef TECHNIQUE_H
#define TECHNIQUE_H

typedef struct {
    char nom[50];
    char description[200];
    int valeur;
    int type_effet;
    int tours_actifs;
    int recharge;
    int recharge_restante;
} TechniqueSpeciale;

#endif


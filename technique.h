#ifdef TECHNIQUE_H
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

TechniqueSpeciale charger_TechniqueSpeciale(char *chemin_fichier);
void utiliser_technique_speciale( Combattant *utilisateur,Equipe *equipe_joueur,Equipe *equipe_adverse,Environnement env);

#endif


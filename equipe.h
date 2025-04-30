#ifndef EQUIPE_H
#define EQUIPE_H
#include "combattant.h"
typedef struct{
	char nom[50];
	Combattant combattants[3];
	int nb_combattants;
}Equipe;
Equipe creer_equipe();
void afficher_equipe(Equipe e);
int equipe_est_vaincue(Equipe e);
#endif	

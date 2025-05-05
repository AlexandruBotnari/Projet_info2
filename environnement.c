#include "environnement.h"
#include <string.h>
#include <stdio.h>

Environnement charger_environnement(char *chemin_fichier){
	Environnement e;
	FILE* f;
	f=fopen(chemin_fichier,"r");
	if (f == NULL){
		printf("erreur fopen\n");
		strcpy(c.nom, "inconnu");
		e.nom = e.element_avantage = e.element_desavantage = e.bonus = e.malus = 0;
		strcpy(c.element, "aucun");
		return c;
	}
	fscanf(f, "%s %s %s %f %f",
           e.nom,
           e.element_avantage,
           e.element_desavantage,
           &e.bonus,
           &e.malus);
    
	fclose(f);
	return e;
}

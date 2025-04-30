#include <stdio.h>
#include <string.h>
#include "equipe.h"
#include "combattant.h"

Equipe creer_equipe(){
	Equipe e;
	int choix_personnage();
	
    	char *tab_personnage[] = {"Arthemis.txt","Atlas.txt","déméter.txt","gaia.txt","hélios.txt","Héphaistos.txt","Ouranos.txt","poséidon.txt","téthys.txt","zeus.txt"};
	printf("Entrez le nom de votre équipe : ");
    	scanf("%s", e.nom);
    	printf("Création de l'équipe %s :\n", e.nom);
    	e.nb_combattants = 0; 
    	while(e.nb_combattants<3){
    		int index= choix_personnage();
		if (index < 0 || index > 9) {
        		printf("Choix invalide.\n");
        	continue;
        	}
		e.combattants[e.nb_combattants] = charger_combattant(tab_personnage[index]);
    		e.nb_combattants ++;
	}
    	return e;
}

void afficher_equipe(Equipe e) {
    printf("Équipe : %s\n", e.nom);
    for (int i = 0; i < e.nb_combattants; i++) {
        printf("Combattant %d :\n", i + 1);
        afficher_combattant(e.combattants[i]);
    }
}
int equipe_est_vaincue(Equipe e) {
    for (int i = 0; i < e.nb_combattants; i++) {
        if (e.combattants[i].vie_courante > 0) {
            return 0; 
        }
    }
    return 1; 
}

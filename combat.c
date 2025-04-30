#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "combat.h"
#include "equipe.h"
#include "combattant.h"
#include "techniques.h"
void jouer_combat(Equipe *e1, Equipe *e2){
	srand(time(NULL));
	while (!equipe_est_vaincue(e1) && !equipe_est_vaincue(e2)){
		jouer_tour(e1,e2);
		jouer_tour(e2,e1);
		printf("\n--- État après ce tour ---\n");
        	afficher_equipe(*e1);
        	afficher_equipe(*e2);
    	}
    	if (equipe_est_vaincue(*e1)){
        	printf("\n🏆 L'équipe %s a gagné !\n", e2->nom);
        }
    	else{
        	printf("\n🏆 L'équipe %s a gagné !\n", e1->nom);
	}
}


void jouer_tour(Equipe *e1, Equipe *e2){
	for (int i=0;i<3;i++){
		if (e2->combattants[i].vie_courante < 0) {
    			e2->combattants[i].charge= 0;
		}
		else{
			e1->combattants[i].charge=e1->combattants[i].charge+e1->combattants[i].vitesse;
		}	
		if (e1->combattants[i].charge>=4){
			printf("✅ barre chargé\n");
			int d=choix_cible_a_attaquer(e2);
			int degats=e1->combattants[i].attaque-e2->combattants[d].defense;
			e2->combattants[d].vie_courante -= degats;
			if (e2->combattants[d].vie_courante <= 0) {
    				e2->vie_courante = 0;
			}
		}
	}

}
int choix_cible_a_attaquer(Equipe defenseur){
	int i;
	printf("Quel numéro de combattant voulez-vous attaquer ?\n");
	scanf("%d", &i);
	while (defenseur.combattants[i].vie_courante<1){
		printf("Personnage mort veuillez en choisir un autre");
		printf("Quel numéro combattant voulez-vous attaquer ?\n");
		scanf("%d\n", &i);
	}
	return i;
}


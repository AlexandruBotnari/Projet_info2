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
	OrdreCombattant ordre[6];
	int index=0;
	for (int i=0;i<3;i++){
		if(e1->combattants[i].vie_courante > 0) {
			e1->combattants[i].charge+=e1->combattants[i].vitesse;
			ordre[index].combattant=&e1->combattants[i];
			ordre[index].equipe_att=e1;
			ordre[index].equipe_def=e2;
			index++;
		}
	}
	for (int i=0;i<3;i++){
		if(e2->combattants[i].vie_courante > 0) {
			e2->combattants[i].charge+=e2->combattants[i].vitesse;
			ordre[index].combattant=&e2->combattants[i];
			ordre[index].equipe_att=e2;
			ordre[index].equipe_def=e1;
			index++;
		}
	}
	for (int i = 0; i < index - 1; i++) {
        	for (int j = i + 1; j < index; j++) {
            		if (ordre[i].combattant->agilite < ordre[j].combattant->agilite) {
                		OrdreCombattant temp = ordre[i];
                		ordre[i] = ordre[j];
                		ordre[j] = temp;
            		}
        	}
   	 }
   	 for (int i=0;i<index;i++){
   	 	Combattant *c = ordre[i].combattant;
   	 	if (c->charge>=4 && c->vie_courante>0){
   	 		c->charge=0;
   	 		printf("✅ barre chargé, %s est prêt à attaquer\n", c->nom);
			int d=choix_cible_a_attaquer(ordre[i].equipe_def);
			Combattant *cible = &ordre[i].equipe_def->combattants[d];
			int degats=c->attaque-cible->defense;
			cible->vie_courante -= degats; 
			if (cible->vie_courante <= 0) {
    				cible->vie_courante = 0;
			}
			printf("%s attaque %s et inflige %d, il lui reste %d pv\n",c->nom, cible->nom, degats, cible->vie_courante);
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
		scanf("%d", &i);
	}
	return i;
}

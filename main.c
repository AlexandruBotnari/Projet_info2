#include <stdio.h>
#include "combattant.h"
#include "combattant.c" // juste pour tester pour l'instant
int choix_personnage(){
	int p;
	printf("Quel personnage voulez vous:\nArtémis : 0\nAtlas: 1\nDéméter : 2\nGaia : 3\nHélios : 4\nHéphaistos : 5\nOuranos : 6\nPoséidon : 7\nTéthys : 8\nZeus : 9\n ");
	scanf("%d", &p);
	return p;
}
int main() {
	char *tab_personnage[]={"Arthemis.txt","Atlas.txt","déméter.txt","gaia.txt","hélios.txt","Héphaistos.txt","Ouranos.txt","poséidon.txt","téthys.txt","zeus.txt"};
	int index= choix_personnage();
	if (index < 0 || index >= 9) {
        printf("Choix invalide.\n");
        return 1;
        }
	Combattant monCombattant = charger_combattant(tab_personnage[index]);
	afficher_combattant(monCombattant);
	return 0;
}
	

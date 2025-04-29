#include <stdio.h>
#include "combattant.h"
#include "combattant.c" // juste pour tester pour l'instant
int choix_personnage(){
	int p;
	printf("Quel personnage voulez vous:\nZeus: 0\narthemis: 1\n");
	scanf("%d", &p);
	return p;
}
int main() {
	char *tab_personnage[]={"Zeus.txt","arthemis.txt"};
	int index= choix_personnage();
	if (index < 0 || index >= 2) {
        printf("Choix invalide.\n");
        return 1;
        }
	Combattant monCombattant = charger_combattant(tab_personnage[index]);
	afficher_combattant(monCombattant);
	return 0;
}
	

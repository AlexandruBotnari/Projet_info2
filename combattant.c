#include <stdio.h>
#include "combattant.h"
#include <string.h>
void afficher_combattant(Combattant c) {
    printf("Nom: %s\n", c.nom);
    printf("Vie: %d/%d\n", c.vie_courante, c.vie_max);
    printf("Attaque: %d\n", c.attaque);
    printf("Defense: %d\n", c.defense);
    printf("Agilite: %d\n", c.agilite);
    printf("Vitesse: %d\n", c.vitesse);
    printf("Element: %s\n", c.element);
}
int choix_personnage(){
	int p;
	printf("Quel personnage voulez vous:\nArtémis : 0\nAtlas: 1\nDéméter : 2\nGaia : 3\nHélios : 4\nHéphaistos : 5\nOuranos : 6\nPoséidon : 7\nTéthys : 8\nZeus : 9\n ");
	scanf("%d", &p);
	if (p != 1 || p < 0 || p > 9) {
            printf("❌ Choix invalide, essayez encore.\n");
            while (getchar() != '\n');
        }
	return p;
}
Combattant charger_combattant(char *chemin_fichier){
	Combattant c;
	FILE* f;
	f=fopen(chemin_fichier,"r");
	if (f == NULL){
		printf("erreur fopen\n");
		strcpy(c.nom, "inconnu");
		c.vie_max = c.vie_courante = c.attaque = c.defense = c.agilite = c.vitesse = 0;
		strcpy(c.element, "aucun");
		return c;
	}
	fscanf(f, "%s %d %d %d %d %d %d %s",
           c.nom,
           &c.vie_max,
           &c.vie_courante,
           &c.attaque,
           &c.defense,
           &c.agilite,
           &c.vitesse,
           c.element);
	c.charge=0;
	fclose(f);
	return c;
}

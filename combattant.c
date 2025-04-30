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
    afficher_technique_speciale(c.techniques);
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
	
	fclose(f);
	return c;
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
	
	fclose(f);
	return c;
}

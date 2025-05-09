#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <unistd.h> 
typedef struct {
    char nom[50];
    char description[200];
    int valeur;
    int type_effet;
    int tours_actifs;
    int recharge;
    int recharge_restante;
} TechniqueSpeciale;
typedef struct Combattant {
    char nom[50];
    int vie_max;
    int vie_courante;
    int attaque;
    int defense;
    int agilite;
    int vitesse;
    char element[50];
    int charge;
    int attaque_base;
    int defense_base;
    int agilite_base;
    int buff_attaque_tour;
    int buff_defense_tour;
    int buff_agilite_tour;
    TechniqueSpeciale technique;
} Combattant;
typedef struct {
    char nom[50];
    Combattant combattants[3];
    int nb_combattants;
}Equipe;
typedef struct {
    Combattant *combattant;
    Equipe *equipe_att;
    Equipe *equipe_def;
} OrdreCombattant;
typedef struct {
    char nom[50];
    char element_bonus[20];
    char element_malus[20];
    float bonus;
    float malus;
} Environnement;
// Gestion des fichiers et des structures principales
Environnement charger_environnement(const char *chemin_fichier);
Environnement choix_environnement(void);

// Gestion des combattants
Combattant charger_combattant(const char *chemin_fichier);
int choix_personnage(void);
Equipe creer_equipe(void);
void afficher_combattant(Combattant c);
void afficher_equipe(Equipe *e);
void afficher_equipe_tour(Equipe *e);
int equipe_est_vaincue(Equipe *e);
int choix_cible_a_attaquer(Equipe *defenseur);

// Combat et techniques spéciales
void jouer_tour(Equipe *e1, Equipe *e2, Environnement *env);
void jouer_combat(Equipe *e1, Equipe *e2, Environnement *env);
void utiliser_technique_speciale(Combattant *utilisateur, Equipe *equipe_joueur, Equipe *equipe_adverse, Environnement *env);
int calculer_degats_generique(int valeur_base, int valeur_defense, const char *element_attaquant, const char *element_defenseur, Environnement *env);
void clearTerminal(){
	system("clear");
}

int afficherMenu() {
	int k=0;
	clearTerminal();
    	while(k!=1){
    		printf("=====================================\n");
    		printf("      ⚔️ Combat Mythologique 3v3 ⚔️    \n");
    		printf("=====================================\n");
    		printf("1. Démarrer une nouvelle partie\n");
    		printf("2. Voir la liste des combattants\n");
    		printf("3. Règles du jeu\n");
    		printf("4. Quitter\n");
    		printf("=====================================\n");
    		do {
    			printf("👉 Faites votre choix : ");
    			scanf("%d",&k);
    			clearTerminal();
    			while(getchar() != '\n'); 
    		} while (k != 1 && k != 2 && k != 3 && k != 4 );
    		if (k==2){
    			printf("Quel personnage voulez-vous ?\n"
       "🏹 Artémis\n"
       "🌋 Atlas\n"
       "🌾 Déméter\n"
       "🌱 Gaïa\n"
       "☀️ Hélios\n"
       "🔥 Héphaïstos\n"
       "💨 Ouranos\n"
       "🌊 Poséidon\n"
       "💧 Téthys\n"
       "⚡ Zeus\n");
       int milo=0;
               		do {
               			
    				printf("1: Sortir👋 \n ");
    				scanf("%d",&milo);
    				while(getchar() != '\n'); 
    			} while (milo != 1);
        	}
        	if (k==3){
    			printf("Le but est de vaincre l'adversaire à travers des attaques et des techniques spéciales\n");
    			int m=0;
    			do {
    				printf("1: Sortir👋 \n ");
    				scanf("%d",&m);
    				while(getchar() != '\n'); 
    			} while (m != 1);
        	}
        	if (k==4){
        		printf("😢\n");
        		clearTerminal();
        		exit(0);
        	}
        	clearTerminal();
}  		
    	 
}
Environnement choix_environnement() {
    int p;
    Environnement env;
    do {
        printf("Quel environnement voulez-vous ?\n"
               "0: Etna 🔥\n1: Nysa 🌲\n2: Keraunos ⚡\n3: Thalassa 🌊\n4: Olympe 🏔️\n"
               "5: Aulis 🌪️\n");
        scanf("%d", &p);
        while(getchar() != '\n'); // vide le buffer
    } while (p < 0 || p > 5);
    char *tab_environnement[] = {"etna.txt", "nysa.txt", "keraunos.txt", "thalassa.txt", "olympe.txt",
        "aulis.txt"};
    env = charger_environnement(tab_environnement[p]);
    return env;
}
Environnement charger_environnement(const char *chemin_fichier) {
    Environnement e;
    FILE* f = fopen(chemin_fichier, "r");

    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier : %s\n", chemin_fichier);
        strcpy(e.nom, "inconnu");
        strcpy(e.element_bonus, "aucun");
        strcpy(e.element_malus, "aucun");
        e.bonus = 0.0f;
        e.malus = 0.0f;
        return e;
    }

    fscanf(f, "%s %s %s %f %f",
           e.nom,
       	e.element_bonus,
       e.element_malus,
       &e.bonus,
       &e.malus);

    fclose(f);
    return e;
}    
void afficher_combattant_tempo(Combattant c) {
    printf("Nom: %s\n", c.nom);
    printf("Vie: %d/%d\n", c.vie_courante, c.vie_max);
    printf("Attaque: %d\n", c.attaque);
    printf("Defense: %d\n", c.defense);
    printf("Agilité: %d\n", c.agilite);
    printf("Vitesse: %d\n", c.vitesse);
    printf("charge: %d\n", c.charge);
    printf("Élément: %s\n", c.element);
    printf("Nom Technique: %s\n", c.technique.nom);
    printf("Technique valeur: %d\n", c.technique.valeur);
    printf("type effet: %d\n", c.technique.type_effet);
    printf("description: %s\n", c.technique.description);
    printf("tour actifs: %d\n", c.technique.tours_actifs);
}
void afficher_combattant(Combattant c) {
    printf("Nom: %s\n", c.nom);
    printf("Vie: %d/%d\n", c.vie_courante, c.vie_max);
    printf("Attaque: %d\n", c.attaque);
    printf("Defense: %d\n", c.defense);
    printf("Agilité: %d\n", c.agilite);
    printf("Vitesse: %d\n", c.vitesse);
    printf("Élément: %s\n", c.element);
}

int choix_personnage() {
    int p;
    do {
    	clearTerminal();
        printf("Quel personnage voulez-vous ?\n"
               "0: Artémis\n1: Atlas\n2: Déméter\n3: Gaia\n4: Hélios\n"
               "5: Héphaistos\n6: Ouranos\n7: Poséidon\n8: Téthys\n9: Zeus\n");
        scanf("%d", &p);
        while(getchar() != '\n'); // vide le buffer
    } while (p < 0 || p > 9);
    return p;
}


Combattant charger_combattant(const char *chemin_fichier) {
	Combattant c;
	
    	FILE *f = fopen(chemin_fichier, "r");
    	if (f==NULL) {
        	printf("Erreur fopen\n");
        	strcpy(c.nom, "inconnu");
        	c.vie_max = c.vie_courante = c.attaque = c.defense = c.agilite = c.vitesse = 0;
        	strcpy(c.element, "aucun");
        	return c;
    	}
    	fscanf(f,
        "%63s   %d %d %d %d %d %d %d   %31s   %63s   %d %d   \"%255[^\"]\"   %d %d %d",
        c.nom,
        &c.vie_max,
        &c.vie_courante,
        &c.attaque,
        &c.defense,
        &c.agilite,
        &c.vitesse,
        &c.charge,
        c.element,
        c.technique.nom,
        &c.technique.valeur,
        &c.technique.type_effet,
        c.technique.description,
        &c.technique.tours_actifs,
        &c.technique.recharge,
        &c.technique.recharge_restante
    );
    	fclose(f);
    	afficher_combattant_tempo(c);
    	return c;
}

Equipe creer_equipe() {
    Equipe e;
    char *tab_personnage[] = {
        "Artémis.txt", "Atlas.txt", "déméter.txt", "gaia.txt", "hélios.txt",
        "Héphaistos.txt", "Ouranos.txt", "poséidon.txt", "téthys.txt", "zeus.txt"
    };

    printf("Entrez le nom de votre équipe : ");
    fgets(e.nom, sizeof(e.nom), stdin);
    e.nom[strcspn(e.nom, "\n")] = 0;  // Enlève le saut de ligne

    e.nb_combattants = 0;
    while (e.nb_combattants < 3) {
        int index = choix_personnage();
        e.combattants[e.nb_combattants] = charger_combattant(tab_personnage[index]);
        e.nb_combattants++;
    }
    return e;
}

void afficher_equipe(Equipe *e) {
	clearTerminal();
    	printf("Équipe : %s\n", e->nom);
    	for (int i = 0; i < e->nb_combattants; i++) {
        	printf("Combattant %d : ", i + 1);
        	printf("%s\n",e->combattants[i].nom);
    	}
}

int equipe_est_vaincue(Equipe *e) {
    for (int i = 0; i < e->nb_combattants; i++) {
        if (e->combattants[i].vie_courante > 0) {
            return 0;
        }
    }
    return 1;
}

int choix_cible_a_attaquer(Equipe *defenseur) {
    int i;
    do {
        printf("Choisissez la cible à attaquer :\n");
        for (int j = 0; j < 3; j++) {
            printf("%d: %s (%d PV)\n", j, defenseur->combattants[j].nom, defenseur->combattants[j].vie_courante);
        }
        scanf("%d", &i);
        while(getchar() != '\n');
    } while (i != 0 && i != 1 && i!=2 || defenseur->combattants[i].vie_courante <= 0);
    return i;
}

void jouer_tour(Equipe *e1, Equipe *e2, Environnement *env) {
    OrdreCombattant ordre[6];
    int index = 0;

    // Initialisation de l'ordre des combattants
    for (int i = 0; i < 3; i++) {
        if (e1->combattants[i].vie_courante > 0) {
            e1->combattants[i].charge += e1->combattants[i].vitesse;
            ordre[index++] = (OrdreCombattant){&e1->combattants[i], e1, e2};
        }
    }
    for (int j = 0; j < 3; j++) {
        if (e2->combattants[j].vie_courante > 0) {
            e2->combattants[j].charge += e2->combattants[j].vitesse;
            ordre[index++] = (OrdreCombattant){&e2->combattants[j], e2, e1};
        }
    }

    // Tri par agilité
    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (ordre[i].combattant->agilite < ordre[j].combattant->agilite) {
                OrdreCombattant tmp = ordre[i];
                ordre[i] = ordre[j];
                ordre[j] = tmp;
            }
        }
    }

    // Exécution des actions
    for (int i = 0; i < index; i++) {
        Combattant *c = ordre[i].combattant;
        Equipe *pasbon = ordre[i].equipe_att;
        if (c->charge >= 4 && c->vie_courante > 0) {
            c->charge = 0;
            printf("\n✅ %s de l'équipe %s est prêt à attaquer !\n", c->nom, pasbon->nom);
            if(c->technique.recharge_restante == 0){
            	int choix;
	    		do {
        		printf("Choisir action :\n1 - Attaque normale\n2 - Technique spéciale (%s)\n", c->technique.nom);
                	scanf("%d", &choix);
        		while(getchar() != '\n'); // vide le buffer
    			} while (choix != 1 && choix != 2);
            		if (choix == 2 ) {
                	utiliser_technique_speciale(c, ordre[i].equipe_att, ordre[i].equipe_def, env);
            	} 
            	else {
                	int d = choix_cible_a_attaquer(ordre[i].equipe_def);
                	Combattant *cible = &ordre[i].equipe_def->combattants[d];
                	int degats = calculer_degats_generique(c->attaque, cible->defense, c->element, cible->element, env);
                	if (degats < 0) degats = 0;

                	cible->vie_courante -= degats;
                	if (cible->vie_courante < 0) cible->vie_courante = 0;

                	printf("%s attaque %s et inflige %d dégâts. PV restants : %d\n", c->nom, cible->nom, degats, cible->vie_courante);
            	}
        }
        else {
        int d = choix_cible_a_attaquer(ordre[i].equipe_def);
                	Combattant *cible = &ordre[i].equipe_def->combattants[d];
                	int degats = calculer_degats_generique(c->attaque, cible->defense, c->element, cible->element, env);
                	if (degats < 0) degats = 0;
                	cible->vie_courante -= degats;
                	if (cible->vie_courante < 0) cible->vie_courante = 0;

                	printf("%s attaque %s et inflige %d dégâts. PV restants : %d\n", c->nom, cible->nom, degats, cible->vie_courante);
       }
    }
}

    // Mise à jour des effets temporaires
    for (int i = 0; i < 3; i++) {
        Combattant *c = &e1->combattants[i];

        if (c->technique.recharge_restante > 0)
            c->technique.recharge_restante--;

        if (c->buff_attaque_tour > 0 && --c->buff_attaque_tour == 0)
            c->attaque = c->attaque_base;

        if (c->buff_defense_tour > 0 && --c->buff_defense_tour == 0)
            c->defense = c->defense_base;

        if (c->buff_agilite_tour > 0 && --c->buff_agilite_tour == 0)
            c->agilite = c->agilite_base;
    }
}
           
void afficher_equipe_tour(Equipe *e) {
   	printf("Équipe : %s\n", e->nom);
    	for (int i = 0; i < e->nb_combattants; i++) {
        printf("Combattant %d : ", i + 1);
        printf("%s\n",e->combattants[i].nom);
        printf("Vie: %d/%d\n", e->combattants[i].vie_courante, e->combattants[i].vie_max);
        printf("Charge: %d\n", e->combattants[i].charge);
    }
}
void utiliser_technique_speciale( Combattant *utilisateur,Equipe *equipe_joueur,Equipe *equipe_adverse, Environnement *env) {
    TechniqueSpeciale *tech = &utilisateur->technique;

    // Vérification de la recharge
    if (tech->recharge_restante > 0) {
        printf("%s ne peut pas utiliser %s (recharge restante : %d tours).\n",
               utilisateur->nom, tech->nom, tech->recharge_restante);
        return;
    }

    Combattant *cible = NULL;

    // Choix de la cible
    if (tech->type_effet == 0) {
        // Cas attaque → on utilise ta fonction telle quelle
        int index = choix_cible_a_attaquer(equipe_adverse);
        cible = &equipe_adverse->combattants[index];
    } else {
    	int k;
    	do {
        	printf("Sur quel allié appliquer %s ?\n", tech->nom);
        	for (int i = 0; i < 3; i++) {
            		printf("%d: %s\n%d PV\nAttaque: %d\nDéfense: %d\nAgilité: %d\n", i, equipe_joueur->combattants[i].nom, equipe_joueur->combattants[i].vie_courante, equipe_joueur->combattants[i].attaque, equipe_joueur->combattants[i].defense, equipe_joueur->combattants[i].agilite);
        }
        scanf("%d", &k);
        while(getchar() != '\n');
    } while (k < 0 || k > 2 || equipe_joueur->combattants[k].vie_courante <= 0);
    	cible=&equipe_joueur->combattants[k];
}
    
    
        

    // Affichage principal
    printf("\n🌀 %s utilise %s sur %s !\n", utilisateur->nom, tech->nom, cible->nom);
    printf(">> %s\n", tech->description);

    // Application de l’effet
    switch (tech->type_effet) {
        case 0: { // Attaque puissante
            int degats = calculer_degats_generique(
                tech->valeur,
                cible->defense,
                utilisateur->element,
                cible->element,
                env
            );
            // Affichage des effets environnementaux
            if (strcmp(utilisateur->element, env->element_bonus) == 0 &&
                strcmp(cible->element, env->element_malus) == 0) {
                printf("L’environnement (%s) renforce l’attaque de %s ! (Bonus ×%.1f)\n",
                       env->nom, utilisateur->nom, env->bonus);
            }
            else if (strcmp(utilisateur->element, env->element_malus) == 0 &&
                     strcmp(cible->element, env->element_bonus) == 0) {
                printf("L’environnement (%s) affaiblit l’attaque de %s… (Malus ×%.1f)\n",
                        env->nom, utilisateur->nom, env->malus);
            }

            cible->vie_courante -= degats;
            if (cible->vie_courante < 0){
            	cible->vie_courante = 0;
            }
            printf("💥 %s subit %d dégâts ! PV restants : %d/%d\n",
                   cible->nom, degats, cible->vie_courante, cible->vie_max);
            break;
        }

        case 1: // Buff attaque
            cible->attaque += tech->valeur;
            cible->buff_attaque_tour = tech->tours_actifs;
            printf("⚔️ %s gagne +%d en attaque pour %d tours !\n",
                   cible->nom, tech->valeur, tech->tours_actifs);
            break;

        case 2: // Buff défense
            cible->defense += tech->valeur;
            cible->buff_defense_tour = tech->tours_actifs;
            printf("🛡️ %s gagne +%d en défense pour %d tours !\n",
                   cible->nom, tech->valeur, tech->tours_actifs);
            break;

        case 3: // Buff agilité
            cible->agilite += tech->valeur;
            cible->buff_agilite_tour = tech->tours_actifs;
            printf("💨 %s gagne +%d en agilite pour %d tours !\n",
                   cible->nom, tech->valeur, tech->tours_actifs);
            break;

        case 4: // Soins
            cible->vie_courante += tech->valeur;
            if (cible->vie_courante > cible->vie_max)
                cible->vie_courante = cible->vie_max;
            printf("❤️ %s récupère %d PV ! PV actuels : %d/%d\n",
                   cible->nom, tech->valeur, cible->vie_courante, cible->vie_max);
            break;
    }

    // Recharge
    tech->recharge_restante = tech->recharge;
}
int calculer_degats_generique(int valeur_base,int valeur_defense,const char *element_attaquant,const char *element_defenseur, Environnement *env) {
	float coeff = 1.0;

    	// Bonus environnement : element avantage attaque element désavantage
    	if (strcmp(element_attaquant, env->element_bonus) == 0 && strcmp(element_defenseur, env->element_malus) == 0) {
        	coeff *= env->bonus;
    }
    else if (strcmp(element_attaquant, env->element_malus) == 0 &&
             strcmp(element_defenseur, env->element_bonus) == 0) {
    	coeff *= env->malus;
    }	

    	float degats_f = valeur_base - valeur_defense;
    	if (degats_f < 1.0f){
    		degats_f = 1.0f;
	}
	return (int)round(degats_f * coeff);
}
void jouer_combat(Equipe *e1, Equipe *e2, Environnement *env) {
    srand(time(NULL));
    int nb_tours=0;
    while (!equipe_est_vaincue(e1) && !equipe_est_vaincue(e2)) {
    	clearTerminal();
    	nb_tours++;
    	printf("Tours: %d\n",nb_tours);
        jouer_tour(e1, e2, env);
        sleep(1);
        printf("\n--- État après ce tour ---\n\n");
       	 sleep(1);
        afficher_equipe_tour(e1);
        afficher_equipe_tour(e2);
        int k=0;
        do {
    		printf("On passe au prochain tour?\n1-Oui✅\n2-Non❌\n");
    		scanf("%d",&k);
    		while(getchar() != '\n'); 
    	} while (k != 1);
        
    }
    if (equipe_est_vaincue(e1)) {
        printf("\n🏆 Victoire de l'équipe %s !\n", e2->nom);
    } else {
        printf("\n🏆 Victoire de l'équipe %s !\n", e1->nom);
    }
}

int main(){
	afficherMenu();
    	Equipe e1 = creer_equipe();
    	afficher_equipe(&e1);
    	int k=0;
    	do {
    		printf("On passe à l'équipe 2?\n1-Oui✅\n2-Non❌\n");
    		scanf("%d",&k);
    		if (k==2){
    			printf("pas possible🦧\n");
    		}
    		while(getchar() != '\n'); 
    		} while (k != 1);
    	clearTerminal();
    	Equipe e2 = creer_equipe();
    	afficher_equipe(&e2);
    	do {
    		printf("On passe à l'environnement?\n1-Oui✅\n2-Non❌\n");
    		scanf("%d",&k);
    		if (k==2){
    			printf("pas possible🦧\n");
    		}
    		while(getchar() != '\n'); 
    		} while (k != 1);
    	clearTerminal();
    	Environnement env=choix_environnement();
    	printf("%s a été choisie, le combat peut commencer ⚔️\n",env.nom);
    	sleep(2);
    	clearTerminal();
    	printf("=====================================\n");
    	printf("      ⚔️ Combat Mythologique 3v3 ⚔️    \n");
    	printf("=====================================\n");
    	sleep(4);
    	clearTerminal();
    	jouer_combat(&e1, &e2, &env);
    	return 0;
}


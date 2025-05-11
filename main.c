#include <stdio.h>
#include "combattant.h"      // pour les structures de combattants
#include "equipe.h"          // pour créer et afficher les équipes
#include "combat.h"          // pour gérer le déroulement du combat
#include "environnement.h"   // pour choisir et charger un environnement
#include <time.h>            // pour la graine aléatoire dans jouer_combat
#include "menu.h"            // pour afficher le menu d’accueil et clearTerminal

// 🚀 Point d’entrée principal du programme
int main() {
    // 🎮 Affiche le menu de démarrage avec les options
    afficherMenu();

    // 🛡️ Création et affichage de la première équipe
    Equipe e1 = creer_equipe();
    afficher_equipe(&e1);

    // ⚔️ Création et affichage de la seconde équipe
    Equipe e2 = creer_equipe();
    afficher_equipe(&e2);

    // 🌍 Choix et chargement d’un environnement de combat
    Environnement env = choix_environnement();

    // 🧠 Lancement du combat avec les 2 équipes et l’environnement
    jouer_combat(&e1, &e2, &env);

    // ✅ Fin du programme
    return 0;
}
	

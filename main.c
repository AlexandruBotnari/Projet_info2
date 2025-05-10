#include <stdio.h>
#include "combattant.h"
#include "equipe.h"
#include "combat.h"
#include "environnement.h"
#include <time.h>
#include "menu.h"

int main(){
    afficherMenu();
    Equipe e1 = creer_equipe();
    afficher_equipe(&e1);
    Equipe e2 = creer_equipe();
    afficher_equipe(&e2);
    Environnement env = choix_environnement();
    jouer_combat(&e1, &e2, &env);
    return 0;
}

	

#include <stdio.h>
#include "combattant.h"
#include "combattant.c" // juste pour tester pour l'instant

int main() {
    Combattant monCombattant = {"DragonRouge", 100, 100, 30, 20, 15, 10, {}, 0};
    afficher_combattant(monCombattant);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "menu.h"

void clearTerminal() {
    system("clear");
}

int afficherMenu() {
    int k = 0;
    clearTerminal();
    while (k != 1) {
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
            scanf("%d", &k);
            clearTerminal();
            while(getchar() != '\n');
        } while (k < 1 || k > 4);

        if (k == 2) {
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
            int milo = 0;
            do {
                printf("1: Sortir👋 \n ");
                scanf("%d", &milo);
                while(getchar() != '\n');
            } while (milo != 1);
        }

        if (k == 3) {
            printf("Le but est de vaincre l'adversaire à travers des attaques et des techniques spéciales\n");
            int m = 0;
            do {
                printf("1: Sortir👋 \n ");
                scanf("%d", &m);
                while(getchar() != '\n');
            } while (m != 1);
        }

        if (k == 4) {
            printf("😢\n");
            clearTerminal();
            exit(0);
        }
        clearTerminal();
    }

    return k;
}


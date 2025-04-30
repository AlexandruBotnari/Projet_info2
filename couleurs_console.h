#ifndef COULEURS_CONSOLE_H
#define COULEURS_CONSOLE_H
#include <stdio.h>

#define COULEUR(param) printf("\033[%sm", param)

/// Nettoyage d’écran
#define EFFACER_ECRAN() printf("\033[H\033[2J")

/// Styles (SGR)
#define RESET       "0"   // Remise à zéro
#define GRAS        "1"   // Texte en gras
#define CLIGNOTANT  "5"   // Texte clignotant
#define INVERSE     "7"   // Couleurs inversées

/// Couleurs de texte classiques
#define NOIR        "30"
#define ROUGE       "31"
#define VERT        "32"
#define JAUNE       "33"
#define BLEU        "34"
#define MAGENTA     "35"
#define CYAN        "36"
#define BLANC       "37"

/// Arrière-plans classiques
#define ARRIERE_NOIR    "40"
#define ARRIERE_ROUGE   "41"
#define ARRIERE_VERT    "42"
#define ARRIERE_JAUNE   "43"
#define ARRIERE_BLEU    "44"
#define ARRIERE_MAGENTA "45"
#define ARRIERE_CYAN    "46"
#define ARRIERE_BLANC   "47"

/// Couleurs vives
#define ROUGE_VIF    "91"
#define VERT_VIF     "92"
#define JAUNE_VIF    "93"
#define BLEU_VIF     "94"
#define MAGENTA_VIF  "95"
#define CYAN_VIF     "96"
#define BLANC_VIF    "97"

#endif // COULEURS_CONSOLE_H

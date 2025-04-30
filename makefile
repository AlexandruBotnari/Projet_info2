# CY fighters 3v3
PROG = projet
# Sources
SRC = main.c fonction.c affichage.c joueur.c combat.c combattant.c interface.c technique.c utils.c
# Compilation et exécution
all: $(PROG)
  ./$(PROG)
# Compilation du programme
$(PROG): $(SRC) fichier.h combat.h combattant.h environnement.h interface.h joueur.h technique.h utils.h couleurs_console.h
  gcc -Wall -o $(PROG) $(SRC)
# Nettoyage
clean:
  rm -f $(PROG)

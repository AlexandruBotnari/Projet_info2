# CY fighters 3v3
PROG = projet
# Sources existantes
SRC = main.c joueur.c combat.c combattant.c interface.c technique.c utils.c equipe.c
# Compilation et exécution
all: $(PROG)
	./$(PROG)
# Compilation du programme
$(PROG): $(SRC) combat.h combattant.h environnement.h interface.h joueur.h technique.h utils.h couleurs_console.h equipe.h
	gcc -Wall -o $(PROG) $(SRC)
# Nettoyage
clean:
	rm -f $(PROG)

# CY fighters 3v3
PROG = projet
# Sources existantes
SRC = essai.c
# Compilation et exécution
all: $(PROG)
	./$(PROG)
# Compilation du programme
$(PROG): $(SRC) stdlib.h math.h string.h time.h stdlib.h
	gcc -Wall -o $(PROG) $(SRC)
# Nettoyage
clean:
	rm -f $(PROG)

# Nom de l'exécutable
EXEC = combat3v3

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -std=c99 -g

# Fichiers sources (sans technique.c)
SRC = main.c \
      combattant.c \
      equipe.c \
      environnement.c \
      combat.c \
      menu.c

# Fichiers objets
OBJ = $(SRC:.c=.o)

# Cibles

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXEC)

re: clean all


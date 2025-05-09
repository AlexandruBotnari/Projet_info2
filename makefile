PROG = projet
CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = main.c combat.c combattant.c equipe.c
OBJ = $(SRC:.c=.o)

all: $(PROG)

$(PROG): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(PROG)

clean:
	rm -f $(OBJ) $(PROG)

PROG = projet
CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = essai.c
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

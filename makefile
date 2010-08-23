NAME   = program

CC    = gcc
CFLAGS = -Wall -pedantic -c

SRC  = file.c matrix.c
OBJ  = $(SRC:.c=.o) main.o

compile: $(OBJ)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -fr *~ *.o *.gch
	rm -f $(NAME)
	rm -f $(TAME)

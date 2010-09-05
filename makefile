NAME   = program

CC    = gcc
CFLAGS = -Wall -c

SRC  = file.c matrix.c catmap.c
OBJ  = $(SRC:.c=.o) main.o

compile: $(OBJ)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -fr *~ *.o *.gch
	rm -f $(NAME)
	rm -f $(TAME)

NAME = program

CAT_MAP   = cat_map
BAKER_MAP = baker_map
GLOBAL    = global

CC = gcc
CFLAGS = -Wall -c

SRC = catmap.c protection.c 
OBJ = $(SRC:.c=.o)

$(CAT_MAP): $(OBJ) main.o
	$(CC) $(LFLAGS) -o $(CAT_MAP) $(OBJ) main.o

$(GLOBAL): $(OBJ) main_global_var.o
	$(CC) $(LFLAGS) -o $(GLOBAL) $(OBJ) main_global_var.o

clean:
	rm -fr *~ *.o *.gch $(CAT_MAP) $(GLOBAL)
	rm -f $(NAME)

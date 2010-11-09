NAME = program

CAT_MAP   = cat_map
BAKER_MAP = baker_map
GLOBAL    = global

CC = gcc
CFLAGS = -Wall -c

SRC = helper.c matrix.c catmap.c protection.c 
OBJ = $(SRC:.c=.o)

$(CAT_MAP): $(OBJ) main.o
	$(CC) $(LFLAGS) -o $(CAT_MAP) $(OBJ) main.o

$(GLOBAL): $(OBJ) main-2.o
	$(CC) $(LFLAGS) -o $(GLOBAL) $(OBJ) main-2.o

$(BAKER_MAP): $(OBJ) main-3.o
	$(CC) $(LFLAGS) -o $(BAKER_MAP) $(OBJ) main-3.o

clean:
	rm -fr *~ *.o *.gch $(CAT_MAP) $(GLOBAL) $(BAKER_MAP)
	rm -f $(NAME)

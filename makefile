NAME   = program

LIBS_DIR = ./Libs/

CC    = gcc
CFLAGS = -Wall -c

LIBS = $(LIBS_DIR)file.o $(LIBS_DIR)matrix.o $(LIBS_DIR)catmap.o $(LIBS_DIR)helper.o
SRC  = protection.c
OBJ  = $(LIBS) $(SRC:.c=.o) main.o

compile: $(OBJ)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -fr *~ *.o
	rm -f $(NAME)

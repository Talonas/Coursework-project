NAME   = program

LIBS_DIR = ./Libs/

CC    = gcc
CFLAGS = -Wall -c ./Components/

LIBS = $(LIBS_DIR)file.o $(LIBS_DIR)matrix.o $(LIBS_DIR)catmap.o $(LIBS_DIR)helper.o
SRC  = protection.c
OBJ  = $(LIBS) $(SRC:.c=.o) main.o

compile: $(OBJ)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJ)

OBJ_TEST = $(LIBS) $(SRC:.=o) test.o
test: $(OBJ_TEST)
	$(CC) $(LFLAGS) -o test-program $(OBJ_TEST)

clean:
	rm -fr *~ *.o
	rm -f $(NAME)

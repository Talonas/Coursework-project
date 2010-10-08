LIBS_DIR = ../Libs/

CC    = gcc
CFLAGS = -Wall -c

SRC = file.c matrix.c catmap.c helper.c
OBJ  = $(SRC:.c=.o)

compile: $(OBJ)
	$(CC) $(CFLAGS) $(SRC)
	mv -f *.o $(LIBS_DIR)

clean:
	rm -fr $(LIBS_DIR)*~ $(LIBS_DIR)*.o

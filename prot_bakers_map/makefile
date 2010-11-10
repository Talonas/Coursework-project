NAME = bakers_map

CC = gcc
CFLAGS = -Wall -c

SRC = bakers_map.c protection.c

OBJ = $(SRC:.c=.o) main.o

compile: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -fr *.o $(NAME)

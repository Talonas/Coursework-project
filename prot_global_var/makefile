NAME = global

CC = gcc
CFLAGS = -Wall -c

OBJ = main.o

compile: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -fr *.o $(NAME)

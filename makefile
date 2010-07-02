NAME   = program
 
CPP    = g++
CFLAGS = -Wall -c
LFALGS = -g
 
SRC  =
HDRC = $(SRC:.cpp=.h)
OBJ  = $(SRC:.cpp=.o) main.o
 
compile: $(OBJ) $(CPP) $(LFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -fr *~ *.o *.gch
	rm -f $(NAME)
	rm -f $(TAME)

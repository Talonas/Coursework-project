NAME   = program

CPP    = g++
CFLAGS = -Wall -c
LFALGS = -g

SRC  = ArnoldCatMap.cpp BakersMap.cpp File.cpp Matrix.cpp SourceModificator.cpp
HDRC = $(SRC:.cpp=.h)
OBJ  = $(SRC:.cpp=.o) main.o

compile: $(OBJ)
	$(CPP) $(LFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -fr *~ *.o *.gch
	rm -f $(NAME)
	rm -f $(TAME)

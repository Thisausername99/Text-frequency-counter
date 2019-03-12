SRC = struct.c word.c wordfreak.c
OBJ = struct.o word.o wordfreak.o
PROG = wordfreak

$(PROG): $(OBJ)
	gcc $(OBJ) -o $(PROG)

$(OBJ): $(SRC)
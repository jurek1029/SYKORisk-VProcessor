SRC := src
OBJ := bin
CC := gcc

SOURCES := $(wildcard $(SRC)/*.c)
OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

syko.exe: $(OBJECTS)
	$(CC) $^ -o $@	

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -I$(SRC) -c $< -o $@

clean:
	rm -f bin/*.o
	rm -f syko.exe


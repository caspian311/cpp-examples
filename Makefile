CC=gcc
EXEC=sayhello
SRC=src/sayhello.c
OBJ=$(SRC:.c=.o)

all: $(EXEC)

$(OBJ): $(SRC)
	$(CC) -c $(SRC)
	mv *.o src

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)

clean:
	rm -f $(EXEC) $(OBJ)

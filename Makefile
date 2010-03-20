CC=gcc
EXEC=hello
SRC=src/hello.c
OBJ=$(SRC:.c=.o)

all: test

$(OBJ): $(SRC)
	$(CC) -c $(SRC)
	mv *.o src

test: $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)

clean:
	rm -f $(EXEC) $(OBJ)

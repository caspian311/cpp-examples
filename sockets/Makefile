CC =		gcc
CFLAGS =	-O2 -g -Wall -fmessage-length=0
SERVER_OBJS =		src/server.o
CLIENT_OBJS =		src/client.o 
SERVER_TARGET =	server
CLIENT_TARGET =	client

all: $(SERVER_TARGET) $(CLIENT_TARGET)

$(CLIENT_TARGET): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT_TARGET) $(CLIENT_OBJS)

$(SERVER_TARGET): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_TARGET) $(SERVER_OBJS)

clean:
	rm -f *.o $(CLIENT_TARGET)  $(SERVER_TARGET)

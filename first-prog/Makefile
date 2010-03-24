CC =		gcc
CFLAGS =	-O2 -g -Wall -fmessage-length=0
OBJS =		src/sayhello.o src/greeting.o 
TARGET =	sayhello

all: 		$(TARGET)

$(TARGET): 	$(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET) 

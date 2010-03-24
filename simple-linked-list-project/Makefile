CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		src/Main.o src/Nodes.o

LIBS =		

TARGET =	linked-lists-example

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

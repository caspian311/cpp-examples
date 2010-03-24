CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		src/Main.o src/Car.o

LIBS =		

TARGET =	test-project

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

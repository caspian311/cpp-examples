CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		src/Main.o src/Car.o src/Hybrid.o src/Truck.o

LIBS =

TARGET =	inheritance-oo-project

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		command-line-agrs.o

LIBS =

TARGET =	command-line-agrs

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

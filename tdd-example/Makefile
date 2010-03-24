CC = 		g++
CCFLAGS =	-O2 -g -Wall -fmessage-length=0

TEST =		SuiteTest.cpp AddTest.cpp
TEST-OBJS =	$(TEST:.cpp=.o)
CPP-LIBS =	-Lcppunit -lcppunit -ldl
CPP-INC =	-I/usr/local/include
TEST-TARGET =	run-tests

SRC =		Add.cpp
OBJS =		$(SRC:.cpp=.o)

all:		$(TARGET)

$(TEST-OBJS):	$(TEST)
	$(CC) $(CCFLAGS) ${CPP-INC} -c $(TEST)

$(TEST-TARGET):	$(TEST-OBJS) $(OBJS)
	$(CC) $(CCFLAGS) $(CPP-LIBS) -o $(TEST-TARGET) $(TEST-OBJS) $(OBJS)

test:		$(TEST-TARGET)
	./$(TEST-TARGET)

$(OBJS):	$(SRC)
	$(CC) $(CCFLAGS) -c $(SRC)

clean:
	rm -f $(TEST-OBJS) $(OBJS) $(TEST-TARGET)

COMPILER = g++
FLAGS = -Wall -g -std=c++0x
EXECUTABLE = makeInteresting

all: test.o
	$(COMPILER) $(FLAGS) -o $(EXECUTABLE) test.o

test.o: test.cpp
	$(COMPILER) $(FLAGS) -c test.cpp

clean:
	rm -f *.o $(EXECUTABLE)

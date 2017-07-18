COMPILER = g++
FLAGS = -g -Wall -std=c++0x
EXECUTABLE = lab03_A

all: BagTest.o Bag.o Simple.o
	$(COMPILER) $(FLAGS) -o $(EXECUTABLE) BagTest.o Bag.o Simple.o

BagTest.o: BagTest.cpp
	$(COMPILER) $(FLAGS) -c BagTest.cpp

Bag.o: Bag.cpp
	$(COMPILER) $(FLAGS) -c Bag.cpp

Simple.o: Simple.cpp
	$(COMPILER) $(FLAGS) -c Simple.cpp

clean:
	rm -f *.o $(EXECUTABLE)

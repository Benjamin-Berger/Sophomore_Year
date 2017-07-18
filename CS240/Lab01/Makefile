COMPILER = g++
FLAGS = -g -Wall -std=c++0x
EXECUTABLE = prelab_a

all: Driver.o ClassA.o
	$(COMPILER) $(FLAGS) -o $(EXECUTABLE) Driver.o ClassA.o

Driver.o: Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp

ClassA.o: ClassA.cpp
	$(COMPILER) $(FLAGS) -c ClassA.cpp

clean:
	rm -f *.o $(EXECUTABLE)

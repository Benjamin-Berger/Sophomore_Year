COMPILER = g++
FLAGS = -g -Wall -std=c++0x
EXECUTABLE = p4

all: Driver.o Shelter.o
	$(COMPILER) $(FLAGS) -o $(EXECUTABLE) Driver.o Shelter.o

Driver.o: Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp

Shelter.o: Shelter.cpp
	$(COMPILER) $(FLAGS) -c Shelter.cpp

clean:
	rm -f *.o $(EXECUTABLE)

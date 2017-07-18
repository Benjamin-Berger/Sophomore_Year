COMPILER = g++
FLAGS = -g -Wall -std=c++0x
EXECUTABLE = lab09

all: Driver.o DataProcessor.o
	$(COMPILER) $(FLAGS) -o $(EXECUTABLE) Driver.o DataProcessor.o

Driver.o: Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp

DataProcessor.o: DataProcessor.cpp
	$(COMPILER) $(FLAGS) -c DataProcessor.cpp

clean:
	rm -f *.o $(EXECUTABLE)

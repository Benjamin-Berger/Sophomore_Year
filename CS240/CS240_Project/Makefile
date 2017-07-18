COMPILER = g++
FLAGS = -g -Wall -std=c++0x
EXECUTABLE = stop

all: tester.o ProcStop.o
	$(COMPILER) $(FLAGS) -o $(EXECUTABLE) tester.o ProcStop.o

tester.o: tester.cpp
	$(COMPILER) $(FLAGS) -c tester.cpp
ProcStop.o: ProcStop.cpp
	$(COMPILER) $(FLAGS) -c ProcStop.cpp

clean:
	rm -f *.o $(EXECUTABLE)

COMPILER = g++
CFLAGS = -g -Wall -std=c++0x -Ofast
PROJECT = wikiParse 

all: Driver.o Processor.o WordData.o
	$(COMPILER) $(FLAGS) Driver.o Processor.o WordData.o -o $(PROJECT)
Driver.o: Driver.cpp
	$(COMPILER) $(CFLAGS) -c Driver.cpp
Processor.o: Processor.cpp
	$(COMPILER) $(CFLAGS) -c Processor.cpp
WordData.o: WordData.cpp
	$(COMPILER) $(CFLAGS) -c WordData.cpp
clean:
	rm -rf *o report.txt sorted_words.txt $(PROJECT)

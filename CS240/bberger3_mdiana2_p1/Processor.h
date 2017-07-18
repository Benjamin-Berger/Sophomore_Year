#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>

#include "WordData.h"

class Processor {

	private:
		std::string fileName;
		std::string currentTitle;
		std::ifstream inputFile;
		std::vector<std::string> stopWords;
		std::map<std::string, WordData> words;
		std::vector<WordData> data;
		std::vector<std::string> titleOrder;

		int wordCount;
		int stopWordCount;
		int uniqueStopWordCount;
		int uniqueNonStopWordCount;
		int uniqueWordCount;
		double stopWordPercentage;
	public:
		Processor(std::string fn);
		void generateReport();
		void generateSortedWords();
		void addToWordCount(std::string line);
		void removePunctuation();
		void loadStopWords();
		void sortWords();
		void printFile();
		void printWords();
		void printStopWords();
		bool isStopWord(std::string str);
		bool isTitleLine(std::string str);
		
};

#endif

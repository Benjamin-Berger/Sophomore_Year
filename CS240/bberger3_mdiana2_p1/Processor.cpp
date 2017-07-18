#include "Processor.h"

using namespace std;

Processor::Processor(std::string fn) {
	fileName = fn;
	wordCount = 0;
	stopWordCount = 0;
	uniqueStopWordCount = 0;
	uniqueNonStopWordCount = 0;
	uniqueWordCount = 0;
	loadStopWords();
}

void Processor::generateReport() {
	vector<WordData> noStopData;
	for (unsigned i = 0; i < data.size(); i++) {
		if (!isStopWord(data[i].getWordName())) {
			noStopData.push_back(data[i]);
			uniqueNonStopWordCount++;
		}
		else
			uniqueStopWordCount++;
		uniqueWordCount++;
	}
	stopWordPercentage = (double)stopWordCount / wordCount * 100;
	ofstream report;
	report.open("report.txt");
	vector<WordData> sameCountData;
	int currentCount = -1;
	for (unsigned i = 0; i < ceil(noStopData.size() * .05); i++) {
		noStopData[i].setTitleOrder(titleOrder);
		if (currentCount != noStopData[i].getCount()) {
			reverse(sameCountData.begin(), sameCountData.end());
			for (unsigned j = 0; j < sameCountData.size(); j++) {
				report << sameCountData[j].getWordName() << ", " << sameCountData[j].getCount() << ", " << sameCountData[j].getMostFrequentTitle() << " " << endl;
			}
			sameCountData.clear();
		}
		sameCountData.push_back(noStopData[i]);
		if (i + 1 >= ceil(noStopData.size() * .05)) {
			int finalCount = noStopData[i].getCount();
			i++;
			while (finalCount == noStopData[i].getCount() && i < noStopData.size()) {	
				noStopData[i].setTitleOrder(titleOrder);
				sameCountData.push_back(noStopData[i]);
				i++;
			}
		}
	}
	for (unsigned j = 0; j < sameCountData.size(); j++) {
		report << sameCountData[j].getWordName() << ", " << sameCountData[j].getCount() << ", " << sameCountData[j].getMostFrequentTitle() << " " << endl;
	}
	cout << stopWordPercentage << "\% stop words" << endl;
	report.close();	
}

void Processor::generateSortedWords() {
	ofstream sortedWords;
	sortedWords.open("sorted_words.txt");
	for (auto it = words.cbegin(); it != words.cend(); it++) {
		sortedWords << it->first << " " << (it->second).getCount() <<  endl;
	}
	sortedWords.close();
}

void Processor::addToWordCount(string line) {
	istringstream ss(line);
	string word;
	while (ss >> word) {
		wordCount++;	
		map<string, WordData>::iterator it;
		it = words.find(word);
		if (it == words.end()) {
			words.insert(pair<string, WordData>(word, WordData(word, currentTitle)));
		} else {
			(it->second).incrementCount();
			(it->second).addTitle(currentTitle);
		}	
		if (isStopWord(word))
			stopWordCount++;
	}	
}
	

void Processor::removePunctuation() {
	inputFile.open(fileName.c_str());
	string line;
	if (inputFile.is_open()) {
		while (getline(inputFile, line)) {
			string modifiedLine;
			if (!isTitleLine(line)) {
			for (unsigned i = 0; i < line.size(); i++) {
				if (ispunct(line[i])) {
				if (line[i] == '(' || line[i] == ')') continue;
				if (line[i] == '\"' || line[i] == '\'') {	
					if (i != 0 && i != line.size()-1 && (line[i-1] == ' ' || line[i+1] == ' ')) continue;
					else if (i == 0 || i == line.size()-1) continue;
				}	
				if (i == 0) {
						if (line[i+1] == ' ') {
							continue;// remove the char
						}
					} else if (i == line.size()-1) {
						continue;// remove the char
					} else {
						if (line[i+1] == ' ' || line[i-1] == ' ' || ispunct(line[i+1]) || ispunct(line[i-1])) {
							continue;// remove the char
						}
					}
				}
				modifiedLine += line[i];
			}
			addToWordCount(modifiedLine);
			}
		}
		inputFile.close();
		//for (unsigned i = 0; i < titleOrder.size(); i++)
		//	cout << titleOrder[i] << endl;
	}
}

void Processor::loadStopWords() {
	ifstream stopWordsFile("stop.txt");
	string word;
	if (stopWordsFile.is_open()) {
		while (stopWordsFile >> word) {
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			stopWords.push_back(word);
		}
	}	
}

void Processor::sortWords() {
	for (auto it = words.cbegin(); it != words.cend(); it++) {
		data.push_back(it->second);
	}
	sort(data.begin(), data.end());
	reverse(data.begin(), data.end());	
}

void Processor::printFile() {
	string line;
	inputFile.open(fileName.c_str());
	if (inputFile.is_open()) {
		while (getline(inputFile, line)) {
			cout << line << endl;
		}
		inputFile.close();
	} else {
		cout << "Unable to open file" << endl;
	}
}

void Processor::printWords() {
	for (auto it = words.cbegin(); it != words.cend(); it++) {
		cout << it->first << " " << (it->second).getCount() <<  endl;
		(it->second).printTitles();
	}	
}

void Processor::printStopWords() {
	for (unsigned i = 0; i < stopWords.size(); i++)
		cout << stopWords[i] + " ";
	cout << endl;
}

bool Processor::isTitleLine(string str) {
	if (str.substr(0,7) == "<TITLE>") {
		currentTitle = str.substr(str.find(">")+2, str.find("<\\")-9);
		titleOrder.push_back(currentTitle);
		return true;
	}
	else
		return false;
}

bool Processor::isStopWord(string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	if (binary_search(stopWords.begin(), stopWords.end(), str))
		return true;
	else
		return false;
}

#ifndef WORDDATA_H
#define WORDDATA_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

class WordData {
	private:
		std::string wordName;
		int count;
		std::vector<std::string> titles;
		std::vector<std::string> titleOrder;
	public:
		WordData(std::string name, std::string firstTitle);
		void incrementCount();
		void addTitle(std::string t);
		void printTitles() const;
		std::string getWordName();
		int getCount() const;
		void setTitleOrder(std::vector<std::string> order);
		std::string getMostFrequentTitle();
		
	bool operator==(const WordData& rhs) const;
	bool operator!=(const WordData& rhs) const;
	bool operator<(const WordData& rhs) const;
	bool operator>(const WordData& rhs) const;
};

#endif

#include "WordData.h"

using namespace std;

WordData::WordData(string name, string firstTitle) {
	wordName = name;
	count = 1;
	titles.push_back(firstTitle);
}

void WordData::incrementCount() {
	count++;
}

void WordData::addTitle(string t) {
	titles.push_back(t);
}

void WordData::printTitles() const {
	for (unsigned i = 0; i < titles.size(); i++) {
		cout << titles[i] + " ";
	}
	cout << endl;
}

void WordData::setTitleOrder(vector<string> order) {
	titleOrder = order;
}

string WordData::getWordName() {
	return wordName;
}

int WordData::getCount() const {
	return count;
}

string WordData::getMostFrequentTitle() {
	//sort(titles.begin(), titles.end());
	map<string, int> titleFrequencies;
	for (unsigned i = 0; i < titles.size(); i++) {
		auto it = titleFrequencies.find(titles[i]);	
		if (it == titleFrequencies.end()) {
			titleFrequencies.insert(pair<string, int>(titles[i], 1));
		} else {
			(it->second)++;
		}
	}

	int max = 0;
	string result;
	vector<string> tmpList;
	for (auto it = titleFrequencies.cbegin(); it != titleFrequencies.cend(); it++) {
		if (it->second > max) {
			tmpList.clear();
			tmpList.push_back(it->first);
			result = it->first;
			max = it->second;
		} else if (it->second == max) {
			tmpList.push_back(it->first);
		}
	}
	if (tmpList.size() == 1) {
		result = tmpList[0];
	} else if (tmpList.size() > 1) {
		reverse(titleOrder.begin(), titleOrder.end());
		for (unsigned i = 0; i < titleOrder.size(); i++) {
			for (unsigned j = 0; j < tmpList.size(); j++) {
				if (titleOrder[i] == tmpList[j]) {
					result = tmpList[j];
					break;
				}
			}
		}
	} else {
		result = "";
	}
	return result;	
}

bool WordData::operator==(const WordData& rhs) const{
	if (count == rhs.count && wordName == rhs.wordName) return true;
	else return false;
}

bool WordData::operator!=(const WordData& rhs) const{
	if (count != rhs.count || wordName != rhs.wordName) return true;
	else return false;
}

bool WordData::operator<(const WordData& rhs) const{
	if (count < rhs.count) return true;
	else if (count == rhs.count && wordName > rhs.wordName) return true; 
	else return false;
}

bool WordData::operator>(const WordData& rhs) const{
	if (count > rhs.count) return true;
	else if (count == rhs.count && wordName > rhs.wordName) return true;
	else return false;
}

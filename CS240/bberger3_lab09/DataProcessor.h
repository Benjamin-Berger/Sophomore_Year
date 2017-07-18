#ifndef __DATA_H_
#define __DATA_H_

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class DataProcessor{
	private:
		std::vector<float> data;
		static const size_t notfound = -1;

	public:
		void readFromFile(std::string inFile);

		void writeToFile(std::string outFile);

		int linearSearch(float x);

		int binarySearch(float x);
		
		int bSearch(float x, int min, int max);

		void slowSort();

		void fastSort();
		void mergeSort(int top, int bot);
		void merge(int top, int bot);
};

#endif //__DATA__H_

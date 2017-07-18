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


	public:
		void readFromFile(std::string inFile);

		void writeToFile(std::string outFile);

		int linearSearch(float x);

		int binarySearch(float x);

		void slowSort();

		void fastSort();


};

#endif //__DATA__H_

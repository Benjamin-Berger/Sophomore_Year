#include "DataProcessor.h"

#include <fstream>




using namespace std;

DataProcessor::readFromFile(string inFile){
	ifstream myFile (inFile);
	float line;

	if(myFile.is.open()) {
		while(getline(myFile,line)) {
			data.push_back(line);
		}
	}
	
	myFile.close();


}

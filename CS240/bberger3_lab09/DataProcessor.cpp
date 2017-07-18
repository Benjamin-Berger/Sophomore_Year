/* 	Questions!
	1) data.size(0 warning unsigned
	2) in linear search data notFound
*/





#include "DataProcessor.h"

#include <fstream>
#include <iostream>
#include <list>
#include <cmath>

using namespace std;

void DataProcessor::readFromFile(string inFile){
	ifstream myFile (inFile);
	string line;
	float var;

	if(myFile.is_open()) {
		while(getline(myFile,line)) {
			var = ::atof(line.c_str());
			data.push_back(var);
		}
	}
	
	myFile.close();


}


void DataProcessor::writeToFile(string outFile){
	ofstream out (outFile);

	for(unsigned int i = 0; i < data.size(); i++){
		out << data[i] << endl;
	}
	data.clear();
}


int DataProcessor::linearSearch(float x){
	for(unsigned int i = 0; i < data.size(); i++){
		if(data[i] == x){
			return i;
		}

	}
	return DataProcessor::notfound;

}

int DataProcessor::binarySearch(float x){
	return bSearch(x, 0, data.size() -1);
}





int DataProcessor::bSearch(float x, int min, int max){
	if(max < min){
		return DataProcessor::notfound;
	} else {
		int mid = (min + max)/2;
		
		if(data[mid] > x){
			return bSearch(x, min, mid-1);
		}else if (data[mid] < x){
			return bSearch(x, mid+1, max);
      		}else{
        		return mid;
		}
	}

}

void DataProcessor::slowSort(){
	for(unsigned int i = 0; i < data.size() - 1;i++){
		int location = i;
		float min = data[i];
		for(unsigned int j = i+1; j < data.size(); j++){
			if(min > data[j]){
				min = data[j];
				location = j;
			}
		}
		data[location] = data[i];
		data[i] = min;
	}
}

void DataProcessor::fastSort(){
	int top = 0;
	int bot = data.size() -1;
	mergeSort(top, bot);

}

void DataProcessor::merge(int top, int bot){
 int mid = floor((top + bot) / 2);
    int first = 0;
    int sec = top;
    int thr = mid + 1;

    int temp[bot-top+1];

    while ( sec <= mid && thr <= bot )
        if ( data[sec] < data[thr] )
            temp[first++] = data[sec++];
        else
            temp[first++] = data[thr++];

    while ( sec <= mid )
        data[first++] = data[sec++];

    while ( thr <= bot )
        data[first++] = data[thr++];

    for ( int i = top; i <= bot; i++ )
        data[i] = data[i-top];
}

void DataProcessor::mergeSort(int top, int bot){
	if ( top < bot )
    {
        int mid = floor((top + bot) / 2);
        mergeSort(top, mid);
        mergeSort(mid + 1, bot);
        merge(top, bot);
    }

}

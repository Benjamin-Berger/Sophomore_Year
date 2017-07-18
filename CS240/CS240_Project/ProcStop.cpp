#include "ProcStop.h"

using namespace std;

void ProcStop::stopList(string stopFile){
	string line;
	ifstream stopF (stopFile);

	if(stopF.is_open()){
		while(getline(stopF,line)) {
			stop.push_back(line);
		}
	}
	stopF.close();
}



void ProcStop::sortList(){
	mergeSort(0, stop.size() - 1);

}

void ProcStop::merge(int top, int bot){
 int mid = floor((top + bot) / 2);
    int first = 0;
    int sec = top;
    int thr = mid + 1;

    int temp[bot-top+1];

    while ( sec <= mid && thr <= bot )
        if ( strcasecmp(stop[sec],stop[thr]) < 0 )
            temp[first++] = stop[sec++];
        else
            temp[first++] = stop[thr++];

    while ( sec <= mid )
        stop[first++] = stop[sec++];

    while ( thr <= bot )
        stop[first++] = stop[thr++];

    for ( int i = top; i <= bot; i++ )
        stop[i] = stop[i-top];
}

void ProcStop::mergeSort(int top, int bot){
	if ( top < bot )
    {
        int mid = floor((top + bot) / 2);
        mergeSort(top, mid);
        mergeSort(mid + 1, bot);
        merge(top, bot);
    }

}






int ProcStop::checkStop(string word){
	int x = csHelper(word, 0, stop.size());
	
	cout << "just checking this" << strcasecmp(word.c_str(),"poop") << endl;

	if(x > -1){
		x = 1;
	}
	return x;
}

int ProcStop::csHelper(string word, int min, int max){
	if(max < min) {
		return -1;
	} else {
		int mid = (min + max) /2;

		if(strcasecmp(stop[mid].c_str(),word.c_str()) > 0){
			return csHelper(word,min, mid-1);
		} else if(strcasecmp(stop[mid].c_str(),word.c_str()) < 0){
			return csHelper(word,mid+1, max);
		} else{
			return mid;
		}
	}
}


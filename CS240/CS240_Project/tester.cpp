#include "ProcStop.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc == 2){
		ProcStop test;
		test.stopList(argv[1]);
		cout << test.checkStop("and") << endl;







	}
}

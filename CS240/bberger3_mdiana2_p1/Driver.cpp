#include "Processor.h"
#include <chrono>

using namespace std;

int main(int argc, char* argv[]) {
	chrono::monotonic_clock::time_point start, finish;
	chrono::nanoseconds elapsed;
	start = chrono::monotonic_clock::now();
	if (argc == 2) {
		Processor p(argv[1]);
		p.removePunctuation();
		p.sortWords();
		p.generateReport();
		p.generateSortedWords();
	} else {
		cerr << "Invalid use." << endl;
		cerr << "Usage: ./wikiParse input_file_name" << endl;
	}
	finish = chrono::monotonic_clock::now();
	elapsed = chrono::duration_cast<chrono::microseconds>(finish-start);
	cout << elapsed.count() << " microseconds" << endl;
}

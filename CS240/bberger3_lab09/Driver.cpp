#include "DataProcessor.h"
#include <chrono>

using namespace std;

int main(int argc, char* argv[]){
	/**C++11 introduced the chrono header file as a means
	  of providing a standard  by which one could measure
	  the execution time of a piece of code.

	  More recent versions of g++ support more features of
	  C++11 including more robust clock types (particularly 
	  stable_clock).
	 **/

	//declare a couple of time points
	chrono::monotonic_clock::time_point start, finish;

	//declare a nanosecond holder
	chrono::nanoseconds elapsed;
	
	//get the current time (starts the timer)
	start = chrono::monotonic_clock::now();
		
	
		//Code we wish to test for performance
		


	//get the current time again (ends the timer)
	finish = chrono::monotonic_clock::now();
	
	//computes the difference in time in nanoseconds
	elapsed = chrono::duration_cast<chrono::nanoseconds>(finish-start);

	//prints out the number of elapsed nanoseconds
	cout << elapsed.count() << " us" << endl;
	
	float elap = 0;
	ofstream results; 
	results.open(argv[2], ios::out | ios::app);

	if(argc == 3){
		DataProcessor test;
		for(int i = 0; i < 10; i++){
			test.readFromFile(argv[1]);
			
			start = chrono::monotonic_clock::now();
			test.slowSort();
			finish = chrono::monotonic_clock::now();
			
			elapsed = chrono::duration_cast<chrono::nanoseconds>(finish-start);
			elap += elapsed.count();
		}
		elap = (elap / 10);
		results << elap << endl;
		elap = 0;		

                for(int i = 0; i < 10; i++){

                        start = chrono::monotonic_clock::now();
                        test.linearSearch(5);
                        finish = chrono::monotonic_clock::now();

                        elapsed = chrono::duration_cast<chrono::nanoseconds>(finish-start);
                        elap += elapsed.count();
                }
		elap = (elap/10);
		results << elap << endl;
		elap = 0;

               for(int i = 0; i < 10; i++){
			test.readFromFile(argv[1]);
                        start = chrono::monotonic_clock::now();
                        test.fastSort();
                        finish = chrono::monotonic_clock::now();

                        elapsed = chrono::duration_cast<chrono::nanoseconds>(finish-start);
                        elap += elapsed.count();
                }
                elap = (elap/10);
                results << elap << endl;
                elap = 0;

               for(int i = 0; i < 10; i++){
                        start = chrono::monotonic_clock::now();
                        test.binarySearch(5);
                        finish = chrono::monotonic_clock::now();

                        elapsed = chrono::duration_cast<chrono::nanoseconds>(finish-start);
                        elap += elapsed.count();
                }
                elap = (elap/10);
                results << elap << endl;
                elap = 0;

	}
	results << endl << endl;

}

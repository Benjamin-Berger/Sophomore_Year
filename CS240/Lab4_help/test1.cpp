/** 
  Copyright  2014 - Jessica Hartog 
  Binghamton University, Computer Science Department
  Binghamton, NY 13902
 **/

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
	This program illustrates how string streams operate just like
	most other streams -- except that you can push things into them
	and take things out of them.

	So, you can push things into the string stream like you would 
	push things into the output stream (cout). And you can remove
	things from the string stream like you would remove things from
	the input stream (cin).


	For more information visit:
		http://www.cplusplus.com/reference/sstream/stringstream/

**/
int main(){

	//Declare variables
	stringstream ss;
	string line, word;
	int count = 0;
	ifstream myInFile (“practice.txt”);
	ofstream myOutFile;


	//Prompt the user
	cout << "Type a phrase whose words to count: ";

	//Get a line from the standard input (cin)
	//NOTE: If we do not use getline, by default the >> operator stops
	//at whitespace, so we will not really have this program doing 
       	//anything interesting
	getline(myInFile, line);

	//Push the line into the stringstream
	ss << line;

	//When the stringstream is empty, this condition will fail
	while(ss >> word){
		count++;
		cout << "Word " << count << " is: " << word << std::endl;
	}

	return 0;
}
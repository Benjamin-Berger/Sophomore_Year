// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main () {
  string line, word;
  ifstream myfile ("War_Of_The_Worlds.txt");
  stringstream ss;


  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
	ss << line;
	
	while(ss >> word){
		if(word == “War”){
		   cout << “Hi”;
		}
	}
	
      
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
  
  return 0;
}
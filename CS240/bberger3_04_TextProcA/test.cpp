#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){
	if(argc == 3){

	string line, word;
	ifstream myFile (argv[1]);
	ofstream outFile (argv[2]);
	stringstream ss, ss2;
	double rep = 0, words = 0, stop = 0, x = 0.0, y = 0.0;
	int pos = -1;


	if(myFile.is_open()) {
		while(getline(myFile,line)){
			ss.clear();
			ss << line;
			while(ss >> word){
				words++;
				stop++;
				if(word == "War"){
					word = "Rainbows";
					rep++;
				}
				if(word == "Martians"){
					word = "witches";
					rep++;	
				}
				if(word == "died"){
					word = "laughed";
					rep++;
				}
				if(word == "die"){
					word = "laugh";
					rep++;
				}
				if(word == "gun"){
					word = "puppy";
					rep++;
				}
				if(word == "water"){
					word = "lemonade";
					rep++;
				}
				if(word == "people"){
					word = "children";
					rep++;
				}
				// going to try and make change the word by find
				pos = word.find("dark");
				if(pos > -1){
				word.replace(pos,4,"bright");
				pos = -1;
				rep++;
				}
				pos = word.find("blood");
				if(pos > -1){
				word.replace(pos,5,"strawberry syrup");
				pos = -1;
				rep++;
				}
				pos = word.find("destroy");
				if(pos > -1){
				word.replace(pos,7,"mend");
				pos = -1;
				rep++;
				}

				//stop words
				if(word == "a"){
					stop--;
				}
				if(word == "A"){
					stop--;
				}
				if(word == "an"){
					stop--;
				}
				if(word == "An"){
					stop--;
				}
				if(word == "and"){
					stop--;
				}
				if(word == "And"){
					stop--;
				}
				if(word == "are"){
					stop--;
				}
				if(word == "Are"){
					stop--;
				}
				if(word == "be"){
					stop--;
				}
				if(word == "Be"){
					stop--;
				}
				if(word == "he"){
					stop--;
				}
				if(word == "He"){
					stop--;
				}
				if(word == "is"){
					stop--;
				}
				if(word == "Is"){
					stop--;
				}
				if(word == "it"){
					stop--;
				}
				if(word == "It"){
					stop--;
				}
				if(word == "she"){
					stop--;
				}
				if(word == "She"){
					stop--;
				}
				if(word == "the"){
					stop--;
				}
				if(word == "The"){
					stop--;
				}
				if(word == "you"){
					stop--;
				}
				if(word == "You"){
					stop--;
				}

				outFile << word << " ";
			}
			outFile << endl;
		}
		if(words != 0.0){
		x = (100*(rep/words));
		}
		if(stop != 0.0){
		y = (100*(rep/stop));
		}
		cout << "Processing " << argv[1] << " resulted in change rate of " << x << "% overall and " << y << "% useful words." << endl;
		
		myFile.close();
		outFile.close();
	} else {
		cout << "Unable to open file";
	}
} else {
	cout << "Improper number of arguments given" << endl;
}
	return 0;


}

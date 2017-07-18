#ifndef __STOP_H_
#define __STOP_H_

#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>

class ProcStop{
	private: 
		//the list of stop words will be sotred in list
		std::vector<std::string> stop;
		
	public:


		/* the stopList function will move all the words from
		the file into the "stop" list 	*/
		void stopList(std::string stopFile);


		void sortList();
		void merge(int top, int bot);
		void mergeSort(int top, int bot);



		/* the checkStop function checks to see if the word is in
		the list of stop words. works will all cases. 
		@return 1 if found -1 if not	*/
		int checkStop(std::string word);

		/* csHelper is the check stop helper. It will run 
		the binary search to find the word */
		int csHelper(std::string word, int min, int max);
};

#endif //__STOP_H_

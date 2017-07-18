#ifndef __SHELT_H_
#define __SHELT_H_

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <queue>
#include <string>
#include <list>

class Shelter{
	private:
		/*list of cats or dogs. 1 is dog, 2 is cat. 
		I chose to use a list to keep the order of the cats
		and dogs. This was because in a list I could have access
		to all the elements to find the first dog and or cat.
		I also had free access to remove them when I wanted to.*/
		std::list<int> order;
		/* I chose to use a queue for keeping the names of the
		animals. This was because I always wanted to access only
		the front of the list in either case.*/
		std::queue<std::string> dogNames;
		std::queue<std::string> catNames;

		/*while there are many "correct" data structures to choose
		from, I think using a queue was the most efficient in this
		case. We only wanted access the the first element and a
		queue does just that.*/

	public:
		//constructer. just because
		Shelter();
		
		//the menu for all the options
		void menu();

		//the add menu for all animals
		void add();
	
		//the menu and functions to remove the animals in order
		void remove();

		//cleans up the memory so that there are no leaks 
		//before leaving
//		void exit();  actually dont need this
};

#endif //__SHELT__H_

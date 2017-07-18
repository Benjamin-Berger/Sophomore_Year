#include <fstream>
#include <iostream>
#include <stdexcept>
#include "Simple.h"



typedef Simple Element;

class Bag{
	private:
		//Array of Elements, since the array will represent
		//all of the items held in the Bag, and the capacity 
		//of the Bags can grow -- this needs to 
		//be a pointer so it can be dynamic.
		Element* items;
		//The capacity of the Bag.
		int itemCapacity;
		//The number of items in the Bag.
		int itemSize;
	public:
		//Default Constructor -- makes no allocations
		Bag();
		//Explicit Value Constructor
		Bag(int cap);
		//Copy Constructor
		Bag(const Bag& rhs);
		//Assignment Operator
		Bag& operator=(const Bag& rhs);
		//Destructor
		~Bag();
		//Add to end
		void push_back(Element e);
		//Remove from the end and return that value
		//May try to access something out of range
		Element pop_back();
		//Access something at a given position
		//May try to access something out of range
		Element& operator[](int i);
		//Look for an Element and return the first position it is found 
		//in the bag -- return -1 if not found
		int find(Element e);
		//Return the size of the array (number of items in the Bag);
		int size();
		//Return the capacity of the array (number of items the Bag can currently hold)
		int capacity();
		//Empty the contents of the Bag
		void clear();
		//Check to see if the Bag is empty
		bool empty();
		/**	Print the contents of the Bag. If a bag contains {1,2,3}, this will print on a
			new line, by itself:
			3 items: 1 2 3
		**/


		//checks if two bags are exactly the same
		bool operator==(const Bag &b) const;
		//checks if two bags are different from each other
		bool operator!=(const Bag &b) const;




		friend std::ostream& operator<<(std::ostream &os, const Bag& b);
};

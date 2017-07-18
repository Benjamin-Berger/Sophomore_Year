/** 
  Copyright  2014 - Jessica Hartog 
  Binghamton University, Computer Science Department
  Binghamton, NY 13902
 **/

#include <iostream>
#include "Bag.h"

using namespace std;

void init(){
	srand(time(NULL));
}

unsigned Simple::c = 1;

int main(){
	init();

	//For the purposes of these tests, it is assumed that the following work as intended
	//operator<<(ostream&, const Bag&)
	//Bag::size()
	//Bag::capacity()
	//Bag::operator==(const Bag&)
	//Bag::operator!=(const Bag&)

	//Default Constructor Test
	cout << endl << ">> Default Constructor Test: " << endl;
	Bag b0;
	if(b0.size() != 0 || b0.capacity() != 0){
		cerr << "Failed default constructor." << endl;
		cerr << "After default construction, size and capacity should be 0." << endl;
		return -1;
	}
	cout << "    Passed" << endl;

	//Explicit Value Constructor Test
	cout << endl << ">> Explicit Value Constructor Test: " << endl;

	Bag b1(3);
	if(b1.size() != 0 || b1.capacity() != 3){
		cerr << "Failed explicit value constructor." << endl;
		cerr << "After explicit construction with parameter 3, size should be 0 and capacity should be 3." << endl;
		return -2;
	}

	Bag b2(-1);
	if(b2.size() != 0 || b2.capacity() != 0){
		cerr << "Failed explicit value constructor." << endl;
		cerr << "After explicit construction with parameter -1, size and capacity should be 0." << endl;
		return -2;
	}
	cout << "    Passed" << endl;

	//Since Simple is our object type now -- we will create an assortment of simple objects
	Simple s0, s1, s2, s3, s4, s5, s6, s7, s8, s9;
	Simple s0c(s0), s1c(s1), s2c(s2), s3c(s3), s4c(s4), s5c(s5), s6c(s6), s7c(s7), s8c(s8), s9c(s9);

	//Push Back Test on Default Bag
	cout << endl << ">> Push Back Test on Default Bag: " << endl;

	b0.push_back(s1);
	if(b0.size() != 1 || b0.capacity() != 1){
		cerr << "Failed push_back on one item" << endl;
		cerr << "size: " << b0.size() << " capacity: " << b0.capacity() << endl;
		return -3;
	}
	b0.push_back(s2);
	if(b0.size() != 2 || b0.capacity() != 2){
		cerr << "Failed push_back on second item" << endl;
		cerr << "size: " << b0.size() << " capacity: " << b0.capacity() << endl;
		return -3;
	}
	b0.push_back(s3);
	if(b0.size() != 3 || b0.capacity() != 4){
		cerr << "Failed push_back on third item" << endl;
		cerr << "size: " << b0.size() << " capacity: " << b0.capacity() << endl;
		return -3;
	}
	cout << "    Passed" << endl;


	//Push Back Test on Explicit Bag
	cout << endl << ">> Push Back Test on Explicit Bag: " << endl;

	b1.push_back(s4);
	if(b1.size() != 1 || b1.capacity() != 3){
		cerr << "Failed push_back on one item" << endl;
		cerr << "size: " << b1.size() << " capacity: " << b1.capacity() << endl;
		return -4;
	}
	b1.push_back(s5);
	if(b1.size() != 2 || b1.capacity() != 3){
		cerr << "Failed push_back on second item" << endl;
		cerr << "size: " << b1.size() << " capacity: " << b1.capacity() << endl;
		return -4;
	}
	b1.push_back(s6);
	if(b1.size() != 3 || b1.capacity() != 3){
		cerr << "Failed push_back on third item" << endl;
		cerr << "size: " << b1.size() << " capacity: " << b1.capacity() << endl;
		return -4;
	}
	b1.push_back(s7);
	if(b1.size() != 4 || b1.capacity() != 6){
		cerr << "Failed push_back on fourth item" << endl;
		cerr << "size: " << b1.size() << " capacity: " << b1.capacity() << endl;
		return -4;
	}
	cout << "    Passed" << endl;


	//Copy Constructor Test
	cout << endl << ">> Copy Constructor Test: " << endl;

	Bag b0c(b0);
	if(b0 != b0c){
		cerr << "Failed Copy Constructor Test -- Not All Values Copied" << endl;
		return -5;
	}
	b0.push_back(s8);
	b0c.push_back(s9);
	if(b0 == b0c){
		cerr << "Failed Copy Constructor Test -- No Deep Copy Made" << endl;
		return -5;
	}

	Bag b1c(b1);
	if(b1 != b1c){
		cerr << "Failed Copy Constructor Test -- Not All Values Copied" << endl;
		return -5;
	}
	b1.push_back(s0);
	b1c.push_back(s1);
	if(b1 == b1c){
		cerr << "Failed Copy Constructor Test -- No Deep Copy Made" << endl;
		return -5;
	}

	Bag b2c(b2);
	if(b2 != b2c){
		cerr << "Failed Copy Constructor Test -- Not All Values Copied" << endl;
		return -5;
	}
	b2.push_back(s3);
	if(b2 == b2c){
		cerr << "Failed Copy Constructor Test -- No Deep Copy Made" << endl;
		return -5;
	}
	cout << "    Passed" << endl;

	//Assignment Operator Test
	cout << endl << ">> Assignment Operator Test: " << endl;

	b0c = b0;
	if(b0 != b0c){
		cerr << "Failed Assignment Operator Test -- Not All Values Copied" << endl;
		return -6;
	}
	b1c = b1;
	if(b1 != b1c){
		cerr << "Failed Assignment Operator Test -- Not All Values Copied" << endl;
		return -6;
	}
	b2c = b2;
	if(b2 != b2c){
		cerr << "Failed Assignment Operator Test -- Not All Values Copied" << endl;
		return -6;
	}
	cout << "    Passed" << endl;

	//Pop Back Test
	cout << endl << ">> Pop Back Test: " << endl;
	Simple s;
	s = b0.pop_back();
	if(s != s8){ cout << "Wrong Return In Pop Back" << endl; return -7;}
	if(b0.capacity() != 4){ cout << "Capacity Changed in Pop Back" << endl; return -7;}
	if(b0.size() != 3){ cout << "Size Did Not Change in Pop Back" << endl; return -7;}
	s = b0.pop_back();
	if(s != s3){ cout << "Wrong Return In Pop Back" << endl; return -7;}
	if(b0.capacity() != 4){ cout << "Capacity Changed in Pop Back" << endl; return -7;}
	if(b0.size() != 2){ cout << "Size Did Not Change in Pop Back" << endl; return -7;}
	s = b0.pop_back();
	if(s != s2){ cout << "Wrong Return In Pop Back" << endl; return -7;}
	if(b0.capacity() != 4){ cout << "Capacity Changed in Pop Back" << endl; return -7;}
	if(b0.size() != 1){ cout << "Size Did Not Change in Pop Back" << endl; return -7;}
	s = b0.pop_back();
	if(s != s1){ cout << "Wrong Return In Pop Back" << endl; return -7;}
	if(b0.capacity() != 4){ cout << "Capacity Changed in Pop Back" << endl; return -7;}
	if(b0.size() != 0){ cout << "Size Did Not Change in Pop Back" << endl; return -7;}
	try{
		cout << "\t Calling Pop Back on an Empty Bag: ";
		s = b0.pop_back();
		return -7;
	} catch (out_of_range &oor){
		cout << " Exception successfully caught. " << endl;
	}
	cout << "    Passed" << endl;

	//Operator [] Test
	cout << endl << ">> Operator [] Test: " << endl;

	try{
		cout << "\t Calling [-1]: ";
		s = b1[-1];
		return -8;
	} catch (out_of_range &oor){
		cout << " Exception successfully caught. " << endl;
	}
	s = b1[0];
	if(s != s4){
		cout << "Incorrect return from []." << endl;
		return -8;
	}
	s = b1[1];
	if(s != s5){
		cout << "Incorrect return from []." << endl;
		return -8;
	}
	s = b1[2];
	if(s != s6){
		cout << "Incorrect return from []." << endl;
		return -8;
	}
	s = b1[3];
	if(s != s7){
		cout << "Incorrect return from []." << endl;
		return -8;
	}
	s = b1[4];
	if(s != s0){
		cout << "Incorrect return from []." << endl;
		return -8;
	}
	b1c = Bag(8);
	b1c.push_back(s0);
	b1c.push_back(s1);
	b1c.push_back(s2);
	b1c.push_back(s0c);
	b1c.push_back(s1c);
	try{
		b1[0] = b1c[0];
		b1[1] = b1c[1];
		b1[2] = b1c[2];
		b1[3] = b1c[3];
		b1[4] = b1c[4];
	} catch (out_of_range &oor){
		cout << "Exception thrown when it ought not have been." << endl;
	}

	try{
		cout << "\t Calling [] beyond itemSize on RHS: ";
		s = b1[5];
		return -8;
	} catch (out_of_range &oor){
		cout << " Exception successfully caught." << endl;
	}

	try{
		cout << "\t Calling [] beyond itemSize on LHS: ";
		b1[5] = s9c;
		return -8;
	} catch (out_of_range &oor){
		cout << " Exception successfully caught." << endl;
	}

	try{
		cout << "\t Calling [] beyond itemCapacity on RHS: ";
		s = b1[100];
		return -8;
	} catch (out_of_range &oor){
		cout << " Exception successfully caught." << endl;
	}

	try{
		cout << "\t Calling [] beyond itemCapacity on LHS: ";
		b1[100] = s8c;
		return -8;
	} catch (out_of_range &oor){
		cout << " Exception successfully caught." << endl;
	}
	cout << "    Passed" << endl;

	//Find Test
	cout << endl << ">> Find Test: " << endl;
	int idx;
	idx = b1.find(s2);
	if(idx != 2){
		cout << "Find did not return correct index when found and unique." << endl;
		cout << "Returned " << idx << ", but should have returned 2" << endl;
		return -9;
	}
	idx = b1.find(s0);
	if(idx != 0){ 
		cout << "Find did not return correct index when found and duplicate." << endl;
		cout << "Returned " << idx << ", but should have returned 0" << endl;
		return -9;
	}
	idx = b1.find(s9);
	if(idx != -1){
		cout << "Find did not return correct index when not found." << endl;
		cout << "Returned " << idx << ", but should have returned -1" << endl;
		return -9;
	}


	cout << "    Passed" << endl;

	//Clear Test
	cout << endl << ">> Clear Test: " << endl;
	Bag b3;
	b0.clear();
	if(b0 != b3){
		cout << "Clear failed on a bag that was already empty." << endl;
		cout << "After clearing: " << b0 << endl;
		return -10;
	}
	b1.clear();
	if(b1 != b3){
		cout << "Clear failed on a bag that contained items." << endl;
		cout << "After clearing: " << b1 << endl;
		return -10;
	}

	cout << "    Passed" << endl;

	//Empty Test
	cout << endl << ">> Empty Test: " << endl;
	if(!b3.empty()){
		cout << "Empty failed on an empty bag." << endl;
		cout << b3 << endl;
		cout << " came back as non-empty." << endl;
		return -11;
	}
	if(b1c.empty()){
		cout << "Empty failed on a non-empty bag." << endl;
		cout << b1c << endl;
		cout << " came back as empty." << endl;
		return -11;		
	}
	cout << "    Passed" << endl;
}

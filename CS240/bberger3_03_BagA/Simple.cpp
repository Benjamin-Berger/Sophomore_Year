/** 
  Copyright  2014 - Jessica Hartog 
  Binghamton University, Computer Science Department
  Binghamton, NY 13902
 **/

#include "Simple.h"

using namespace std;

Simple::Simple(){
	simple = new double[2];
	simple[0] = rand()/1000.0;
	simple[1] = rand()/1000.0;
	id = c++;
	return;
}
Simple::~Simple(){
	delete[] simple;
	return;
}
Simple::Simple(const Simple& rhs){
	simple = new double[2];
	simple[0] = rhs.simple[0];
	simple[1] = rhs.simple[1];
	id = rhs.id;
	return;
}
Simple& Simple::operator=(const Simple& rhs){
	simple[0] = rhs.simple[0];
	simple[1] = rhs.simple[1];
	id = rhs.id;
	return *this;
}
bool Simple::operator==(const Simple& rhs) const{
	if(simple[0] != rhs.simple[0]){ return false;}
	if(simple[1] != rhs.simple[1]){ return false;}
	if(id != rhs.id){ return false;}
	return true;
}

bool Simple::operator!=(const Simple& rhs) const{
	/**
	  Here we have three options:
	  1) We can change all the conditions in the code for == at exactly opposite times, and leave the rest of the code the same
	  2) We can change all of the return statements in the code for == to return exactly the opposite, and leave the rest of the code the same
	  3) We can just call the == operator and return the opposite of what it returns

	  I went with option 3
	**/
	return !(operator==(rhs));
}
ostream& operator<<(ostream& o, const Simple& rhs){
	o << rhs.id << ":(" << rhs.simple[0] << "," << rhs.simple[1] << ")";
	return o;
}

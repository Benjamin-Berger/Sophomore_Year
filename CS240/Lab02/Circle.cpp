#include "Circle.h"

#define PI 3.14159265358979

#define C_DEBUG true

using namespace std;

//TODO
//Default Constructor (Assigns unit circle)
Circle::Circle(){
	if(C_DEBUG) {cout << "-- Circle -- Default constructor called." << endl;}
}

//Copy Constructor (Copies values from the argument)
Circle::Circle(const Circle &other){
	if(C_DEBUG) {cout << "-- Circle -- Copy constructor called." << endl;}
	center = other.center;
	radius = other.radius;
}

//TODO
//Explicit Value Constructor (Uses parameters to assign to circle)
Circle::Circle(Point center, double radius){
	if(C_DEBUG) {cout << "-- Circle -- Explicit value constructor called." << endl;}
}

//Assignment Operator (copies values from the argument)
Circle& Circle::operator=(const Circle &rhs){
	if(C_DEBUG) {cout << "-- Circle -- Assignment operator called." << endl;}
	//Alias test
	if(this!=&rhs){
		center = rhs.center;
		radius = rhs.radius;
	}
	return *this;
}

//TODO
//Returns the area of the circle
double Circle::area(){
}

//TODO
//Returns the circumference of the circle
double Circle::circumference(){
}

//TODO
//Determines whether or not a point is inside (positive), on (zero), or outside (negative) the edge of the circle
int Circle::compare(Point &point){
}

//TODO
//Returns the length of the arc that subtends the central angle (central angle measurement in degrees)
double Circle::arclength(double central_angle){
}

//Destructor
Circle::~Circle(){
	if(C_DEBUG) {cout << "-- Circle -- Destructor called." << endl;}
}

//TODO
//Prompts the user for a Point (center) and stores it
//then prompts the user for the radius and stores it
istream& operator>>(istream& is, Circle& c){
	if(C_DEBUG) {cout << "-- Operator >> called on a Circle." << endl;}
}

//TODO
//Prints out (on one line, and separated with spaces) the center and radius of the circle (labeled and separated with a colon and space)
ostream& operator<<(ostream& os, Circle& c){
	if(C_DEBUG) {cout << "-- Operator << called on a Circle." << endl;}
}


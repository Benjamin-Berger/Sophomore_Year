#include "ClassA.h"

//converts a bool value to a string that expresses that value
//without this function, printing the bool will print either 0 or 1
const char* ClassA::toString(bool x){ 
	return x ? "true" : "false";
}


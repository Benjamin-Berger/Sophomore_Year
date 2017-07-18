#ifndef __CLASSA_H
#define __CLASSA_H

#include <iostream>

/**
	This is the class defined according to PreLab1.pdf
  **/
class ClassA{
	public:
		void q1(int array[], int size, int n);
		void q2(int a, int b);
		int q3(int p, int q);
		void q4(bool a, bool b);
		void q5();
	private:
		int q3_helper(int p, int q, int accum1, int accum2);
		const char* toString(bool x);

};

#endif	//__CLASSA_H

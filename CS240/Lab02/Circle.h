#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include <iostream>
#include "Point.h"

class Circle{
	public:
		Circle();
		Circle(const Circle &other);					//given
		Circle(Point center, double radius);
		Circle& operator=(const Circle &rhs);				//given
		double area();
		double circumference();
		int compare(Point &point);
		double arclength(double central_angle);
		~Circle();							//given
		friend std::istream& operator>>(std::istream& is, Circle& c);
		friend std::ostream& operator<<(std::ostream& os, Circle& c);
	private:
		Point center;	
		double radius;
};

#endif //CIRCLE_H

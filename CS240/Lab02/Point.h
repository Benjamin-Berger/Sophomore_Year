#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <iostream>

class Point{
	public:
		Point();
		Point(const Point& point);						//given
		Point(int x, int y);
		Point& operator=(const Point &rhs);					//given
		double operator-(const Point &p) const;
		~Point();								//given
		friend std::ostream& operator<<(std::ostream& os, const Point& p);
		friend std::istream& operator>>(std::istream& is, Point& p);
	private:
		int x;
		int y;
};


#endif //POINT_H

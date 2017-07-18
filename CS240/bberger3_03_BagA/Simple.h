/** 
  Copyright  2014 - Jessica Hartog 
  Binghamton University, Computer Science Department
  Binghamton, NY 13902
 **/

#ifndef SIMPLE_H
#define SIMPLE_H

#include <iostream>
#include <ctime>
#include <cstdlib>


class Simple{
	public:
		Simple();
		~Simple();
		Simple(const Simple& rhs);
		Simple& operator=(const Simple& rhs);
		bool operator==(const Simple& rhs) const;
		bool operator!=(const Simple& ths) const;
		friend std::ostream& operator<<(std::ostream& o, const Simple& rhs);
	private:
		double* simple;
		unsigned id;
		static unsigned c;
};

#endif //SIMPLE_H

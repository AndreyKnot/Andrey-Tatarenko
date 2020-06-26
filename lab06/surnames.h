#pragma once
#include "basic_class.h"

class Surname : public Student
{
private:
	string sur_star;
	string sur_cur;

public:
	string get_sur_star() const;
	string get_sur_cur() const;

	void set_sur_star(string);
	void set_sur_cur(string);

	Surname();
	Surname(int, int, int, string, bool, int, sint, string, string, string);
	Surname(const Surname& other);
	~Surname();
};
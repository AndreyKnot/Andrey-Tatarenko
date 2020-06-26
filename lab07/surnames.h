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

	void print() const override;
	stringstream get_str() const override;
	void write_in_file(ofstream& el) override;

	Surname();
	Surname(int, int, int, string, bool, int, sint, string, string, string);
	Surname(const Surname& other);
	~Surname();
};
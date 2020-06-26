#pragma once
#include "basic_class.h"
#include <string>

using std::string;
using std::ostream;
using std::istream;

class Course final : public Student
{
private:
	int course;

public:
	int get_course();
	void set_course(int);

	void print() const override;
	stringstream get_str() const override;
	void write_in_file(ofstream& el) override;

	Course();
	Course(int, int, int, string, bool, int, sint, string, int);
	Course(const Course& other);
	~Course();
	////////////////////////////////////////////////////////
	string getInfo() const override final;
	stringstream getStr() const override final;
	void input(istream&) override final;

	Course& operator= (Course&);
	bool operator==(const string) const override final;
};
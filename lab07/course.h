#pragma once
#include "basic_class.h"

class Course : public Student
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
};
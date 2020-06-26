#pragma once
#include "class1.h"

class Course final : public Student
{
private:
	int course;

public:
	string get_info() const override final;
	stringstream get_str() const override final;

	Course();
	Course(int, int, int, string, bool, int, int);
	Course(const Course&);
	~Course() override final;

	bool operator==(const int) const override final;
};

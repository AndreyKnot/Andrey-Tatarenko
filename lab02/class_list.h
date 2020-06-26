#pragma once
#include "basic_class.h"

class Arr
{
private:

	Student* array_stud;

	int count = El;

public:

	void create_array();

	void print_array() const;

	void delete_one();

	void add();

	void select() const;

	void fill_array();

	int count_plus();

	int count_minus();

	void print_one(Student) const;

	void delete_array();

	Student Construct(int);

	int prog_d_rand(bool);

	void find_debt();

};
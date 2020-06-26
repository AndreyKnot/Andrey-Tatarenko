#pragma once
#include "surnames.h"

class Arr_Sur
{
private:

	Surname* array_sur;

	int count = El;

public:

	void create_array();

	void print_array(int) const;

	void delete_one();

	void add();

	string select() const;

	void fill_array();

	int count_plus();

	int count_minus();

	void print_one(Surname) const;

	void delete_array();

	Surname Construct(int);

	int prog_d_rand(bool);

	void find_debt();

	void in_f();

	void from_f(int);

	int get_count() const;

	int str_in_file(string) const;

	void set_count(int);

	void regex_task();

	void sort(comp);

	static bool sort_forward(const int&, const int&);

	static bool sort_back(const int&, const int&);

};
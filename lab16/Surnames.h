#pragma once

#include "Student.h"

class Surnames final : public Student
{
private:
	string star;
	string cur;

public:
	int get_age() const override;
	int get_number() const override;
	int get_mark() const override;
	int get_dprog()const override;
	bool get_debt()const override;
	string get_name() const override;

	string getInfo() const override;
	void enter(istream&) override;

	Surnames();
	Surnames(int, int, int, string, bool, int, string, string);
	Surnames(const Surnames&);
	~Surnames() override;

	void* operator new(size_t);
	void* operator new[](size_t);
	void operator delete(void*);
	void operator delete[](void*);
};

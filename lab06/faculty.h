#pragma once

#include <string>
using std::string;

class Fac
{
private:
	string fname;
public:
	string get_fname() const;
	void set_fname(string);

	Fac();
	Fac(string);
	Fac(const Fac& other);
	~Fac();
};
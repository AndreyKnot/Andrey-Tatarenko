#pragma once
#include <string>

using std::string;
using std::ostream;
using std::istream;

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
	/////////////////////////////////////////////////
	friend istream& operator>> (istream&, Fac&);
	friend ostream& operator<< (ostream&, const Fac&);
};
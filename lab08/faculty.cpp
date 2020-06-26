#include "faculty.h"

string Fac::get_fname() const
{
	return fname;
}

void Fac::set_fname(string fn)
{
	fname = fn;
}

Fac::Fac() : fname("Non")
{
}

Fac::Fac(string fn) : fname(fn)
{
}

Fac::Fac(const Fac& other) : fname(other.fname)
{
}

Fac::~Fac()
{
}
/////////////////////////////////////////////////////////
istream& operator>> (istream& input, Fac& date)
{
	input >> date.fname;

	return input;
}
ostream& operator<< (ostream& output, const Fac& date)
{
	output << date.fname;

	return output;
}
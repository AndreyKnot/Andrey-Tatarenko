#include "surnames.h"

string Surname::get_sur_star() const
{
	return sur_star;
}

string Surname::get_sur_cur() const
{
	return sur_cur;
}

void Surname::set_sur_star(string s_s)
{
	sur_star = s_s;
}

void Surname::set_sur_cur(string s_c)
{
	sur_cur = s_c;
}

Surname::Surname() : Student(0, 0, 0, "Name", 0, 0, 0, "Non"), sur_star("Surname"), sur_cur("Surname")
{

}

Surname::Surname(int a, int n, int m, string na, bool d, int pd, sint an, string fc, string s_s, string s_c) : Student(a, n, m, na, d, pd, an, fc), sur_star(s_s), sur_cur(s_c)
{

}

Surname::Surname(const Surname& other) : Student(other), sur_star(other.sur_star), sur_cur(other.sur_cur)
{

}

Surname::~Surname()
{

}
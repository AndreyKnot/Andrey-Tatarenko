#include "audience.h"

sint Aud::get_aud_numb() const
{
	return aud_numb;
}

void Aud::set_aud_numb(sint a_n)
{
	aud_numb = a_n;
}

Aud::Aud() : aud_numb(0)
{
}

Aud::Aud(sint aud_numb) : aud_numb(aud_numb)
{
}

Aud::Aud(const Aud& other) : aud_numb(other.aud_numb)
{
}

Aud::~Aud() 
{
}
////////////////////////////////////////////////
istream& operator>> (istream& input, Aud& author)
{
	input >> author.aud_numb;
	return input;
}
ostream& operator<< (ostream& output, const Aud& author)
{
	output << author.aud_numb;
	return output;
}
bool Aud::operator==(const sint author) const
{
	return this->aud_numb == author;
}
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
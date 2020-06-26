#include "Functor.h"

bool Functor::operator() (const shared_ptr<Student>& st1, const shared_ptr<Student>& st2)
{
	if (value % 2 != 0)
		return st1->get_numb() < st2->get_numb();
	else
		return st1->get_numb() > st2->get_numb();
}

Functor::Functor(int value) :value(value) {}
Functor::~Functor() {}
#pragma once

#include "class1.h"

class Functor
{
private:
	int value;

public:
	bool operator()(const shared_ptr<Student>&, const shared_ptr<Student>&);

	Functor(int);
	~Functor();
};

#pragma once
#include "Student.h"

class Foreign final : public Student
{
private:
	string country;

public:
	string getInfo() const override final;
	friend ostream& operator<<(ostream&, const Foreign) noexcept;

	Foreign();
	Foreign(string, string, int);
	Foreign(const Foreign&);
	~Foreign() override final;
};

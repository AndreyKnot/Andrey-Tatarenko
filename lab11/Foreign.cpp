#include "Foreign.h"

string Foreign::getInfo() const
{
	stringstream temp;
	temp.setf(std::ios::left);
	temp << setw(11) << name << setw(10) << age << setw(6) << country;

	return temp.str();
}

ostream& operator<<(ostream& output, const Foreign& Fore) noexcept
{
	output.setf(std::ios::left);
	output << Fore.getInfo();

	return output;
}

Foreign::Foreign() :Student(), country("Зимбабве") {}
Foreign::Foreign(string country, string name, int age) : country(country), Student(name, age) {}
Foreign::Foreign(const Foreign& other) : Student(other), country(other.country) {}
Foreign::~Foreign() {}
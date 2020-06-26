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

void Surname::print() const
{
	cout << "Возраст: " << age << "\tНомер студента: " << number_stud << "\tСредний балл: " << middle_mark << "\tИмя: "
		<< name << "\tДолг: " << debt << "\tДолг с прог: " << prog_d << "\tНомер аудитории: " << audience.get_aud_numb()
		<< "\tФакультет: " << faculty.get_fname() << "\tСтароста: " << sur_star << "\tКуратор: " << sur_cur << endl;
}

stringstream Surname::get_str() const
{
	stringstream temp;

	temp << "Возраст: " << age << "\tНомер студента: " << number_stud << "\tСредний балл: " << middle_mark << "\tИмя: "
		<< name << "\tДолг: " << debt << "\tДолг с прог: " << prog_d << "\tНомер аудитории: " << audience.get_aud_numb()
		<< "\tФакультет: " << faculty.get_fname() << "\tСтароста: " << sur_star << "\tКуратор: " << sur_cur << endl;

	return temp;
}

void Surname::write_in_file(ofstream& el)
{
	el << "Возраст: " << age << "\tНомер студента: " << number_stud << "\tСредний балл: " << middle_mark << "\tИмя: "
		<< name << "\tДолг: " << debt << "\tДолг с прог: " << prog_d << "\tНомер аудитории: " << audience.get_aud_numb()
		<< "\tФакультет: " << faculty.get_fname() << "\tСтароста: " << sur_star << "\tКуратор: " << sur_cur << endl;
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
////////////////////////////////////////////////////
Surname& Surname::operator=(Surname& temp)
{
	if (this == &temp) return *this;

	Student::operator=(temp);
	string sur_star = temp.sur_star;
	string sur_cur = temp.sur_cur;

	return *this;
}

bool Surname::operator==(const string name) const
{
	return this->name == name;
}

stringstream Surname::getStr() const
{
	stringstream temp;

	temp << "Возраст: " << age << "\tНомер студента: " << number_stud << "\tСредний балл: " << middle_mark << "\tИмя: "
		<< name << "\tДолг: " << debt << "\tДолг с прог: " << prog_d << "\tНомер аудитории: " << audience.get_aud_numb()
		<< "\tФакультет: " << faculty.get_fname() << "\tСтароста: " << sur_star << "\tКуратор: " << sur_cur << endl;

	return temp;
}

string Surname::getInfo() const
{
	stringstream temp;
	temp.setf(ios::left);

	temp << "Возраст: " << age << "\tНомер студента: " << number_stud << "\tСредний балл: " << middle_mark << "\tИмя: "
		<< name << "\tДолг: " << debt << "\tДолг с прог: " << prog_d << "\tНомер аудитории: " << audience.get_aud_numb()
		<< "\tФакультет: " << faculty.get_fname() << "\tСтароста: " << sur_star << "\tКуратор: " << sur_cur << endl;

	return temp.str();
}

void Surname::input(istream& input)
{
	input >> age >> number_stud >> middle_mark >> name >> debt >> prog_d 
		>> audience >> faculty >> sur_star >> sur_cur;
}
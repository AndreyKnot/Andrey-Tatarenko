/**
* @file list.cpp
* ���� ��������� ������ ����� CList
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#include "list.h" /** ϳ��������� ����� list.h */

CList::~CList() /** ��������� ����������� */
{
	StudentList.clear(); /** �������� ���'�� ������ ������� */
}

CList::CList() /** ��������� ������������ �� ������������� */
{
	for (size_t i = 0; i < 5; i++) /** �����, ���� �������� ������ ���������� */
	{
		if (i == 0)
			StudentList.emplace_back(new Student());
		else if (i == 1)
			StudentList.emplace_back(new Course(18, 2, 8, "Andry", 1, 20, 2));
		else if (i == 2)
			StudentList.emplace_back(new Student(19, 3, 7, "Jhon", 1, 30));
		else if (i == 3)
			StudentList.emplace_back(new Surnames(19, 4, 10, "Dmitry", 0, 0, "Miler"));
		else
			StudentList.emplace_back(new Course(20, 5, 7, "Jim", 1, 30, 3));
	}
}

void CList::PrintList() const noexcept /** ��������� ������ ��������� ������ �� ����� */
{
	try
	{
		if (StudentList.size() == 0) /** �������� ������ ������ */
			throw exception("������ ����.");

		int value = 1;

		cout << endl << setiosflags(ios::left);
		cout << setw(10) << "�������" << setw(8) << "�����";
		cout << setw(15) << "������� ����" << setw(7) << "���";
		cout << setw(10) << "����" << setw(14) << "����(����.)";
		cout << setw(7) << "����/��������" << endl; /** ��������� ���� ���� ����� */

		for_each(StudentList.begin(), StudentList.end(), [&value](const unique_ptr<Student>& Student) /** ����, ���� �������� ������ �������� */
		{
			cout << *Student << endl; /** ��������� ������ �� ���� �������� */
			value++; /** ��������� ���� ����������� */
		});

		cout << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

int CList::Task() const /** ��������� ������ ��������� �������������� �������� */
{
	int value = 1; /** ���������� ����� ������� ��������� �������� */

	for (const auto& Student : StudentList) /** ���� ���� �������� �� �������� ������ */
	{
		if (Student->get_debt() == 1) /** �������� ���� �������� */
		{
			cout << value << ". " << *Student << endl; /** ��������� �������� �� ����� */
			value++; /** ��������� ����� ����������� ������ */
		}
	}

	if (value == 0) /** ���� �������� ���� */
		throw exception("��������� � ������ ����������� �����������.");

	return value; /** ���������� ������� ��������� �������� */
}

int CList::AddStudent(int value) /** ��������� ������ ��������� ���� �������� */
{
	if (value == 1)
	{
		Student* temp = new Student; /** ��������� �������� ����� Student */
		StudentList.emplace_back(temp); /** ������� �������� � ����� */
	}
	else if (value == 2)
	{
		Student* temp = new Course; /** ��������� �������� ����� Course */
		StudentList.emplace_back(temp); /** ������� �������� � ����� */
	}
	else if (value == 3)
	{
		Student* temp = new Surnames; /** ��������� �������� ����� Surnames */
		StudentList.emplace_back(temp); /** ������� �������� � ����� */
	}
	else
		throw exception("�������� �������.");

	return StudentList.size(); /** ���������� ������ ������ */
}

int CList::DeleteStudent(int value) /** ��������� ������ ��������� �������� */
{
	if (StudentList.size() == 0) /** �������� ������ ������ */
		throw exception("C����� �������� ����.");

	int number = -1;
	bool findEl = false;
	std::vector<unique_ptr<Student>>::iterator it; /** ��������� ��������� */

	for (const auto& Student : StudentList) /** ����, ���� �������� �� �������� �������� */
	{
		if (Student->get_number() == value) /** ���� �������� �� �������� ������ */
		{
			number++; /** ��������� ����� ������ �������� */
			findEl = true; /** ������� ���� ����������� �������� */
			break; /** ������� ������ ����� */
		}
		else
			number++; /** ��������� ����� ������ �������� */
	}

	if (findEl) /** ���� ������� � �������� �������� ��� ������ */
	{
		it = StudentList.begin(); /** ������������ ��������� �� ������� ������ */
		advance(it, number); /** ���������� ��������� �� �������� ������� */
		StudentList.erase(it); /** ��������� ��������� �������� */

		cout << "�������� ���������." << endl;
	}
	else
		throw exception("������� �� ������.");

	return StudentList.size(); /** ���������� ����� ������ ������ */
}

void CList::Sort(Functor& choise) noexcept /** ��������� ������ ���������� ������ */
{
	std::sort(StudentList.begin(), StudentList.end(), choise); /** ���������� ������ */
}

int CList::SaveFile(string filename) const /** ��������� ������ ������ ����� � ���� */
{
	if (StudentList.size() == 0) /** �������� ������ ������ */
		throw exception("������ ����.");

	ofstream fout(filename); /** ³������� ����� */
	if (!fout.is_open()) /** �������� �� �������� ���� */
		throw exception("���������� ������� ����.");

	fout << setiosflags(ios::left);
	fout << setw(10) << "�������" << setw(8) << "�����";
	fout << setw(15) << "������� ����" << setw(7) << "���";
	fout << setw(10) << "����" << setw(14) << "����(����.)";
	fout << setw(7) << "����/��������" << endl; /** ��������� ���� ���� */

	int value = 1;
	for (const auto& Student : StudentList) /** ����, ���� �������� �� �������� ������ */
	{
		fout << setiosflags(ios::left) << setw(2) << value << ". "; /** ��������� ����������� �������� */
		fout << *Student << endl; /** ��������� ���� �������� */
		value++;
	}

	fout.close(); /** �������� ����� */
	return value - 1; /** ���������� ������� ��������, �� ���� �������� � ���� */
}

int CList::ReadFile(string filename) /** ��������� ������ ������� ����� � ����� */
{
	regex expressionStudent("([\\d]* [\\d]* [\\d]* [A-Z]+[\\w,.;:-]* [0|1] [\\d]* )"); /** ���������� ����� ��� ����� Student */
	regex expressionCourse("([\\d]* [\\d]* [\\d]* [A-Z]+[\\w,.;:-]* [0|1] [\\d]* [\\d]* )"); /** ���������� ����� ��� ����� Course */
	regex expressionSurnames("([\\d]* [\\d]* [\\d]* [A-Z]+[\\w,.;:-]* [0|1] [\\d]* [A-Z]+[\\w,.;:-]* )"); /** ���������� ����� ��� ����� Surnames */
	regex replaceSymbols("[;:-]"); /** ���������� ����� ��� �������, �� ����� ������� */

	string temp, data, replacement = "";
	int value = 0;
	ifstream fin(filename); /** ³������� ����� */
	istringstream ss;

	if (!fin.is_open()) /** �������� �� �������� ���� */
	{
		throw exception("���������� ������� ���� ��� ������.");
		return StudentList.size();
	}

	while (!fin.eof()) /** ����, ���� ������ �� ���� ����� */
	{
		getline(fin, data); /** ��������� ������ � ����� */
		temp = regex_replace(data, replaceSymbols, replacement); /** ��������� ������� �� �� �������� */
		temp += " ";

		if (regex_match(temp, expressionStudent)) /** �������� �� ���������� �� ����� Student */
		{
			istringstream ss(temp);
			Student* Stud = new Student(); /** ��������� ����� ����� Student */

			ss >> *Stud;
			StudentList.emplace_back(Stud); /** ������� �������� � ����� */
			value++; /** ��������� ����� ������� ����� �������� */
		}
		else if (regex_match(temp, expressionCourse)) /** �������� �� ���������� �� ����� Student */
		{
			istringstream ss(temp);
			Course* Student = new Course(); /** ��������� ����� ����� Course */

			ss >> *Student;
			StudentList.emplace_back(Student); /** ������� �������� � ����� */
			value++; /** ��������� ����� ������� ����� �������� */
		}
		else if (regex_match(temp, expressionSurnames)) /** �������� �� ���������� �� ����� Student */
		{
			istringstream ss(temp);
			Surnames* Student = new Surnames(); /** ��������� ����� ����� Surnames */

			ss >> *Student;
			StudentList.emplace_back(Student); /** ������� �������� � ����� */
			value++; /** ��������� ����� ������� ����� �������� */
		}
	}

	fin.close(); /** �������� ����� */
	return value; /** ���������� ����� ������� ����� �������� */
}

int CList::get_numb(int value) const /** ��������� ������ ��������� ������ �������� */
{
	return StudentList[value]->get_number(); /** ���������� ������ */
}
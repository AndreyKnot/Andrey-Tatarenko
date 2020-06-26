#include "class2.h"
#include "SmartPointer.h"

void func();

int main()
{
	setlocale(LC_ALL, "ru");

	func();

	if (_CrtDumpMemoryLeaks())
		cout << endl << "���������� ������!" << endl;
	else
		cout << endl << "������ ������ �����������." << endl;

	system("PAUSE");
	return 0;
}

void func()
{
	int value;
	vector <Student*> vector;

	try
	{
		auto_ptr<Course> autoptr(new Course);
		shared_ptr<Student> sharedptr = make_shared<Student>(19, 4, 9, "Jhon", 1, 14);
		unique_ptr<Course> uniqueptr = make_unique<Course>(17, 4, 10, "Peter", 0, 0, 1);
		SmartPointer<Course> MyPointer = new Course;
		weak_ptr<Student> weakptr = sharedptr;
		shared_ptr<Student> sharedptr2 = weakptr.lock();
		SmartPointer<Course> MyPointer2 = MyPointer;

		cout << endl << endl;
		cout << "����� �������(����� ���������): " << MyPointer.operator->() << endl;
		cout << "����� ����� �������: " << MyPointer2.operator->() << endl;
		cout << endl;

		cout << setw(10) << "�������" << setw(8) << "�����";
		cout << setw(15) << "������� ����" << setw(7) << "���";
		cout << setw(10) << "����" << setw(14) << "����(����.)";
		cout << setw(7) << "����" << endl;

		vector.emplace_back(autoptr.get());
		vector.emplace_back(sharedptr.get());
		vector.emplace_back(uniqueptr.get());
		vector.emplace_back(MyPointer.operator->());
		vector.emplace_back(sharedptr2.get());

		value = 1;
		for_each(vector.begin(), vector.end(), [&value](const Student* program)
		{
			cout << value << ". " << *program << endl;
			value++;
		});
		cout << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
}
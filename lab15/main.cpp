#include "class2.h"
#include "SmartPointer.h"

void func();

int main()
{
	setlocale(LC_ALL, "ru");

	func();

	if (_CrtDumpMemoryLeaks())
		cout << endl << "Обнаружена утечка!" << endl;
	else
		cout << endl << "Утечка памяти отсутствует." << endl;

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
		cout << "Адрес объекта(умным указатель): " << MyPointer.operator->() << endl;
		cout << "Адрес копии объекта: " << MyPointer2.operator->() << endl;
		cout << endl;

		cout << setw(10) << "Возраст" << setw(8) << "Номер";
		cout << setw(15) << "Средний балл" << setw(7) << "Имя";
		cout << setw(10) << "Долг" << setw(14) << "Долг(прог.)";
		cout << setw(7) << "Курс" << endl;

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
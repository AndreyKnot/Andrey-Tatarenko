#include "Surnames.h"
#include "Course.h"

#define SIZE 4

int main()
{
	setlocale(LC_ALL, "ru");

	Student* list[SIZE];

	list[0] = new Student();
	list[1] = new Course(18, 2, 8, "Andry", 1, 20, 2);
	list[2] = new Student(19, 3, 7, "Jhon", 1, 30);
	list[3] = new Surnames(19, 4, 10, "Dmitry", 0, 0, "Miler", "Grand");

	cout << endl;
	for (size_t i = 0; i < SIZE; i++)
		cout << *list[i] << endl;
	cout << endl;

	Student* list2 = new Student[SIZE];

	cout << endl;
	for (size_t i = 0; i < SIZE; i++)
		cout << list2[i] << endl;
	cout << endl;

	for (size_t i = 0; i < SIZE; i++)
		delete list[i];

	delete[] list2;

	if (_CrtDumpMemoryLeaks())
		cout << endl << "Есть утечка памяти." << endl;
	else
		cout << endl << "Утечка памяти отсутствует." << endl;

	system("PAUSE");

	return 0;
}
#include "MyClass.h"
#include "Header.h"
#include "Student.h"

void Test_FindEl(Class, int*, int);
void Test_Sort(Class, int*, int);
void Test_FindMin(Class, int*, int);
void Func();

int main()
{
	setlocale(LC_ALL, "ru");

	Func();

	if (_CrtDumpMemoryLeaks()) 
		cout << endl << "Обнаружена утечка памяти!" << endl;
	else 
		cout << endl << "Утечки не обнаруженно!" << endl;

	return 0;
}

void Func()
{
	Class element;
	int size = 10;
	int* array = new int[size] { 1, -5, 0, 22, 236, -523, 56423, -5634, -4235, 1000};

	Test_FindEl(element, array, size);
	Test_Sort(element, array, size);
	Test_FindMin(element, array, size);

	return;
}

void Test_FindEl(Class element, int* array, int size)
{
	int expected = 3;
	element.FindEl(array, size, 22);

	//if (expected == real) cout << "Тест нахождения элементов \t выполнен успешно.\n";
	//else cout << "Тест нахождения элементов \t не выполнен успешно.\n";
}
void Test_Sort(Class element, int* array, int size)
{
	int beforeSort = array[0];
	array = element.Sort(array, size, 1);
	int afterSort = array[0];

	if (beforeSort != afterSort && afterSort == 56423) cout << "Тест сортировки\t\t\t\t выполнен успешно.\n";
	else cout << "Тест сортировки\t\t\t\t не выполнен успешно.\n";
}
void Test_FindMin(Class element, int* array, int size)
{
	int temp = element.FindMin(array, size);

	if (temp == -5634) cout << "Тест нахождения минимального элемента\t выполнен успешно.\n";
	else cout << "Тест нахождения минимального элемента\t не выполнен успешно.\n";
}
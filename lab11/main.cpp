#include "TClass.h"
#include "Student.h"
#include "Header.h"
#include "Foreign.h"

void ArrayInt(int);
void ArrayFloat(int);
void ArrayClass(int);
Student** CreateArray(int);

int main()
{
	setlocale(LC_ALL, "ru");
	const int SIZE = 5;
	int choise = 0;

	while (choise != 4)
	{
		cout << "\nВыберете массив:\n1) типа int\n2) типа float\n";
		cout << "3) Свой тип данных\n4) Выйти\n";
		cout << "Массив: ";
		cin >> choise;

		if (choise == 1)
			ArrayInt(SIZE);
		else if (choise == 2)
			ArrayFloat(SIZE);
		else if (choise == 3)
			ArrayClass(SIZE);
		else if (choise > 4 || choise < 1)
			cout << endl << "Неверная команда. Повторите попытку." << endl;
		else
			choise = 4;
	}

	if (_CrtDumpMemoryLeaks())
		cout << endl << "Обнаружена утечка памяти!" << endl;
	else
		cout << endl << "Утечки не обнаруженно!" << endl;

	system("PAUSE");
	return 0;
}

void ArrayInt(int SIZE)
{
	int* arraySize = new int[SIZE];
	int** arrayInt = new int*[SIZE];
	int choise = 0, result = 0;

	for (size_t i = 0; i < SIZE; i++)
	{
		arraySize[i] = rand();
		arrayInt[i] = &arraySize[i];
	}

	TClass<int> element(arrayInt);
	cout << endl << "Массив типа int:" << endl;
	element.OutputArr(SIZE);

	choise = element.EnterEl(choise);
	result = element.FindEl(choise, SIZE);
	if (result == -1)
		cout << "Элемент с индексом " << choise << " отсутствует." << endl;
	else
		cout << "Индекс элемента " << choise << " : " << result << endl;

	choise = element.ChoiseSort(choise);
	element.Sort(SIZE, choise - 1);
	cout << endl << "Результат сортировки:" << endl;
	element.OutputArr(SIZE);

	result = element.FindMin(SIZE);
	cout << "Минимальный элемент в массиве: " << result << endl;

	delete[] arraySize;
	delete[] arrayInt;
}

void ArrayFloat(int SIZE)
{
	float* arraySize = new float[SIZE];
	float** arrayFloat = new float*[SIZE];
	float choise = 0, result = 0;

	for (size_t i = 0; i < SIZE; i++)
	{
		arraySize[i] = (rand() % 101 - 50) / 10.0;
		arrayFloat[i] = &arraySize[i];
	}

	TClass<float> element(arrayFloat);
	cout << endl << "Массив типа float:" << endl;
	element.OutputArr(SIZE);

	choise = element.EnterEl(choise);
	result = element.FindEl(choise, SIZE);
	if (result == -1)
		cout << "Элемент с индексом " << choise << " отсутствует." << endl;
	else
		cout << "Индекс элемента " << choise << " : " << result << endl;

	choise = element.ChoiseSort(choise);
	element.Sort(SIZE, choise - 1);
	cout << endl << "Результат сортировки:" << endl;
	element.OutputArr(SIZE);

	result = element.FindMin(SIZE);
	cout << "Минимальный элемент в массиве: " << result << endl;

	delete[] arraySize;
	delete[] arrayFloat;
}

void ArrayClass(int SIZE)
{
	Student guy;
	Student** ArrayClass = CreateArray(SIZE);
	TClass<Student> element(ArrayClass);
	int choise = 0, result = 0;

	cout << setw(6) << "Имя" << setw(10) << "Возраст" << setw(10) << "Страна" << endl;
	element.OutputArr(SIZE);

	cout << "Введите элемент, индекс которого хотите получить: ";
	cin >> guy;

	result = element.FindEl(guy, SIZE);
	if (result == -1)
		cout << "Элемент с индексом " << guy << " отсутствует." << endl;
	else
		cout << "Индекс элемента: " << result << endl;

	while (choise <= 0 || choise > 3)
	{
		cout << endl << "Сортировать по:" << endl;
		cout << "1) Убыванию\n2) Возрастанию\n3) Не сортировать\n";
		cout << "Ваш выбор: ";
		cin >> choise;

		if (choise <= 0 || choise > 3)
			cout << "Неверная команда. Повторите попытку." << endl;
	}

	if (choise == 1) choise = 1;
	else if (choise == 2) choise = 0;

	element.Sort(SIZE, choise);
	cout << endl << "Результат сортировки:" << endl;
	element.OutputArr(SIZE);

	guy = element.FindMin(SIZE);
	cout << "Минимальный элемент в массиве: " << guy << endl;

	for (size_t i = 0; i < SIZE; i++)
	{
		delete ArrayClass[i];
	}
	delete[] ArrayClass;
}

Student** CreateArray(int size)
{
	Student** array = new Student *[size];

	for (size_t i = 0; i < size; i++)
	{
		if (i == 0)
		{
			*(array + i) = new Student();
		}
		else if (i == 1)
		{
			*(array + i) = new Foreign("США", "Джим", 22);
		}
		else if (i == 2)
		{
			*(array + i) = new Student("Алексей", 17);
		}
		else if (i == 3)
		{
			*(array + i) = new Foreign("Португалия", "Георг", 20);
		}
		else
		{
			*(array + i) = new Student("Павел", 28);
		}
	}

	return array;
}
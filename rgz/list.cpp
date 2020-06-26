/**
* @file list.cpp
* Файл реалізації методів класу CList
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#include "list.h" /** Підключення файлу list.h */

CList::~CList() /** Реалізація деструктора */
{
	StudentList.clear(); /** Очищення пам'яті масива програм */
}

CList::CList() /** Реалізація конструктора за замовчуванням */
{
	for (size_t i = 0; i < 5; i++) /** Масив, який заповнює вектор елементами */
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

void CList::PrintList() const noexcept /** Реалізація методу виведення списку на екран */
{
	try
	{
		if (StudentList.size() == 0) /** Перевірка розміру списка */
			throw exception("Список пуст.");

		int value = 1;

		cout << endl << setiosflags(ios::left);
		cout << setw(10) << "Возраст" << setw(8) << "Номер";
		cout << setw(15) << "Средний балл" << setw(7) << "Имя";
		cout << setw(10) << "Долг" << setw(14) << "Долг(прог.)";
		cout << setw(7) << "Курс/Староста" << endl; /** Виведення назв полів класів */

		for_each(StudentList.begin(), StudentList.end(), [&value](const unique_ptr<Student>& Student) /** Цикл, який виводить список елементів */
		{
			cout << *Student << endl; /** Виведення номеру та полів елемента */
			value++; /** Збільшення зміної нумерування */
		});

		cout << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

int CList::Task() const /** Реалізація метода виконання індивідуального завдання */
{
	int value = 1; /** Оголошення змінної кількості відповідних елементів */

	for (const auto& Student : StudentList) /** Цикл який обходить усі елементи масиву */
	{
		if (Student->get_debt() == 1) /** Перевірка полів елементів */
		{
			cout << value << ". " << *Student << endl; /** Виведення елемента на екран */
			value++; /** Збільшення змінної нумерування масиву */
		}
	}

	if (value == 0) /** Якщо елементів немає */
		throw exception("Программы с такими параметрами отсутствуют.");

	return value; /** Повернення кількості відповідних елементів */
}

int CList::AddStudent(int value) /** Реалізація метода додавання нової програми */
{
	if (value == 1)
	{
		Student* temp = new Student; /** Створення елемента класу Student */
		StudentList.emplace_back(temp); /** Вставка елемента у масив */
	}
	else if (value == 2)
	{
		Student* temp = new Course; /** Створення елемента класу Course */
		StudentList.emplace_back(temp); /** Вставка елемента у масив */
	}
	else if (value == 3)
	{
		Student* temp = new Surnames; /** Створення елемента класу Surnames */
		StudentList.emplace_back(temp); /** Вставка елемента у масив */
	}
	else
		throw exception("Неверная команда.");

	return StudentList.size(); /** Повернення розміру списку */
}

int CList::DeleteStudent(int value) /** Реалізація метода видалення програми */
{
	if (StudentList.size() == 0) /** Перевірка розміру списку */
		throw exception("Cписок программ пуст.");

	int number = -1;
	bool findEl = false;
	std::vector<unique_ptr<Student>>::iterator it; /** Створення ітератора */

	for (const auto& Student : StudentList) /** Цикл, який обробляє усі елементи колекції */
	{
		if (Student->get_number() == value) /** Якщо програма має потрібний індекс */
		{
			number++; /** Збільшення змінної номеру елементу */
			findEl = true; /** Змінення зміної знаходження елемента */
			break; /** Зупинка роботи циклу */
		}
		else
			number++; /** Збільшення змінної номеру елементу */
	}

	if (findEl) /** Якщо елемент з потрібним індексом був найден */
	{
		it = StudentList.begin(); /** Встановлення покажчика на початок списку */
		advance(it, number); /** Переміщення покажчика на потрібний елемент */
		StudentList.erase(it); /** Видалення потрібного елементу */

		cout << "Удаление выполнено." << endl;
	}
	else
		throw exception("Элемент не найден.");

	return StudentList.size(); /** Повернення змінної розміру списку */
}

void CList::Sort(Functor& choise) noexcept /** Реалізація метода сортування списку */
{
	std::sort(StudentList.begin(), StudentList.end(), choise); /** Сортування списку */
}

int CList::SaveFile(string filename) const /** Реалізація метода запису даних у файл */
{
	if (StudentList.size() == 0) /** Перевірка розміру масиву */
		throw exception("Список пуст.");

	ofstream fout(filename); /** Відкриття файлу */
	if (!fout.is_open()) /** Перевірка чи відкритий файл */
		throw exception("Невозможно открыть файл.");

	fout << setiosflags(ios::left);
	fout << setw(10) << "Возраст" << setw(8) << "Номер";
	fout << setw(15) << "Средний балл" << setw(7) << "Имя";
	fout << setw(10) << "Долг" << setw(14) << "Долг(прог.)";
	fout << setw(7) << "Курс/Староста" << endl; /** Виведення назв полів */

	int value = 1;
	for (const auto& Student : StudentList) /** Цикл, який обробляє усі елементи масиву */
	{
		fout << setiosflags(ios::left) << setw(2) << value << ". "; /** Виведення нумерування елементів */
		fout << *Student << endl; /** Виведення полів елементів */
		value++;
	}

	fout.close(); /** Закриття файлу */
	return value - 1; /** Повернення кількості елементів, які були збережені у файл */
}

int CList::ReadFile(string filename) /** Реалізація метода читання даних з файлу */
{
	regex expressionStudent("([\\d]* [\\d]* [\\d]* [A-Z]+[\\w,.;:-]* [0|1] [\\d]* )"); /** Регулярний вираз для класу Student */
	regex expressionCourse("([\\d]* [\\d]* [\\d]* [A-Z]+[\\w,.;:-]* [0|1] [\\d]* [\\d]* )"); /** Регулярний вираз для класу Course */
	regex expressionSurnames("([\\d]* [\\d]* [\\d]* [A-Z]+[\\w,.;:-]* [0|1] [\\d]* [A-Z]+[\\w,.;:-]* )"); /** Регулярний вираз для класу Surnames */
	regex replaceSymbols("[;:-]"); /** Регулярний вираз для символів, які треба замінити */

	string temp, data, replacement = "";
	int value = 0;
	ifstream fin(filename); /** Відкриття файлу */
	istringstream ss;

	if (!fin.is_open()) /** Перевірка чи відкритий файл */
	{
		throw exception("Невозможно открыть файл для чтения.");
		return StudentList.size();
	}

	while (!fin.eof()) /** Цикл, який працює до кінця файлу */
	{
		getline(fin, data); /** Отримання строки з файлу */
		temp = regex_replace(data, replaceSymbols, replacement); /** Видалення символів які не підходять */
		temp += " ";

		if (regex_match(temp, expressionStudent)) /** Перевірка на відповідність до класу Student */
		{
			istringstream ss(temp);
			Student* Stud = new Student(); /** Створення змінної класу Student */

			ss >> *Stud;
			StudentList.emplace_back(Stud); /** Вставка елемента у масив */
			value++; /** Збільшення змінної кількості нових елементів */
		}
		else if (regex_match(temp, expressionCourse)) /** Перевірка на відповідність до класу Student */
		{
			istringstream ss(temp);
			Course* Student = new Course(); /** Створення змінної класу Course */

			ss >> *Student;
			StudentList.emplace_back(Student); /** Вставка елемента у масив */
			value++; /** Збільшення змінної кількості нових елементів */
		}
		else if (regex_match(temp, expressionSurnames)) /** Перевірка на відповідність до класу Student */
		{
			istringstream ss(temp);
			Surnames* Student = new Surnames(); /** Створення змінної класу Surnames */

			ss >> *Student;
			StudentList.emplace_back(Student); /** Вставка елемента у масив */
			value++; /** Збільшення змінної кількості нових елементів */
		}
	}

	fin.close(); /** Закриття файлу */
	return value; /** Повернення змінної кількості нових елементів */
}

int CList::get_numb(int value) const /** Реалізація метода отримання номеру елементів */
{
	return StudentList[value]->get_number(); /** Повернення номеру */
}
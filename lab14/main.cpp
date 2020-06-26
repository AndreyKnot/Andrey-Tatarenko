#include "class2.h"
#include "Functor.h"

Student* newProgram(int);
void VectorMenu();
void ListMenu();
void MapMenu();
void SetMenu();

vector <shared_ptr<Student>> CombineVectors(vector<shared_ptr<Student>>&, vector <shared_ptr<Student>>&);
map <int, shared_ptr<Student>> CombineMaps(map<int, shared_ptr<Student>>&, map<int, shared_ptr<Student>>&);

int main()
{
	setlocale(LC_ALL, "ru");

	int choise = 0;
	bool stop = 1;

	while (stop)
	{
		cout << "Выберите STL контейнер:" << endl;
		cout << "1) Vector;" << endl;
		cout << "2) List;" << endl;
		cout << "3) Map;" << endl;
		cout << "4) Set;" << endl;
		cout << "5) Выход;" << endl;
		cout << "=======================" << endl;
		cout << "Пункт: ";
		cin >> choise;

		switch (choise)
		{
		case 1:
			VectorMenu();
			break;

		case 2:
			ListMenu();
			break;

		case 3:
			MapMenu();
			break;

		case 4:
			SetMenu();
			break;

		case 5:
			stop = 0;
			break;

		default:
			cout << "Ошибка. Неверная команда. Повторите попытку." << endl;
		}
	}

	if (_CrtDumpMemoryLeaks())
		cout << endl << "Обнаружена утечка памяти!" << endl;
	else
		cout << endl << "Утечки не обнаруженно!" << endl;

	system("PAUSE");
	return 0;
}

Student* newProgram(int value)
{
	if (value % 2 == 0)
	{
		Student* temp = new Course(17, 4, 10, "Peter", 0, 0, 1);
		return temp;
	}
	else
	{
		Student* temp = new Student(19, 4, 9, "Jhon", 1, 14);
		return temp;
	}
}

vector <shared_ptr<Student>> CombineVectors(vector<shared_ptr<Student>>& first, vector <shared_ptr<Student>>& second)
{
	vector <shared_ptr<Student>> resultVector;

	resultVector.insert(resultVector.end(), make_move_iterator(first.begin()), make_move_iterator(first.end()));
	resultVector.insert(resultVector.end(), make_move_iterator(second.begin()), make_move_iterator(second.end()));

	cout << endl << "Векторы объединены." << endl;
	return resultVector;
}

map <int, shared_ptr<Student>> CombineMaps(map<int, shared_ptr<Student>>& firstMap, map<int, shared_ptr<Student>>& secondMap)
{
	map <int, shared_ptr<Student>> resultMap;
	vector <shared_ptr<Student>> data1;
	vector <shared_ptr<Student>> data2;
	vector <int> map1Keys;
	vector <int> map2Keys;
	vector <int> temp;
	vector <int> res;

	for (auto const& it : firstMap)
		map1Keys.push_back(it.first);
	for (auto const& it : secondMap)
		map2Keys.push_back(it.first);

	for (auto const& it : firstMap)
		data1.push_back(it.second);
	for (auto const& it : secondMap)
		data2.push_back(it.second);

	sort(map1Keys.begin(), map1Keys.end());
	sort(map2Keys.begin(), map2Keys.end());

	set_intersection(map1Keys.begin(), map1Keys.end(), map2Keys.begin(), map2Keys.end(), back_inserter(res));

	temp.insert(temp.end(), map1Keys.begin(), map1Keys.end());
	temp.insert(temp.end(), map2Keys.begin(), map2Keys.end());
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());

	auto it1 = map1Keys.begin();
	auto it2 = map2Keys.begin();
	stringstream ss1, ss2;
	int count1, count2;

	int age1, age2;
	string debtTF1, debtTF2;
	bool debt;
	int prog_d1, prog_d2;
	int middle_mark1, middle_mark2;
	int number_stud1, number_stud2, number_stud3;
	string name1, name2;
	int course1, course2;

	string value1, value2;

	for (size_t i = 0; i < temp.size(); i++)
	{
		if (find(res.begin(), res.end(), i + 1) != res.end())
		{
			auto itnumber_stud1 = find(map1Keys.begin(), map1Keys.end(), i + 1);
			auto itnumber_stud2 = find(map2Keys.begin(), map2Keys.end(), i + 1);

			number_stud1 = distance(map1Keys.begin(), itnumber_stud1);
			number_stud2 = distance(map2Keys.begin(), itnumber_stud2);

			ss1 = data1[number_stud1]->get_str();
			ss2 = data2[number_stud2]->get_str();

			value1 = ss1.str();
			value2 = ss2.str();

			count1 = count(value1.begin(), value1.end(), ' ');
			count2 = count(value2.begin(), value2.end(), ' ');

			ss1 >> age1;
			ss1 >> number_stud1;
			ss1 >> middle_mark1;
			ss1 >> name1;
			ss1 >> debtTF1;
			ss1 >> prog_d1;
			if (count1 == 6)
				ss1 >> course1;

			ss2 >> age2;
			ss2 >> number_stud2;
			ss2 >> middle_mark2;
			ss2 >> name2;
			ss2 >> debtTF2;
			ss2 >> prog_d2;
			if (count2 == 6)
				ss2 >> course2;

			name1 += name2;
			number_stud1 += number_stud2;
			age1 += age2;
			prog_d1 += prog_d2;
			middle_mark1 += middle_mark2;
			if (debtTF1 == "1" || debtTF2 == "1")
				debt = true;
			if (count1 == 6 || count2 == 6)
			{
				course1 += course2;
				resultMap.emplace(i + 1, new Course(age1, number_stud1, middle_mark1,  name1, debt, prog_d1, course1));
			}
			else
				resultMap.emplace(i + 1, new Student(age1, number_stud1, middle_mark1, name1, debt, prog_d1));

		}
		else
		{
			it1 = find(map1Keys.begin(), map1Keys.end(), i + 1);
			if (it1 != map1Keys.end())
			{
				number_stud3 = distance(map1Keys.begin(), it1);
				resultMap.emplace(i + 1, data1[number_stud3]);
			}
			else
			{
				it2 = find(map2Keys.begin(), map2Keys.end(), i + 1);
				number_stud3 = distance(map2Keys.begin(), it2);
				resultMap.emplace(i + 1, data2[number_stud3]);
			}
		}
	}

	map1Keys.erase(map1Keys.begin(), map1Keys.end());
	map2Keys.erase(map2Keys.begin(), map2Keys.end());
	temp.erase(temp.begin(), temp.end());
	res.erase(res.begin(), res.end());
	data1.erase(data1.begin(), data1.end());
	data2.erase(data2.begin(), data2.end());

	return resultMap;
}

void VectorMenu()
{
	vector <shared_ptr<Student>> vector;
	std::vector <shared_ptr<Student>> mergeVector;
	std::vector<shared_ptr<Student>>::iterator it;
	stringstream temp;
	string data;
	bool stop = 1, findEl = 0;
	int choise = 0, choise2 = 0, choise3 = 0;
	int value = 0, number = 0, result = 0, sum = 0;

	for (size_t i = 0; i < 4; i++)
	{
		if (i == 0)
			vector.emplace_back(new Student());
		else if (i == 1)
			vector.emplace_back(new Course(20, 1, 10, "Den", 0, 0, 3));
		else if (i == 2)
			vector.emplace_back(new Student(18, 2, 8, "Dima", 0, 0));
		else if (i == 3)
			vector.emplace_back(new Course(19, 3, 7, "Gordon", 1, 25, 2));
	}

	while (stop != 0)
	{
		if (vector.size() == 0)
		{
			cout << "Вектор пуст. Что вы хотите сделать?" << endl;
			cout << "1) Добавить элемент" << endl;
			cout << "2) Завершение работы" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;

			switch (choise)
			{
			case 1:
				cout << "Выберите программу, которую хотите добавить:" << endl;
				cout << "1. Элемент класса Student" << endl;
				cout << "2. Элемент класса Course" << endl;
				cout << "============================================" << endl;
				cout << "Ваш выбор: ";
				cin >> value;

				try
				{
					vector.at(value);

					if (value == 1 || value == 2)
					{
						vector.emplace_back(newProgram(value));
						cout << "Элемент добавлен." << endl;
					}
					else
						cout << "Ошибка. Неверный номер." << endl;
				}
				catch (const std::exception& ex)
				{
					cout << ex.what() << endl;
				}

				break;

			case 2:
				cout << "Завершение работы." << endl;
				stop = 0;
				break;

			default:
				cout << "Неверный номер элемента. Повторите попытку." << endl;
				break;
			}
		}
		else
		{
			cout << endl;
			cout << "1)Вывод на экран" << endl;
			cout << "2)Удаление" << endl;
			cout << "3)Добавление" << endl;
			cout << "4)Объединить векторы" << endl;
			cout << "5)Сортировка" << endl;
			cout << "6)Завершение работы" << endl;
			cout << "======================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			cout << "Выберите команду:" << endl;
			cout << "1) Вывести весь список на экран" << endl;
			cout << "2) Вывести программу по ID" << endl;
			cout << "3) Вывести количество элементов по критерию" << endl;
			cout << "4) Найти элемент по критерию" << endl;
			cout << "5) Вернуться к выбору действий" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				cout << setw(10) << "Возраст" << setw(8) << "Номер";
				cout << setw(15) << "Средний балл" << setw(7) << "Имя";
				cout << setw(10) << "Долг" << setw(14) << "Долг(прог.)";
				cout << setw(7) << "Курс" << endl;

				number = 1;
				for_each(vector.begin(), vector.end(), [&number](const shared_ptr<Student>& program)
				{
					cout << number << ". " << *program << endl;
					number++;
				});
				number = 1;
				break;

			case 2:
				cout << "Введите id элемента, которого вы хотите получить: ";
				cin >> value;
				cout << endl;

				findEl = 0, number = -1;
				for (const auto& element : vector)
				{
					if (element->get_numb() == value)
					{
						number++;
						findEl = 1;
						break;
					}
					else
						number++;
				}

				if (findEl)
				{
					temp = vector[number]->get_str();
					data = temp.str();
					cout << "Ваш элемент: " << endl;
					cout << data << endl << endl;
				}
				else
					cout << "Элемент с таким ID не найден." << endl;

				break;
			case 3:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Имя" << endl;
				cout << "2) Возраст" << endl;
				cout << "3) Средний балл" << endl;
				cout << "4) Долг по прог." << endl;
				cout << "5) Номер" << endl;
				cout << "6) Есть ли долг" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = vector.begin();

				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < vector.size())
				{
					result = (*it)->countElement(choise3, data);
					number++;
					it++;
					sum += result;
				}
				if (sum != 0)
					cout << "Количество элементов с данным параметром: " << sum << endl;

				break;

			case 4:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Имя" << endl;
				cout << "2) Возраст" << endl;
				cout << "3) Средний балл" << endl;
				cout << "4) Долг по прог." << endl;
				cout << "5) Номер" << endl;
				cout << "6) Есть ли долг" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = vector.begin();
				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < vector.size())
				{
					result = (*it)->elementOutput(choise3, data);
					number++;
					it++;
				}

				break;
			case 5:
				cout << "Возвращение назад." << endl;
				break;

			default:
				cout << "Неверный символ. Повторите попытку." << endl;
				break;

			}
			break;

		case 2:
			cout << "Введите ID элемента, который хотите удалить: ";
			cin >> value;
			cout << endl;

			findEl = 0, number = -1;
			for (const auto& element : vector)
			{
				if (element->get_numb() == value)
				{
					number++;
					findEl = 1;
					break;
				}
				else
					number++;
			}

			if (findEl)
			{
				it = vector.begin();
				advance(it, number);
				vector.erase(it);

				cout << "Удаление выполнено." << endl;
			}
			else
				cout << "Элемент не найден." << endl;

			break;

		case 3:
			cout << "Выберите программу, которую хотите добавить:" << endl;
			cout << "1. Элемент класса Student" << endl;
			cout << "2. Элемент класса Course" << endl;
			cout << "============================================" << endl;
			cout << "Ваш выбор: ";
			cin >> value;

			try
			{
				vector.at(value);

				if (value == 1 || value == 2)
				{
					vector.emplace_back(newProgram(value));
					cout << "Элемент добавлен." << endl;
				}
				else
					cout << "Ошибка. Неверный номер." << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}

			break;
		case 4:

			for (size_t j = 0; j < 4; j++)
			{
				if (j == 0)
					mergeVector.emplace_back(new Student(20, 1, 10, "Dani", 0, 0));
				else if (j == 1)
					mergeVector.emplace_back(new Student(19, 2, 5, "Devid", 1, 50));
				else if (j == 2)
					mergeVector.emplace_back(new Course(18, 3, 8, "Chack", 1, 10, 2));
				else if (j == 3)
					mergeVector.emplace_back(new Course(18, 4, 9, "Clark", 0, 0, 2));
			}

			cout << "Контейнер, с которым будет объединение:" << endl << endl;
			cout << setw(10) << "Возраст" << setw(8) << "Номер";
			cout << setw(15) << "Средний балл" << setw(7) << "Имя";
			cout << setw(10) << "Долг" << setw(14) << "Долг(прог.)";
			cout << setw(7) << "Курс" << endl;

			number = 1;
			for_each(mergeVector.begin(), mergeVector.end(), [&number](const shared_ptr<Student>& program)
			{
				cout << number << ". " << *program << endl;
				number++;
			});
			number = 1;

			vector = CombineVectors(vector, mergeVector);
			mergeVector.erase(mergeVector.begin(), mergeVector.end());

			break;

		case 5:
			cout << "Сортировать по: " << endl;
			cout << "1) Возрастанию" << endl;
			cout << "2) Убыванию" << endl;
			cout << "3) Вернуться назад" << endl;
			cout << "==================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			if (choise2 == 1 || choise2 == 2)
			{
				Functor funct(choise2);

				sort(vector.begin(), vector.end(), funct);

				cout << "Вектор отсортирован." << endl;
			}
			else if (choise2 == 3)
				cout << "Возвращение назад." << endl;
			else
				cout << "Ошибка. Неверная команда." << endl;

			break;

		case 6:
			cout << "Завершение работы." << endl << endl;
			stop = 0;
			break;

		default:
			cout << "Неверный символ. Повторите попытку." << endl;
			break;

		}
	}
}

void ListMenu()
{
	list <shared_ptr<Student>> list;
	stringstream temp;
	string data;
	bool stop = 1, findEl = 0;
	int choise = 0, choise2 = 0, choise3 = 0;
	int value = 0;
	int number = 0;
	int result = 0, sum = 0;
	auto it = list.begin();

	for (size_t i = 0; i < 4; i++)
	{
		if (i == 0)
			list.emplace_back(new Student());
		else if (i == 1)
			list.emplace_back(new Course(20, 1, 10, "Den", 0, 0, 3));
		else if (i == 2)
			list.emplace_back(new Student(18, 2, 8, "Dima", 0, 0));
		else if (i == 3)
			list.emplace_back(new Course(19, 3, 7, "Gordon", 1, 25, 2));
	}

	while (stop != 0)
	{
		if (list.size() == 0)
		{
			cout << "Вектор пуст. Что вы хотите сделать?" << endl;
			cout << "1) Добавить элемент" << endl;
			cout << "2) Завершение работы" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;

			switch (choise)
			{
			case 1:
				cout << "Выберите программу, которую хотите добавить:" << endl;
				cout << "1. Элемент класса Student" << endl;
				cout << "2. Элемент класса Course" << endl;
				cout << "============================================" << endl;
				cout << "Ваш выбор: ";
				cin >> value;

				try
				{
					if (value == 1 || value == 2)
					{
						list.emplace_front(newProgram(value));
						cout << "Элемент добавлен." << endl;
					}
					else
						cout << "Ошибка. Неверный номер." << endl;
				}
				catch (const std::exception & ex)
				{
					cout << ex.what() << endl;
				}

				break;

			case 2:
				cout << "Завершение работы." << endl;
				stop = 0;
				break;

			default:
				cout << "Неверный номер элемента. Повторите попытку." << endl;
				break;
			}
		}
		else
		{
			cout << endl;
			cout << "1)Вывод на экран" << endl;
			cout << "2)Удаление элемента" << endl;
			cout << "3)Добавление элементов" << endl;
			cout << "4)Сортировка элементов" << endl;
			cout << "5)Завершение работы" << endl;
			cout << "======================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			cout << "Выберите команду:" << endl;
			cout << "1) Вывести весь список на экран" << endl;
			cout << "2) Вывести программу по ID" << endl;
			cout << "3) Вывести количество элементов по критерию" << endl;
			cout << "4) Найти элемент по критерию" << endl;
			cout << "5) Вернуться к выбору действий" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				cout << setw(10) << "Возраст" << setw(8) << "Номер";
				cout << setw(15) << "Средний балл" << setw(7) << "Имя";
				cout << setw(10) << "Долг" << setw(14) << "Долг(прог.)";
				cout << setw(7) << "Курс" << endl;

				number = 1;
				for_each(list.begin(), list.end(), [&number](const shared_ptr<Student>& program)
				{
					cout << number << ". " << *program << endl;
					number++;
				});
				number = 1;
				break;

			case 2:
				cout << "Введите id элемента, которого вы хотите получить: ";
				cin >> value;
				cout << endl;

				findEl = 0, number = -1;
				for (const auto& element : list)
				{
					if (element->get_numb() == value)
					{
						number++;
						findEl = 1;
						break;
					}
					else
						number++;
				}

				if (findEl)
				{
					it = list.begin();
					advance(it, number);

					temp = (*it)->get_str();
					data = temp.str();

					cout << "Ваш элемент: " << endl;
					cout << data << endl << endl;
				}
				else
					cout << "Элемент с таким ID не найден." << endl;

				break;

			case 3:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Имя" << endl;
				cout << "2) Возраст" << endl;
				cout << "3) Средний балл" << endl;
				cout << "4) Долг по прог." << endl;
				cout << "5) Номер" << endl;
				cout << "6) Есть ли долг" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = list.begin();
				result = 0, sum = 0;
				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < list.size())
				{
					result = (*it)->countElement(choise3, data);
					number++;
					it++;
					sum += result;
				}
				if (sum != 0)
					cout << "Количество элементов с данным параметром: " << sum << endl;

				break;

			case 4:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Имя" << endl;
				cout << "2) Возраст" << endl;
				cout << "3) Средний балл" << endl;
				cout << "4) Долг по прог." << endl;
				cout << "5) Номер" << endl;
				cout << "6) Есть ли долг" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = list.begin();
				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < list.size())
				{
					result = (*it)->elementOutput(choise3, data);
					number++;
					it++;
				}

				break;
			case 5:
				cout << "Возвращение назад." << endl;
				break;

			default:
				cout << "Неверный символ. Повторите попытку." << endl;
				break;

			}
			break;

		case 2:
			cout << "Введите ID элемента, который хотите удалить: ";
			cin >> value;
			cout << endl;

			findEl = 0, number = -1;
			for (const auto& element : list)
			{
				if (element->get_numb() == value)
				{
					number++;
					findEl = 1;
					break;
				}
				else
					number++;
			}

			if (findEl)
			{
				it = list.begin();
				advance(it, number);
				list.erase(it);

				cout << "Удаление выполнено." << endl;
			}
			else
				cout << "Элемент не найден." << endl;

			break;

		case 3:
			cout << "Выберите программу, которую хотите добавить:" << endl;
			cout << "1. Элемент класса Student" << endl;
			cout << "2. Элемент класса Course" << endl;
			cout << "============================================" << endl;
			cout << "Ваш выбор: ";
			cin >> value;

			try
			{
				if (value == 1 || value == 2)
				{
					list.emplace_front(newProgram(value));
					cout << "Элемент добавлен." << endl;
				}
				else
					cout << "Ошибка. Неверный номер." << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}

			break;
		case 4:
			cout << "Сортировать по: " << endl;
			cout << "1) Возрастанию" << endl;
			cout << "2) Убыванию" << endl;
			cout << "3) Вернуться назад" << endl;
			cout << "==================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			if (choise2 == 1 || choise2 == 2)
			{
				Functor funct(choise2);

				list.sort(funct);

				cout << "Список отсортирован." << endl;
			}
			else if (choise2 == 3)
				cout << "Возвращение назад." << endl;
			else
				cout << "Ошибка. Неверная команда." << endl;

			break;

		case 5:
			cout << "Завершение работы." << endl << endl;
			stop = 0;
			break;

		default:
			cout << "Неверный символ. Повторите попытку." << endl;
			break;

		}
	}
}

void MapMenu()
{
	map <int, shared_ptr<Student>> map;
	stringstream temp;
	string data;
	bool stop = 1, findEl = 0;
	int choise = 0, choise2 = 0, choise3 = 0;
	int value = 0;
	int i = 0;
	int number = 0, sum = 0, result = 0;
	auto it = map.begin();

	for (; i < 4; i++)
	{
		if (i == 0)
			map.emplace(i + 1, new Student());
		else if (i == 1)
			map.emplace(i + 1, new Course(20, 1, 10, "Den", 0, 0, 3));
		else if (i == 2)
			map.emplace(i + 1, new Student(18, 2, 8, "Dima", 0, 0));
		else if (i == 3)
			map.emplace(i + 1, new Course(19, 3, 7, "Gordon", 1, 25, 2));
	}

	while (stop != 0)
	{
		if (map.size() == 0)
		{
			cout << "Вектор пуст. Что вы хотите сделать?" << endl;
			cout << "1) Добавить элемент" << endl;
			cout << "2) Завершение работы" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;

			switch (choise)
			{
			case 1:
				cout << "Выберите программу, которую хотите добавить:" << endl;
				cout << "1. Элемент класса Student" << endl;
				cout << "2. Элемент класса Course" << endl;
				cout << "============================================" << endl;
				cout << "Ваш выбор: ";
				cin >> value;

				try
				{
					if (value == 1 || value == 2)
					{
						map.emplace(++i, newProgram(value));
						cout << "Элемент добавлен." << endl;
					}
					else
						cout << "Ошибка. Неверный номер." << endl;
				}
				catch (const std::exception & ex)
				{
					cout << ex.what() << endl;
				}

				break;

			case 2:
				cout << "Завершение работы." << endl;
				stop = 0;
				break;

			default:
				cout << "Неверный номер элемента. Повторите попытку." << endl;
				break;
			}
		}
		else
		{
			cout << endl;
			cout << "1)Вывод на экран" << endl;
			cout << "2)Удаление элемента" << endl;
			cout << "3)Добавление элементов" << endl;
			cout << "4)Сортировать контейнеры" << endl;
			cout << "5)Объеденить контейнеры" << endl;
			cout << "6)Завершение работы" << endl;
			cout << "======================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			cout << "Выберите команду:" << endl;
			cout << "1) Вывести весь список на экран" << endl;
			cout << "2) Вывести программу по ID" << endl;
			cout << "3) Вывести количество элементов по критерию" << endl;
			cout << "4) Найти элемент по критерию" << endl;
			cout << "5) Вернуться к выбору действий" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				cout << setw(10) << "Возраст" << setw(8) << "Номер";
				cout << setw(15) << "Средний балл" << setw(7) << "Имя";
				cout << setw(10) << "Долг" << setw(14) << "Долг(прог.)";
				cout << setw(7) << "Курс" << endl;

				for_each(map.begin(), map.end(), [](const std::pair<const int, shared_ptr<Student>>& program)
				{
					cout << program.first << ". " << *program.second << endl;
				});

				break;

			case 2:
				cout << "Введите номер элемента, которого вы хотите получить: ";
				cin >> value;
				cout << endl;

				findEl = 0;
				it = map.find(value);

				if (it != map.end())
				{
					temp = (*it).second->get_str();
					data = temp.str();

					cout << "Ваш элемент: " << endl;
					cout << data << endl << endl;
				}
				else
					cout << "Элемент с таким ID не найден." << endl;

				break;

			case 3:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Имя" << endl;
				cout << "2) Возраст" << endl;
				cout << "3) Средний балл" << endl;
				cout << "4) Долг по прог." << endl;
				cout << "5) Номер" << endl;
				cout << "6) Есть ли долг" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = map.begin();
				result = 0, sum = 0;
				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < map.size())
				{
					result = it->second->countElement(choise3, data);
					number++;
					it++;
					sum += result;
				}
				if (sum != 0)
					cout << "Количество элементов с данным параметром: " << sum << endl;

				break;

			case 4:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Имя" << endl;
				cout << "2) Возраст" << endl;
				cout << "3) Средний балл" << endl;
				cout << "4) Долг по прог." << endl;
				cout << "5) Номер" << endl;
				cout << "6) Есть ли долг" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = map.begin();
				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < map.size())
				{
					result = it->second->elementOutput(choise3, data);
					number++;
					it++;
				}

				break;
			case 5:
				cout << "Возвращение назад." << endl;
				break;

			default:
				cout << "Неверный символ. Повторите попытку." << endl;
				break;

			}
			break;

		case 2:
			cout << "Введите номер элемента, который хотите удалить: ";
			cin >> value;
			cout << endl;

			findEl = 0;
			it = map.find(value);

			if (it != map.end())
			{
				map.erase(it);
				cout << "Удаление выполнено." << endl;
			}
			else
				cout << "Элемент не найден." << endl;

			break;

		case 3:
			cout << "Выберите программу, которую хотите добавить:" << endl;
			cout << "1. Элемент класса Student" << endl;
			cout << "2. Элемент класса Course" << endl;
			cout << "============================================" << endl;
			cout << "Ваш выбор: ";
			cin >> value;

			try
			{
				if (value == 1 || value == 2)
				{
					map.emplace(++i, newProgram(value));
					cout << "Элемент добавлен." << endl;
				}
				else
					cout << "Ошибка. Неверный номер." << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}

			break;
		case 4:
			cout << "Сортировать по: " << endl;
			cout << "1) Возрастанию" << endl;
			cout << "2) Убыванию" << endl;
			cout << "3) Вернуться назад" << endl;
			cout << "==================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			if (choise2 == 1 || choise2 == 2)
			{
				value = 1;
				Functor funct(choise2);
				vector <shared_ptr<Student>> temp;

				for (auto const& it : map)
					temp.push_back(it.second);

				sort(temp.begin(), temp.end(), funct);

				map.erase(map.begin(), map.end());

				transform(temp.begin(), temp.end(), inserter(map, map.end()), [&value](const shared_ptr<Student>& a)
				{
					return make_pair(value++, a);
				});

			}
			else if (choise2 == 3)
				cout << "Возвращение." << endl;
			else
				cout << "Ошибка. Неверный номер элемента." << endl;

			break;

		case 5:
		{
			std::map <int, shared_ptr<Student>> mergeMap;
			std::map <int, shared_ptr<Student>> result;
			for (size_t j = 0; j < 4; j++)
			{
				if (j == 0)
					mergeMap.emplace(j + 1, new Student(20, 1, 10, "Dani", 0, 0));
				else if (j == 1)
					mergeMap.emplace(j + 1, new Student(19, 2, 5, "Devid", 1, 50));
				else if (j == 2)
					mergeMap.emplace(j + 1, new Course(18, 3, 8, "Chack", 1, 10, 2));
				else if (j == 3)
					mergeMap.emplace(j + 1, new Course(18, 4, 9, "Clark", 0, 0, 2));
			}

			cout << "Контейнер, с которым будет объединение:" << endl << endl;
			cout << setw(10) << "Возраст" << setw(8) << "Номер";
			cout << setw(15) << "Средний балл" << setw(7) << "Имя";
			cout << setw(10) << "Долг" << setw(14) << "Долг(прог.)";
			cout << setw(7) << "Курс" << endl;
			for_each(mergeMap.begin(), mergeMap.end(), [](const pair<const int, shared_ptr<Student>>& program)
			{
				cout << program.first << ". " << *program.second << endl;
			});

			map = CombineMaps(map, mergeMap);

			cout << "Объединение выполнено." << endl;

			break;
		}
		case 6:
			cout << "Завершение работы." << endl << endl;
			stop = 0;
			break;

		default:
			cout << "Неверный символ. Повторите попытку." << endl;
			break;

		}
	}
}

void SetMenu()
{
	set <shared_ptr<Student>> set;
	stringstream ss;
	string data;
	bool stop = 1, findEl = 0;
	int choise = 0, choise2 = 0, choise3 = 0;
	int value = 0, number = 0, result = 0, sum = 0;
	auto it = set.begin();

	for (size_t i = 0; i < 4; i++)
	{
		if (i == 0)
			set.emplace(new Student());
		else if (i == 1)
			set.emplace(new Course(20, 1, 10, "Den", 0, 0, 3));
		else if (i == 2)
			set.emplace(new Student(18, 2, 8, "Dima", 0, 0));
		else if (i == 3)
			set.emplace(new Course(19, 3, 7, "Gordon", 1, 25, 2));
	}

	while (stop != 0)
	{
		if (set.size() == 0)
		{
			cout << "Вектор пуст. Что вы хотите сделать?" << endl;
			cout << "1) Добавить элемент" << endl;
			cout << "2) Завершение работы" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;

			switch (choise)
			{
			case 1:
				cout << "Выберите программу, которую хотите добавить:" << endl;
				cout << "1. Элемент класса Student" << endl;
				cout << "2. Элемент класса Course" << endl;
				cout << "============================================" << endl;
				cout << "Ваш выбор: ";
				cin >> value;

				try
				{
					if (value == 1 || value == 2)
					{
						set.emplace(newProgram(value));
						cout << "Элемент добавлен." << endl;
					}
					else
						cout << "Ошибка. Неверный номер." << endl;
				}
				catch (const std::exception & ex)
				{
					cout << ex.what() << endl;
				}

				break;

			case 2:
				cout << "Завершение работы." << endl;
				stop = 0;
				break;

			default:
				cout << "Неверный номер элемента. Повторите попытку." << endl;
				break;
			}
		}
		else
		{
			cout << endl;
			cout << "1)Вывод на экран" << endl;
			cout << "2)Удаление элемента" << endl;
			cout << "3)Добавление элементов" << endl;
			cout << "4)Сортировка элементов" << endl;
			cout << "5)Завершение работы" << endl;
			cout << "======================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise;
			cout << endl;
		}

		switch (choise)
		{
		case 1:
			cout << "Выберите команду:" << endl;
			cout << "1) Вывести весь список на экран" << endl;
			cout << "2) Вывести программу по ID" << endl;
			cout << "3) Вывести количество элементов по критерию" << endl;
			cout << "4) Найти элемент по критерию" << endl;
			cout << "5) Вернуться к выбору действий" << endl;
			cout << "======================================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			switch (choise2)
			{
			case 1:
				cout << setw(10) << "Возраст" << setw(8) << "Номер";
				cout << setw(15) << "Средний балл" << setw(7) << "Имя";
				cout << setw(10) << "Долг" << setw(14) << "Долг(прог.)";
				cout << setw(7) << "Курс" << endl;

				number = 1;
				for_each(set.begin(), set.end(), [&number](const shared_ptr<Student>& program)
				{
					cout << number << ". " << *program << endl;
					number++;
				});
				number = 1;
				break;

			case 2:
				cout << "Введите id элемента, которого вы хотите получить: ";
				cin >> value;
				cout << endl;

				findEl = 0, number = -1;
				for (const auto& element : set)
				{
					if (element->get_numb() == value)
					{
						number++;
						findEl = 1;
						break;
					}
					else
						number++;
				}

				if (findEl)
				{
					it = set.begin();
					advance(it, number);

					ss = (*it)->get_str();
					data = ss.str();

					cout << "Ваш элемент: " << endl;
					cout << data << endl << endl;
				}
				else
					cout << "Элемент с таким ID не найден." << endl;

				break;

			case 3:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Имя" << endl;
				cout << "2) Возраст" << endl;
				cout << "3) Средний балл" << endl;
				cout << "4) Долг по прог." << endl;
				cout << "5) Номер" << endl;
				cout << "6) Есть ли долг" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = set.begin();
				result = 0, sum = 0;
				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < set.size())
				{
					result = (*it)->countElement(choise3, data);
					number++;
					it++;
					sum += result;
				}
				if (sum != 0)
					cout << "Количество элементов с данным параметром: " << sum << endl;

				break;

			case 4:
				cout << "Выберите критерий, по которому надо искать: " << endl;
				cout << "1) Имя" << endl;
				cout << "2) Возраст" << endl;
				cout << "3) Средний балл" << endl;
				cout << "4) Долг по прог." << endl;
				cout << "5) Номер" << endl;
				cout << "6) Есть ли долг" << endl;
				cout << "7) Вернуться назад" << endl;
				cout << "======================================" << endl;
				cout << "Ваш выбор: ";
				cin >> choise3;
				cout << endl;

				if (choise3 < 1 || choise3 >= 7)
				{
					cout << "Возвращение назад." << endl;
					break;
				}

				it = set.begin();
				cout << "Введите критерий: ";
				cin.ignore();
				getline(cin, data);
				number = 0, value = 0;

				while (number < set.size())
				{
					result = (*it)->elementOutput(choise3, data);
					number++;
					it++;
				}

				break;
			case 5:
				cout << "Возвращение назад." << endl;
				break;

			default:
				cout << "Неверный символ. Повторите попытку." << endl;
				break;

			}
			break;

		case 2:
			cout << "Введите ID элемента, который хотите удалить: ";
			cin >> value;
			cout << endl;

			findEl = 0, number = -1;
			for (const auto& element : set)
			{
				if (element->get_numb() == value)
				{
					number++;
					findEl = 1;
					break;
				}
				else
					number++;
			}

			if (findEl)
			{
				it = set.begin();
				advance(it, number);
				set.erase(it);

				cout << "Удаление выполнено." << endl;
			}
			else
				cout << "Элемент не найден." << endl;

			break;

		case 3:
			cout << "Выберите программу, которую хотите добавить:" << endl;
			cout << "1. Элемент класса Student" << endl;
			cout << "2. Элемент класса Course" << endl;
			cout << "============================================" << endl;
			cout << "Ваш выбор: ";
			cin >> value;

			try
			{
				if (value == 1 || value == 2)
				{
					set.emplace(newProgram(value));
					cout << "Элемент добавлен." << endl;
				}
				else
					cout << "Ошибка. Неверный номер." << endl;
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}

			break;
		case 4:
			cout << "Сортировать по: " << endl;
			cout << "1) Возрастанию" << endl;
			cout << "2) Убыванию" << endl;
			cout << "3) Вернуться назад" << endl;
			cout << "==================" << endl;
			cout << "Ваш выбор: ";
			cin >> choise2;
			cout << endl;

			if (choise2 == 1 || choise2 == 2)
			{
				vector <shared_ptr<Student>> temp(set.begin(), set.end());
				set.erase(set.begin(), set.end());

				Functor funct(choise2);
				sort(temp.begin(), temp.end(), funct);

				set.insert(temp.begin(), temp.end());

				cout << "Отсортированный set" << endl;
				cout << setw(10) << "Возраст" << setw(8) << "Номер";
				cout << setw(15) << "Средний балл" << setw(7) << "Имя";
				cout << setw(10) << "Долг" << setw(14) << "Долг(прог.)";
				cout << setw(7) << "Курс" << endl;

				number = 1;
				for_each(temp.begin(), temp.end(), [&number](const shared_ptr<Student>& program)
				{
					cout << number << ". " << *program << endl;
					number++;
				});
				number = 1;
				temp.erase(temp.begin(), temp.end());
			}
			else if (choise2 == 3)
				cout << "Возвращение." << endl;
			else
				cout << "Ошибка. Неверный номер элемента." << endl;

			break;


		case 5:
			cout << "Завершение работы." << endl << endl;
			stop = 0;
			break;

		default:
			cout << "Неверный символ. Повторите попытку." << endl;
			break;

		}
	}
}
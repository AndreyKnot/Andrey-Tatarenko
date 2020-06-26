#include "test.h"

int main()
{
	Arr stud_array;

	if (test_count_plus(stud_array))
		cout << "Функция count_plus верна!" << endl;
	else
		cout << "Функция count_plus неверна!" << endl;

	if (test_count_minus(stud_array))
		cout << "Функция count_minus верна!" << endl;
	else
		cout << "Функция count_minus неверна!" << endl;

	system("PAUSE");
}

bool test_count_plus(Arr p)
{
	int exp = El + 1;
	int cnt = p.count_plus();

	if (cnt == exp)
		return 1;
	else
		return 0;
}

bool test_count_minus(Arr p)
{
	int exp = El - 1;
	int cnt = p.count_minus();

	if (cnt == exp)
		return 1;
	else
		return 0;
}
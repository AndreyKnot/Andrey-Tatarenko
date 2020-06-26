#include "test.h"

int main()
{
	Arr stud_array;

	if (test_count_plus(stud_array))
		cout << "Function count_plus is right!" << endl;
	else
		cout << "Function count_plus is not right!" << endl;

	if (test_count_minus(stud_array))
		cout << "Function count_minus is right!" << endl;
	else
		cout << "Function count_minus is not right!" << endl;

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
#include "test.h"

int main()
{
	Arr stud_array;

	if (test_count_plus(stud_array))
		cout << "������� count_plus �����!" << endl;
	else
		cout << "������� count_plus �������!" << endl;

	if (test_count_minus(stud_array))
		cout << "������� count_minus �����!" << endl;
	else
		cout << "������� count_minus �������!" << endl;

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
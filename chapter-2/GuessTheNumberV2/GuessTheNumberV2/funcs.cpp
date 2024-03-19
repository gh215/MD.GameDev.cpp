#include "gtn.h"

void greeting()
{
	cout << "����� ���������� � ���� ����! �� ����������� ����� � ��� �� "
		<< border_min << " �� " << border_max
		<< ", � ��������� ��� ����������" << endl << "�� ������ ������ " 
		<< SMALL << ", " << BIG << " ��� " << CORRECT
		<< " ����� ������� �����, ����������� �����������: \n"
		<< SMALL << ": ����� ������� ��������� \n" << BIG 
		<< ": ����� ������� ������� \n" << CORRECT << ": ����� ���� �������" << endl;
}

int num_gen(int min, int max)
{
	int cn = rand() % (max - min + 1) + min;
	return cn;
}

int ask_user(int cn, int min, int max, istream& input, ostream& output)
{
	output << "\n��������� ������� ����� �����: "
		<< cn
		<< ". ��� ������, ������ ��� ����� ����������� �����?"
		<< endl;

	while (true)
	{

		output << "��� �����: ";
		int uc;
		input >> uc;

		if (uc != SMALL && uc != BIG && uc != CORRECT)
		{
			output << "������� " << SMALL << ", "
				<< BIG << " ��� " << CORRECT << endl;
			continue;
		}

		if (cn == border_max && uc == SMALL)
		{
			output << "����� �� ����� ���� ������ " << border_max << endl;
			continue;
		}
		if (cn == border_min && uc == BIG)
		{
			output << "����� �� ����� ���� ������ " << border_min << endl;
			continue;
		}
		if (cn == max && uc == SMALL)
		{
			output << "����� �� ����� ���� ������ " << max << endl;
			continue;
		}
		if (cn == min && uc == BIG)
		{
			output << "����� �� ����� ���� ������ " << min << endl;
			continue;
		}

		return uc;
	}

}

void tell_guessed(int cn)
{
		cout << "\n��������� ������ ���� ����� � ��� ����� " << cn << endl;
}

void bord_reduct(int cn, int uc, int& min, int& max)
{
	if (uc == BIG)
	{
		max = cn - 1;
		return;
	}
	min = cn + 1;
}
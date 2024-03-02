#include "gtn.h"

void greeting()
{
	cout << "Добро пожаловать в нашу игру! Вы загадываете число в уме от "
		<< border_min << " до " << border_max
		<< ", а компьютер его отгадывает" << endl << "Вы будете писать " 
		<< SMALL << ", " << BIG << " или " << CORRECT
		<< " после каждого числа, выведенного компьютером: \n"
		<< SMALL << ": Число слишком маленькое \n" << BIG 
		<< ": Число слишком большое \n" << CORRECT << ": Число было угадано" << endl;
}

int num_gen(int min, int max)
{
	int cn = rand() % (max - min + 1) + min;
	return cn;
}

int ask_user(int cn, int min, int max)
{
	cout << "\nКомпьютер загадал такое число: "
		<< cn
		<< ". Оно больше, меньше или равно загаданному числу?"
		<< endl;

	while (true)
	{

		cout << "Ваш ответ: ";
		int uc;
		cin >> uc;

		if (uc != SMALL && uc != BIG && uc != CORRECT)
		{
			cout << "Введите " << SMALL << ", "
				<< BIG << " или " << CORRECT << endl;
			continue;
		}

		if (cn == border_max && uc == SMALL)
		{
			cout << "Число не может быть больше " << border_max << endl;
			continue;
		}
		if (cn == border_min && uc == BIG)
		{
			cout << "Число не может быть меньше " << border_min << endl;
			continue;
		}
		if (cn == max && uc == SMALL)
		{
			cout << "Число не может быть больше " << max << endl;
			continue;
		}
		if (cn == min && uc == BIG)
		{
			cout << "Число не может быть меньше " << min << endl;
			continue;
		}

		return uc;
	}

}

void tell_guessed(int cn)
{
		cout << "\nКомпьютер угадал ваше число и оно равно " << cn << endl;
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
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


/* Тест-кейсы для нормального пользователя

1. П задумал число на нижней границе:
   - К должен продолжать предлагать числа, пока не угадает нижнюю границу.

2. П задумал число на верхней границе:
   - К должен продолжать предлагать числа, пока не угадает верхнюю границу.

3. П задумал число на середине:
   - Сужает диапазон. Число меньше - ставит меньшую границу диапазона
   - Число больше - ставит большую границу диапазона
   - К должен продолжать предлагать числа, пока не угадает.

4. За разумное количество попыток (например, 8) компьютер должен угадать число.

	Тест-кейсы для ненормального пользователя

1. За диапазоном:
   - Если П задумал число вне диапазона 1-50, К должен выдать ошибку.

2. Недопустимый ответ:
   - Если П вводит что-то кроме 1, 2 или 3, К должен выдать сообщение о неверном вводе и запросить ввод снова.

3. Пользователь меняет загаданное число за пределы установленного К диапазона во время игры:
   - П задумывает число в пределах диапазона и отвечает корректно 1 или 2
   - К сужает диапазон согласно ответам П
   - Когда число почти угадано, но затем П меняет загаданное число на число за пределами установленного К диапазона
   - К обнаруживает противоречие и обвиняет П в том, что он изменил загаданное число за пределы установленного min max диапазона
*/

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(static_cast<unsigned int>(time(0)));

	enum { SMALL = 1, BIG, CORRECT };

	int user_conceive, computerNumber;
	int tries = 0;
	int min = 1, max = 50;
	int const border_min = 1, border_max = 50;
	int const MAX_TRIES = 8;

	bool changing_numbers = false;

	string small_number = "число слишком маленькое";
	string big_number = "число слишком большое";


	cout << "Добро пожаловать в нашу игру! Вы загадываете число в уме от " << min << " до " << max << ", а компьютер его отгадывает"
		"\nВы будете писать " << SMALL << ", " << BIG << " или " << CORRECT << " после каждого числа, выведенного компьютером: \n"
		<< SMALL << ": Число слишком маленькое \n" << BIG << ": Число слишком большое \n" << CORRECT << ": Число было угадано" << endl;

	do
	{
		tries++;
		computerNumber = rand() % (max - min + 1) + min;

		if (computerNumber != border_min && computerNumber != border_max)
		{
			cout << "\nКомпьютер загадал такое число: "
				<< computerNumber
				<< ". Оно больше, меньше или равно загаданному числу?"
				<< endl;


			cout << "Ваш ответ: ";
			cin >> user_conceive;

			if (user_conceive == SMALL)
			{
				cout << "\nОтвет пользователя: " << small_number << endl;
				min = computerNumber + 1;
			}
			else if (user_conceive == BIG)
			{
				cout << "\nОтвет пользователя: " << big_number << endl;
				max = computerNumber - 1;
			}
			else if (user_conceive == CORRECT)
			{
				cout << "\nКомпьютер угадал ваше число и оно равно " << computerNumber <<
					" и на это ушло " << tries << " попыток" << endl;
				break;
			}
			else
			{
				cout << "\nОшибка! Неверно введённое число!" << endl;
				--tries;
				continue;
			}

		}
		else
		{
			if (min < border_min || max > border_max) 
			{
				changing_numbers = true;

				if (changing_numbers)
				{
					cout << "Вы меняете задуманное число!";
					return 0;
				}
			}
			if (computerNumber == border_min)
			{
				cout << "\n" << computerNumber << " - это минимальное число, которое может быть загадно. Это то что вы загадали?" << endl;

				cout << "Ваш ответ: ";
				cin >> user_conceive;

				if (user_conceive == CORRECT)
				{
					cout << "\nКомпьютер угадал ваше число и оно равно " << computerNumber <<
						" и на это ушло " << tries << " попыток" << endl;
					break;
				}
				else
				{
					cout << "\nОшибка! Загаданное число не может быть 0!" << endl;
					return 0;
				}
			}
			if (computerNumber == border_max)
			{
				cout << computerNumber << " - это максимальное число, которое может быть загадно. Это то что вы загадали?" << endl;

				cout << "Ваш ответ: ";
				cin >> user_conceive;

				if (user_conceive == CORRECT)
				{
					cout << "\nКомпьютер угадал ваше число и оно равно " << computerNumber <<
						" и на это ушло " << tries << " попыток" << endl;
					break;
				}
				else
				{
					cout << "\nОшибка! Загаданное число не может быть больше 50!" << endl;
					return 0;
				}
			}
		}


	} while (user_conceive != CORRECT);

	if (tries == MAX_TRIES)
	{
		cout << "К сожалению, компьютеру не удалось угадать число за " << tries << " попыток.\n";
	}

	return 0;
}
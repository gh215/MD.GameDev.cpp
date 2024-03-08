#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;

/*
Псевдокод

	Функция game_start
	{
		Заносим слова в вектор
		Устанавливаем генератор случайного посева чисел
		Перемешиваем слова
	}
	Функция get_user_var
	{
		Если игрок еще не превысил лимит ошибок, но и не разгадал это слово
			Сообщить игроку, сколько ошибок он еще имеет право допустить
			Показать игроку буквы, которые он уже угадал
			Показать игроку, какую часть загаданного слова он уже открыл
			Получить от игрока следующий вариант буквы
		Если игрок предложит букву, которую он уже угадал
			Получить вариант игрока
			Добавить новый вариант в множество использованных букв
		Если предложенная буква присутствует в загаданном слове
			Сообщить пользователю, что эта догадка верная
			Добавить в уже имеющийся фрагмент слова угаданную букву
		Иначе
			Сообщить игроку, что предложенный им вариант неверен
			Увеличить на единицу количество ошибочных вариантов, предложенных игроком
	}

	Функция game_end
	{
		Если игрок допустил слишком много ошибок
			Сообщить игроку, что он повешен
		Иначе
			Поздравить игрока с разгадкой секретного слова
	}
*/



const int МАХ_WRONG = 8;
vector<string>words;
int wrong = 0;
string soFar;
string used = "";

void game_start()
{
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
}
void get_user_var(string THE_WORD)
{
	while ((wrong < МАХ_WRONG) && (soFar != THE_WORD))
	{
		cout << "\nУ вас осталось " << (МАХ_WRONG - wrong) << " попыток";
		cout << "\nВы использовали следующие буквы: " << used;
		cout << "\nСлово: " << soFar << endl;

		char guess;
		cout << "\nВаш выбор: ";
		cin >> guess;
		guess = toupper(guess);

		while (used.find(guess) != string::npos)
		{
			cout << "\nВы уже использовали " << guess << endl;
			cout << "\nВаш выбор: ";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "\nЭто так! " << guess << " - это правильная буква.";
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "\nИзвините, " << guess << " это неправильная буква.";
			++wrong;
		}
	}
}
string game_end(string THE_WORD)
{
	if (wrong == МАХ_WRONG)
	{
		cout << "\nВас повесили!" << endl;
	}
	else
	{
		cout << "\nВы угадали!" << endl;
	}
	cout << "\nСлово, которое было загадано: " << THE_WORD << endl;
	return THE_WORD;
}

int main()
{
	setlocale(0, "Russian");
	game_start();
	const string THE_WORD = words[0];
	soFar = string(THE_WORD.size(), '-');
	cout << "\nДобро пожаловать в игру 'Виселица'! Удачи!" << endl;
	get_user_var(THE_WORD);
	game_end(THE_WORD);
}
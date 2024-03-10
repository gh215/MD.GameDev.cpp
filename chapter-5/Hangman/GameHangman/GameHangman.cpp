#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;

/*
Псевдокод
	Функция rn_seed_gen()
	{
		Запускает повсев случайных чисел
	}

	Функция get_words()
	{
		Создать вектор 
		Заности слова в вектор 
		Перемешивает порядок слов в векторе
		Вернуть вектор		
	}

	Функция get_init_soFar(слово)
	{
		Создать строку, состоящую из "-" длинной, равной длинне слова
		Вернуть строку
	}

	Функция display_game_stat(soFar, использованные_буквы, количество_ошибок)
	{
		Вывести количество оставшихся попыток
		Вывести использованные буквы
		Вывести текущее состояние угадываемого слова
	}

	Функция get_user_var(использованные_буквы)
	{
		Получить ввод от пользователя
		Преобразовать букву в верхний регистр
		Пока введенная буква уже использовалась:
			сообщить пользователю, что эта буква уже использовалась
			получить ввод буквы от пользователя
			преобразовать букву в верхний регистр
		Вернуть введенную букву
	}

	Функция get_upd_SoFar(слово, soFar, буква)
	{
		Создать новую строку newSoFar, копию soFar
		Сля каждого символа в слове:
			Если символ совпадает с буквой:
				заменить соответствующий символ в newSoFar на букву
		Вернуть newSoFar
	}

	Функция game_start(слово)
	{
		Инициализировать soFar вызовом get_init_soFar(слово)
		Инициализировать использованные_буквы пустой строкой
		Инициализировать количество_ошибок нулем
		Пока количество_ошибок меньше MAX_WRONG и soFar не равна слову:
			вывести состояние игры вызовом display_game_stat
			получить букву от пользователя вызовом get_user_var
			добавить букву в использованные_буквы
			Если буква присутствует в слове:
				сообщить, что буква верная
				обновить soFar вызовом get_upd_SoFar
			Иначе:
				сообщить, что буква неверная
				увеличить количество_ошибок
		Если количество_ошибок равно MAX_WRONG:
			вывести сообщение о проигрыше
		Иначе:
			вывести сообщение о выигрыше
		Вывести загаданное слово
	}
*/

void rn_seed_gen()
{
	srand(static_cast<unsigned int>(time(0)));
}
const int МАХ_WRONG = 8;

vector<string> get_words()
{
	vector<string>words;
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	random_shuffle(words.begin(), words.end());
	rn_seed_gen();
	return words;
}

string get_init_soFar(string word)
{
	return string(word.size(), '-');
}

void display_game_stat(string soFar, string used, int wrong)
{
	cout << "\nУ вас осталось " << (МАХ_WRONG - wrong) << " попыток";
	cout << "\nВы использовали следующие буквы: " << used;
	cout << "\nСлово: " << soFar << endl;
}

char get_user_var(string used)
{
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
	return guess;
}

string get_upd_SoFar(string word, string soFar, char guess) {
	string newSoFar = soFar;
	for (int i = 0; i < word.length(); ++i) 
	{
		if (word[i] == guess) 
		{
			newSoFar[i] = guess;
		}
	}
	return newSoFar;
}

void game_start(string word)
{
	string soFar = get_init_soFar(word);
	string used = "";
	int wrongCount = 0;

	while (wrongCount < МАХ_WRONG && soFar != word) 
	{
		display_game_stat(soFar, used, wrongCount);
		char guess = get_user_var(used);
		used += guess;

		if (word.find(guess) != string::npos) {
			cout << "\nЭто так! " << guess << " - это правильная буква.";
			soFar = get_upd_SoFar(word, soFar, guess);
		}
		else 
		{
			cout << "\nИзвините, " << guess << " это неправильная буква.";
			++wrongCount;
		}
	}

	if (wrongCount == МАХ_WRONG) {
		cout << "\nВас повесили!" << endl;
	}
	else {
		cout << "\nВы угадали!" << endl;
	}

	cout << "Слово, которое было загадано: " << word << endl;
}

int main()
{
	setlocale(0, "Russian");
	vector<string> words = get_words();
	string THE_WORD = words[0];
	cout << "\nДобро пожаловать в игру 'Виселица'! Удачи!" << endl;
	game_start(THE_WORD);
	return 0;
}
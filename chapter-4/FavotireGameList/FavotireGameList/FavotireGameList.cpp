#include "favgamelist.h"

/* Псевдокод

	Функция print_game_list(gameList):
		Если gameList пуст:
			Вывести сообщение об отсутствии игр
		Иначе:
			Вывести количество игр
			Для каждой игры в gameList:
				Вывести название игры

	Функция add_game(gameList):
		Запросить ввод названия игры
		Если игра уже есть в gameList:
			Вывести сообщение о наличии игры
		Иначе:
			Добавить игру в gameList
			Вывести сообщение об успешном добавлении

	Функция delete_game(gameList):
		Если gameList пуст:
			Вывести сообщение об отсутствии игр
		Иначе:
			Запросить ввод названия игры для удаления
			Если игра найдена в gameList:
				Удалить игру из gameList
				Вывести сообщение об успешном удалении
			Иначе:
				Вывести сообщение о том, что игра не найдена

	Функция delete_all_games(gameList):
		Если gameList пуст:
			Вывести сообщение об отсутствии игр
		Иначе:
			Очистить gameList
			Вывести сообщение об успешном удалении всех игр

	Функция print_help():
		Вывести справку по программе с описанием доступных вариантов выбора

	Объявить вектор gameList для хранения игр
	Объявить переменную user_input для хранения выбора пользователя

	Вывести приветственное сообщение
	Вывести инструкцию с доступными вариантами выбора

	Цикл:
		Запросить ввод у пользователя
		Если введено WATCH:
			Вызвать функцию print_game_list(gameList)
		Иначе если введено ADD:
			Вызвать функцию add_game(gameList)
		Иначе если введено DELETE:
			Вызвать функцию delete_game(gameList)
		Иначе если введено DELETE_ALL:
			Вызвать функцию delete_all_games(gameList)
		Иначе если введено HELP:
			Вызвать функцию print_help()
		Иначе если введено QUIT:
			Вывести прощальное сообщение
			Выйти из программы
		Иначе:
			Если введенное значение не является цифрой или не соответствует допустимым вариантам:
				Вывести сообщение об ошибке
				Очистить поток ввода
*/

void print_help()
{
	cout << "\nСправка по программе:\n";
	cout << WATCH << " - Посмотреть список текущих игр\n";
	cout << ADD << " - Добавить игру\n";
	cout << DELETE << " - Удалить игру\n";
	cout << DELETE_ALL << " - Удалить все игры\n";
	cout << QUIT << " - Выйти из программы\n";
}

string ask_user_game(string prompt, istream& input, ostream& output)
{
	string game;
	output << prompt << " ";
	input >> game;
	return game;
}

bool game_listed(vector<string>& gameList, string& game) 
{
	return find(gameList.begin(), gameList.end(), game) != gameList.end();
}

void real_add_game(vector<string>& gameList, string& game, ostream& output)
{
	gameList.push_back(game);
	output << "\nИгра была успешно добавлена!" << endl;
}

void real_delete_game(vector<string>& gameList, string& game, ostream& output)
{
	auto iter = find(gameList.begin(), gameList.end(), game);
	if (iter != gameList.end()) 
	{
		gameList.erase(iter);
		output << "Игра '" << game << "' была успешно удалена!" << endl;
	}
}

void delete_all_games(vector<string>& gameList)
{
	gameList.clear();
	cout << "\nВсе игры были успешно удалены!" << endl;
}

void add_game(vector<string>& gameList, istream& input, ostream& output)
{
	string game = ask_user_game("Какую игру вы хотите добавить?", input, output);
	if (game_listed(gameList, game))
	{
		output << "\nТакая игра уже существует!";
			return;
	}
	real_add_game(gameList, game, output);
}

void delete_game(vector<string>& gameList, istream& input, ostream& output)
{
	string game = ask_user_game("Какую игру вы хотите удалить?", input, output);
	if (!game_listed(gameList, game))
	{
		output << "\nИзвините, но в вашей библиотеке нет такой игры";
			return;
	}
	real_delete_game(gameList, game, output);
}

void print_game_list(vector<string>& gameList, ostream& output)
{
	if (gameList.empty())
	{
		output << "Извините, но в вашей библиотеке нет игр";
		return;
	}
	output << "\nНа данный момент у вас " << gameList.size() << " игр и среди них: \n";
	for (const auto& game : gameList)
	{
		output << " " << game << endl;
	}
}



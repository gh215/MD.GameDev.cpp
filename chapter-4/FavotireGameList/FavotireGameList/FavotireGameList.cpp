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

void print_game_list(vector<string>gameList)
{
	vector<string>::iterator watchGames;
	if (gameList.empty())
	{
		cout << "\nИзвините, но в вашей библиотеке нет игр" << endl;
	}
	else
	{
		cout << "\nНа данный момент у вас " << gameList.size() << " игр и среди них: \n";
		for (watchGames = gameList.begin(); watchGames != gameList.end(); ++watchGames)
		{
			cout << " " << *watchGames << endl;
		}
	}
}

void add_game(vector<string>& gameList)
{
	string user_game_input;
	cout << "\nПожалуйста, введите игру:" << endl;
	cin >> user_game_input;

	if (find(gameList.begin(), gameList.end(), user_game_input) != gameList.end())
	{
		cout << "\nЭта игра уже есть в списке\n";
	}
	else
	{
		gameList.push_back(user_game_input);
		cout << "\nИгра была успешно добавлена!" << endl;
	}
}

void delete_game(vector<string>& gameList)
{
	vector<string>::iterator deleteGames;
	string user_game_input;
	if (gameList.empty())
	{
		cout << "\nИзвините, но в вашей библиотеке нет игр, которые можно удалить" << endl;
	}
	else
	{
		cout << "\nПожалуйста, введите игру, которую хотите удалить: " << endl;
		cin >> user_game_input;
		deleteGames = find(gameList.begin(), gameList.end(), user_game_input);
		if (deleteGames != gameList.end())
		{
			gameList.erase(deleteGames);
			cout << "\nИгра была успешно удалена!" << endl;
		}
		else
		{
			cout << "Игра " << user_game_input << " не найдена в списке\n";
		}
	}
}

void delete_all_games(vector<string>& gameList)
{
	if (gameList.empty())
	{
		cout << "\nИзвините, но в вашей библиотеке нет игр, которые можно удалить" << endl;
	}
	else
	{
		gameList.clear();
		cout << "\nВсе игры были успешно удалены!" << endl;
	}
}



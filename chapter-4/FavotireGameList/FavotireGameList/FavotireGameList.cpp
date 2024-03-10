#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/* Псевдокод

*/

enum actions { WATCH = 1, ADD, DELETE, DELETE_ALL, HELP, QUIT };

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

int main()
{
	setlocale(0, "Russian");
	vector<string>gameList;
	int user_input;
	cout << "Добро пожаловать в нашу программу по спику ваших любимых игр" << endl;

	while (true)
	{
		cout << "\nВаш выбор: ";
		cin >> user_input;

		switch (user_input)
		{
		case WATCH:
			print_game_list(gameList);
			break;

		case ADD:
			add_game(gameList);
			break;

		case DELETE:
			delete_game(gameList);
			break;

		case DELETE_ALL:
			delete_all_games(gameList);
			break;

		case HELP:
			print_help();
			break;

		case QUIT:
			cout << "\nСпасибо, что воспользовались нашей программой!" << endl;
			return 0;

		default:
			if (cin.fail() || )
			{
				cout << "\nНеверный ввод, попробуйте ещё раз" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			break;
		}
	}
}



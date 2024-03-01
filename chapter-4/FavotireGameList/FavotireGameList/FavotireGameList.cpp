#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/* Псевдокод

	Приветственное слово К
	Он будет делать
	{
	П может просмотреть игры
	   Если нет игр, то выводится сообщение

	П может добавить игру
	   Если игра уже есть в списке - сообщает, что такая игра уже есть

	П может удалить заголовок игры
	   Если игр вообще нет - выводится сообщение
	   Если выбранной игры нет - выдаёт сообщение
	   Если неверно введена игра - выдаёт сообщение о том, что игры не существует

	П может удалить все игры в списке
	   Если игр вообще нет - выводится сообщение
	} Пока пользователь не захочет выйти из программы

*/

int main()
{
	setlocale(0, "Russian");

	vector<string>gameList;
	vector<string>::iterator deleteGames;
	vector<string>::iterator watchGames;

	int user_input;
	string user_game_input;

	enum actions { WATCH = 1, ADD, DELETE, DELETE_ALL, QUIT };

	cout << "Добро пожаловать в нашу программу по спику ваших любимых игр" << endl;

	cout << "\nЧто бы вы хотели сделать?" << endl;
	cout << "Выберите " << WATCH << ", чтобы посмотреть список текущих игр" << endl;
	cout << "Выберите " << ADD << ", чтобы добавить игру" << endl;
	cout << "Выберите " << DELETE << ", чтобы удалить игру" << endl;
	cout << "Выберите " << DELETE_ALL << ", чтобы удалить все игры" << endl;
	cout << "Если хотите выйти из программы - введите " << QUIT << endl;

	do
	{

		cout << "\nВаш выбор: ";
		cin >> user_input;

		if (user_input == WATCH)
		{
			if (gameList.empty())
			{
				cout << "\nИзвините, но в вашей библиотеке нет игр" << endl;
			}
			else
			{
				cout << "\nНа данный момент у вас " << gameList.size() << " игр и среди них: ";
				for (watchGames = gameList.begin(); watchGames != gameList.end(); ++watchGames)
				{
					cout << *watchGames << endl;
				}
			}

		}
		else if (user_input == ADD)
		{
			cout << "\nПожалуйста, введите игру:" << endl;
			cin >> user_game_input;

			if (find(gameList.begin(), gameList.end(), user_game_input) != gameList.end())
			{
				cout << "Эта игра уже есть в списке\n";
			}
			else
			{
				gameList.push_back(user_game_input);
			}
		}
		else if (user_input == DELETE)
		{
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
				}
			}
		}
		else if (user_input == DELETE_ALL)
		{
			if (gameList.empty())
			{
				cout << "\nИзвините, но в вашей библиотеке нет игр, которые можно удалить" << endl;
			}
			else
			{
				gameList.clear();
			}

		}
		else
		{
			cout << "\nНеверный ввод, попробуйте ещё раз" << endl;
		}

	} while (user_input != QUIT);

	return 0;
}

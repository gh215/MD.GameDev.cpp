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

	Переделать else if на switch
*/

int main()
{
	setlocale(0, "Russian");

	vector<string>gameList;
	vector<string>::iterator deleteGames;
	vector<string>::iterator watchGames;

	int user_input;
	string user_game_input;

	enum actions { WATCH = 1, ADD, DELETE, DELETE_ALL, HELP, QUIT };

	cout << "Добро пожаловать в нашу программу по спику ваших любимых игр" << endl;

	cout << "\nЧто бы вы хотели сделать?" << endl;
	cout << "Выберите " << WATCH << ", чтобы посмотреть список текущих игр" << endl;
	cout << "Выберите " << ADD << ", чтобы добавить игру" << endl;
	cout << "Выберите " << DELETE << ", чтобы удалить игру" << endl;
	cout << "Выберите " << DELETE_ALL << ", чтобы удалить все игры" << endl;
	cout << "Выберите " << HELP << ", чтобы получить помощь" << endl;
	cout << "Если хотите выйти из программы - введите " << QUIT << endl;

	while (true)
	{
		cout << "\nВаш выбор: ";
		cin >> user_input;

		switch (user_input)
		{
		case WATCH:
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
			break;

		case ADD:
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
			break;

		case DELETE:
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
			break;

		case DELETE_ALL:
			if (gameList.empty())
			{
				cout << "\nИзвините, но в вашей библиотеке нет игр, которые можно удалить" << endl;
			}
			else
			{
				gameList.clear();
				cout << "\nВсе игры были успешно удалены!" << endl;
			}
			break;

		case HELP:
			cout << "\nСправка по программе:\n";
			cout << WATCH << " - Посмотреть список текущих игр\n";
			cout << ADD << " - Добавить игру\n";
			cout << DELETE << " - Удалить игру\n";
			cout << DELETE_ALL << " - Удалить все игры\n";
			cout << QUIT << " - Выйти из программы\n";
			break;

		case QUIT:
			cout << "\nСпасибо, что воспользовались нашей программой!" << endl;
			return 0;

		default:
			if (cin.fail())
			{
				cout << "\nНеверный ввод, попробуйте ещё раз" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				/*
				cin.ignore игнорирует все символы из буфера ввода до следующего символа новой строки '\n' включительно.
				Это делается для того, чтобы очистить буфер ввода от некорректных символов, которые могли быть введены пользователем.
				numeric_limits<streamsize>::max() возвращает максимальное значение для типа streamsize, что означает,
				что функция ignore будет удалять символы до тех пор, пока не встретит символ новой строки или не достигнет конца потока ввода.
				*/
			}
			break;
		}
	}
}



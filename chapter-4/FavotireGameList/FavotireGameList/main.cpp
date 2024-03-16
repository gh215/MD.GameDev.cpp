#include "favgamelist.h"

int main()
{
	setlocale(0, "Russian");
	vector<string>gameList;
	int user_input;
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
			cout << "\nНеверный ввод, попробуйте ещё раз" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}
#include "favgamelist.h"

int main()
{
	setlocale(0, "Russian");
	vector<string>gameList;
	int user_input;
	cout << "����� ���������� � ���� ��������� �� ����� ����� ������� ���" << endl;
	print_help();
	cout << "�������� " << HELP << ", ����� �������� ������" << endl;

	while (true)
	{
		cout << "\n��� �����: ";
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
			cout << "\n��� ���� ���� ������� �������!" << endl;
			break;

		case HELP:
			print_help();
			break;

		case QUIT:
			cout << "\n�������, ��� ��������������� ����� ����������!" << endl;
			return 0;

		default:
			cout << "\n�������� ����, ���������� ��� ���" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}
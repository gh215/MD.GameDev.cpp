#include "hang.h"

int main()
{
	setlocale(0, "Russian");
	string THE_WORD = get_word();
	cout << "\n����� ���������� � ���� '��������'! �����!" << endl;
	game_start(THE_WORD);
	return 0;
}
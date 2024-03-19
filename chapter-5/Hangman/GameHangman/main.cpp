#include "hang.h"

int main()
{
	setlocale(0, "Russian");
	string THE_WORD = get_word();
	cout << "\nДобро пожаловать в игру 'Виселица'! Удачи!" << endl;
	game_start(THE_WORD);
	return 0;
}
#include "WordKneader.h"

string permute(string jumble)
{
	int length = jumble.size();

	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
	return jumble;
}


void greetings(string jumble, int score)
{
	cout << "\t\t Добро пожаловть в игру 'Словомеска'!\n\n";
	cout << "Соберите буквы, чтобы отгадать слово\n";
	cout << "Введите слово 'hint', чтобы дать подсказку\n";
	cout << "Введите слово 'quit', для выходя из игры\n";
	cout << "Ваш текущий результат очков = " << score << endl;
	cout << "Перемешанное слово - это " << jumble;
}

string get_user_answer(istream& input, ostream& output)
{
	string guess;
	output << "\n\nВаш ответ: ";
	input >> guess;
	return guess;
}

void print_hint(string& theHint, int& score, int& score_used_hint, bool& usedHint, ostream& output)
{
	output << theHint;
	usedHint = true;
	penalty(score, score_used_hint);
	output << "\nВы воспользовались подсказкой. Ваш текущий результат очков = " << score_used_hint << endl;
}

void penalty(int& score, int& score_used_hint)
{
	score_used_hint = score - scoreHint;
}

void try_again(ostream& output)
{
	output << "\nУвы, но слово неправильное! Попробуйте ещё раз." << endl;
}

void farewell(int& score, ostream& output)
{
	output << "Спасибо за игру! Приходите ещё!\n";
	output << "Ваш текущий результат очков = " << score << endl;
}

int action(string& theWord, string& theHint, int& score, int& score_used_hint, bool& usedHint, istream& input, ostream& output)
{
	string guess = get_user_answer(input, output);
	while (guess != theWord && guess != "quit")
	{
		if (guess == "hint")
		{
			print_hint(theHint, score, score_used_hint, usedHint, output);
		}
		else
		{
			try_again(output);
		}
		guess = get_user_answer(input, output);
	}
	if (guess == theWord)
	{
		output << "\nДа, всё верно!";
		score += theWord.length();
		if (usedHint)
		{
			score -= scoreHint;
		}
		return score;
	}
	return 0;
}
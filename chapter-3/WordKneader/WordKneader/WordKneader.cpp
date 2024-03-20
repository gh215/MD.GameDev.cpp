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


void intro(string jumble, int score)
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

int get_user_guess(string& theWord, string& theHint, bool& usedHint, int& score_used_hint, int& score, istream& input, ostream& output)
{
    string guess = get_user_answer(input, output);
    while ((guess != theWord) && (guess != "quit"))
    {
        if (guess == "hint")
        {
            output << theHint;
            usedHint = true;
            score_used_hint = score - scoreHint;
            output << "\nВы воспользовались подсказкой. Ваш текущий результат очков = " << score_used_hint << endl;
        }
        else
        {
            output << "Нет, это неправильный ответ. Попробуйте ещё раз";
        }
        output << "\nВаш ответ: ";
        input >> guess;
    }

    if (guess == theWord)
    {

        output << "Да, всё верно!";
        int score = theWord.length();
        if (usedHint)
        {
            score -= scoreHint;
        }
        output << "Ваш текущий результат очков = " << score << endl;
        return score;
    }
    return 0;
}
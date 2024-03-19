#include "WordKneader.h"
/* Тест-кейсы
    1. Если пользователь угадал слово без подсказок - он получает количество очков, равное длине слова
    2. Если пользователь угадал слово с одной подсказкой - количество, равное длине слова минус 3
    3. Если угадал с несколькими подсказками - также количество, равное длине слова минус 3
    4. Если не угадал - его спрашивают до тех пор, пока он не нажал quit
    */

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

string get_user_answer()
{
    string guess;
    cout << "\n\nВаш ответ: ";
    cin >> guess;
    return guess;
}

int get_user_guess(string& theWord, string& theHint, bool& usedHint, int& score_used_hint, int& score)
{
    string guess = get_user_answer();
    while ((guess != theWord) && (guess != "quit"))
    {
        if (guess == "hint")
        {
            cout << theHint;
            usedHint = true;
            score_used_hint = score - scoreHint;
            cout << "\nВы воспользовались подсказкой. Ваш текущий результат очков = " << score_used_hint << endl;
        }
        else
        {
            cout << "Нет, это неправильный ответ. Попробуйте ещё раз";
        }
        cout << "\nВаш ответ: ";
        cin >> guess;
    }

    if (guess == theWord)
    {

        cout << "Да, всё верно!";
        int score = theWord.length();
        if (usedHint)
        {
            score -= scoreHint;
        }
        cout << "Ваш текущий результат очков = " << score << endl;
        return score;
    }
    return 0;
}
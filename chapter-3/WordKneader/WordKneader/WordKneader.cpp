﻿#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

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

int main()
{
    setlocale(0, "Russian");

    enum fields { WORD, HINT, NUM_FIELDS };
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
         {"wall", "Чувствуешь ли ты, что бьёшься головой о что-то?"},
         {"glasses", "Это поможет вам увидеть ответ на вопрос."},
         {"labored", "Слишком медленно, не так ли?"},
         {"persistent", "Продолжайте в том же духе!"},
         {"jumble", "В этом и заключается смысл игры."}
    };

    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];
    int score = 0;
    string jumble = theWord;

    jumble = permute(jumble);
    const int scoreHint = 3;
    int score_used_hint = 0;
    bool usedHint = false;

    cout << "\t\t Добро пожаловть в игру 'Словомеска'!\n\n";
    cout << "Соберите буквы, чтобы отгадать слово\n";
    cout << "Введите слово 'hint', чтобы дать подсказку\n";
    cout << "Введите слово 'quit', для выходя из игры\n";
    cout << "Ваш текущий результат очков = " << score << endl;
    cout << "Перемешанное слово - это " << jumble;
    string guess;
    cout << "\n\nВаш ответ: ";
    cin >> guess;

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
    }

    cout << "Спасибо за игру! Ждём Вас снова!";

    return 0;
}
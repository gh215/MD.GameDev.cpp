#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

/* Тест-кейсы
    1. Если пользователь угадал слово wall без использования подсказки, то он получает 4 очка
    2. Если пользователь угадал слово glasses без использования подсказки, то он получает 7 очков
    3. Если пользователь угадал слово labored без использования подсказки, то он получает 7 очков
    4. Если пользователь угадал слово persistent без использования подсказки, то он получает 10 очков
    5. Если пользователь угадал слово jumble без использования подсказки, то он получает 6 очков
    6. Если пользователь угадал слово wall с использованием подсказки, то он получает 1 очко
    7. Если пользователь угадал слово glasses с использованием подсказки, то он получает 4 очка
    8. Если пользователь угадал слово labored с использованием подсказки, то он получает 4 очка
    9. Если пользователь угадал слово persistent с использованием подсказки, то он получает 7 очков
    10. Если пользователь угадал слово jumble с использованием подсказки, то он получает 3 очка
*/
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
    int length = jumble.size();

    for (int i = 0; i < length; ++i)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    const int scoreHint = 3;
    int score_used_hint = 0;
    int score_not_used_hint = 0;
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
        if (!usedHint)
        {
            score_not_used_hint += theWord.length();
            cout << "Ваш текущий результат очков = " << score_not_used_hint << endl;
        }
        else
        {
            score_used_hint += theWord.length();
            cout << "Ваш текущий результат очков = " << score_used_hint << endl;
        }
        
    }

    cout << "Спасибо за игру! Ждём Вас снова!";

    return 0;
}

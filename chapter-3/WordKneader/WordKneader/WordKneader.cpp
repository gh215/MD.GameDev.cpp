#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;


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

    int scoreWord = theWord.length();
    const int scoreHint = 3;
    int score1 = score - scoreHint;
    int score2 = score1 + scoreWord;

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
            cout << "\nВы воспользовались подсказкой. Ваш текущий результат очков = " << score1 << endl;
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
        cout << "Ваш текущий результат очков = " << score2 << endl;
    }

    cout << "Спасибо за игру! Ждём Вас снова!";

    return 0;
}

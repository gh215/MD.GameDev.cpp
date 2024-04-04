#include "WordKneader.h"
/* Тест-кейсы
    1. Если пользователь угадал слово без подсказок - он получает количество очков, равное длине слова
    2. Если пользователь угадал слово с одной подсказкой - количество, равное длине слова минус 3
    3. Если угадал с несколькими подсказками - также количество, равное длине слова минус 3
    4. Если не угадал - его спрашивают до тех пор, пока он не нажал quit
    */


int main()
{
    setlocale(0, "Russian");

    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];
    string jumble = theWord;
    jumble = permute(jumble);

    greetings(jumble);
    int score = action(theWord, theHint);
    farewell(score);
    return 0;
}
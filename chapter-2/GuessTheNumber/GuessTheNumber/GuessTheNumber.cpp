#include <iostream>
#include <cstdlib>
#include <ctime>

/*
написать тест кейс
*/

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int user_conceive;
    int computerNumber;
    enum { SMALL = 1, BIG, CORRECT };
    int tries = 0;
    int min = 1;
    int max = 100;

    cout << "Добро пожаловать в нашу игру! Вы загадываете число в уме, а компьютер его отгадывает"
        "\n Вы будете писать " << SMALL << ", " << BIG << " или " << CORRECT << " после каждого числа, выведенного компьютером: \n"
        << SMALL << ": Число слишком маленькое \n" << BIG << ": Число слишком большое \n" << CORRECT << ": Число было угадано" << endl;

    do
    {
        tries++;

        computerNumber = rand() % (max - min + 1) + min;

        cout << "Компьютер загадал такое число: " 
          << computerNumber 
          << ". Оно больше, меньше или равно загаданному числу?" 
          << endl;

        cout << "Ваш ответ: ";
        cin >> user_conceive;

        if (user_conceive == SMALL)
        {
            cout << "Число слишком маленькое" << endl;
            if (computerNumber > 0)
            {
                max = computerNumber - 1;
            }
            else
            {
                return 0;
            }

        }

        else if (user_conceive == BIG)
        {
            cout << "Число слишком большое" << endl;
            min = computerNumber + 1;

        }
        else if (user_conceive == CORRECT)
        {
            cout << "Компьютер угадал ваше число и оно = " << computerNumber << " и на это ушло " << tries << " попыток" << endl;
        }
        else
        {
            cout << "Ошибка! Неверно введённое число!" << endl;
            return 1;
        }

    } while (user_conceive != CORRECT);

    return 0;

}
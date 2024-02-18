#include <iostream>
#include <cstdlib>
#include <ctime>


/* Тест-кейсы для нормального пользователя
    1. П задумал число на нижней границе:
    число больше - К генерирует число меньше
    2. 
    3. 
    Сужает диапазон
    Число шагов не
    За 10 шагов компьютер должен угадать число

    Тест-кейсы для ненормального пользователя
    1. За диапазоном
    2. Недопустимы ответ (пр. 4)
    3. Пользователь меняет показания

*/  

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    enum { SMALL = 1, BIG, CORRECT };
    int user_conceive, computerNumber;
    int tries = 0;
    int min = 1, max = 50;
    srand(static_cast<unsigned int>(time(0)));

    cout << "Добро пожаловать в нашу игру! Вы загадываете число в уме от " << min << " до " << max << ", а компьютер его отгадывает"
        "\nВы будете писать " << SMALL << ", " << BIG << " или " << CORRECT << " после каждого числа, выведенного компьютером: \n"
        << SMALL << ": Число слишком маленькое \n" << BIG << ": Число слишком большое \n" << CORRECT << ": Число было угадано" << endl;
       
    do
    {
        if (max <= min)
        {
            cout << "Ошибка! Загаданное число не может быть 0 или больше 50!" << endl;
            return 0;
        }

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
            min = computerNumber + 1;
        }

        else if (user_conceive == BIG)
        {
            cout << "Число слишком большое" << endl;
            max = computerNumber - 1;

        }
        else if (user_conceive == CORRECT)
        {
            cout << "Компьютер угадал ваше число и оно = " << computerNumber <<
                " и на это ушло " << tries << " попыток" << endl;
            return 0;
        }
        else
        {
            cout << "Ошибка! Неверно введённое число!" << endl;
            return 0;
        }      
       
    }   while (user_conceive != CORRECT); 
}

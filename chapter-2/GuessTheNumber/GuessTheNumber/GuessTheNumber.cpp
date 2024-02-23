#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


/* Тест-кейсы для нормального пользователя
    1. П задумал число на нижней границе:
    число больше - К генерирует число меньше
    2. П задумал число на верхней границе:
    число меньше - К генерирует число больше
    3. П задумал число на середине:
    Сужает диапазон. Число меньше - ставит меньшую границу диапазона
    Число больше - ставит большую границу диапазона

    За 7 шагов компьютер должен угадать число

    Тест-кейсы для ненормального пользователя
    1. За диапазоном - выдаёт ошибку
    2. Недопустимы ответ (например 4), компьютер должен продолжать игру
    3. Пользователь меняет показания - программа называет его обманщиком

*/  

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");    
    srand(static_cast<unsigned int>(time(0)));

    enum { SMALL = 1, BIG, CORRECT };

    int user_conceive, computerNumber;
    int tries = 0;
    int min = 1, max = 50;

    bool changing_numbers = false;

    string small_number = "число слишком маленькое";
    string big_number = "число слишком большое";


    cout << "Добро пожаловать в нашу игру! Вы загадываете число в уме от " << min << " до " << max << ", а компьютер его отгадывает"
        "\nВы будете писать " << SMALL << ", " << BIG << " или " << CORRECT << " после каждого числа, выведенного компьютером: \n"
        << SMALL << ": Число слишком маленькое \n" << BIG << ": Число слишком большое \n" << CORRECT << ": Число было угадано" << endl;
       
    do
    {
        if (max <= min)
        {
            cout << "\nОшибка! Загаданное число не может быть 0 или больше 50!" << endl;
            return 0;
        }

        tries++;

        computerNumber = rand() % (max - min + 1) + min;     
        cout << "\nКомпьютер загадал такое число: "
            << computerNumber
            << ". Оно больше, меньше или равно загаданному числу?"
            << endl;

        cout << "Ваш ответ: ";
        cin >> user_conceive;

        if (user_conceive == SMALL)
        {

            cout << "\nОтвет пользователя: " << small_number << endl;
            min = computerNumber + 1;
        }

        else if (user_conceive == BIG)
        {
            cout << "\nОтвет пользователя: " << big_number << endl;
            max = computerNumber - 1;
        }
        else if (user_conceive == CORRECT)
        {
            cout << "\nКомпьютер угадал ваше число и оно равно " << computerNumber <<
                " и на это ушло " << tries << " попыток" << endl;
            break;
        }
        else
        {
            cout << "\nОшибка! Неверно введённое число!" << endl;
            continue;
        }      
        if (min > max || max < min)
        {
            changing_numbers = true;
            cout << "\nТы обманываешь меня!" << endl;
            return 0;
        }
       
    }   while (user_conceive != CORRECT && tries != 7); 

    if (tries == 7) 
    {
        cout << "К сожалению, компьютеру не удалось угадать число за " << tries << " попыток.\n";
    }

    return 0;
}
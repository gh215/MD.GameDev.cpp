#include <iostream>
#include <cstdlib>
#include <ctime>

/*
    если число 0 - ошибка
    если число больше 50 - ошибка
    если число = 1 - минимальное значение
    если число = 50 - максимальное значение

    if ((max != 0 && min != 0) && (max < 50 && min < 50))
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
    int max = 50;

    cout << "Добро пожаловать в нашу игру! Вы загадываете число в уме от 1 до 50, а компьютер его отгадывает"
        "\nВы будете писать " << SMALL << ", " << BIG << " или " << CORRECT << " после каждого числа, выведенного компьютером: \n"
        << SMALL << ": Число слишком маленькое \n" << BIG << ": Число слишком большое \n" << CORRECT << ": Число было угадано" << endl;
       
    do
    {
       if ((max > 0 && min > 0) && (max < 51 && min < 51))
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
               max = computerNumber - 1;
           }

           else if (user_conceive == BIG)
           {
               cout << "Число слишком большое" << endl;
               min = computerNumber + 1;

           }
           else if (user_conceive == CORRECT)
           {
               cout << "Компьютер угадал ваше число и оно = " << computerNumber <<
                   " и на это ушло " << tries << " попыток" << endl;
               return 1;
           }
           else if (user_conceive == CORRECT)
           {

           }
           else
           {
               cout << "Ошибка! Неверно введённое число!" << endl;
               return 0;
           }
       
       } 
       else
       {
           cout << "Ошибка! Загаданное число не может быть 0 или больше 50!" << endl;
           return 0;
       }
       
    }   while (user_conceive != CORRECT); 
}

#include <iostream>
#include <cstdlib>
#include <ctime>

/*
    если компьютер предлагает 1 - подтвердить правильность, конец программы.  
    если пользователь отвечает - "маленькое" - ошибка
    каждое следующее предложенное число должно быть меньше предыдущего.
    пользователь отвечает - "большое" - число уменьшается
    пользователь отвечает - "маленькое" - число увеличивается
    если компьютер предлагает 50 - подтвердить правильность, конец программы.
    если пользователь отвечает - "большое" - ошибка
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
    const int limit_max_Number = 51;
    const int limit_min_Number = 0;
    srand(static_cast<unsigned int>(time(0)));

    cout << "Добро пожаловать в нашу игру! Вы загадываете число в уме от 1 до 50, а компьютер его отгадывает"
        "\nВы будете писать " << SMALL << ", " << BIG << " или " << CORRECT << " после каждого числа, выведенного компьютером: \n"
        << SMALL << ": Число слишком маленькое \n" << BIG << ": Число слишком большое \n" << CORRECT << ": Число было угадано" << endl;
       
    do
    {

       if (!(max > limit_min_Number && min > limit_min_Number) 
       && (max < limit_max_Number && min < limit_max_Number))
       {
           cout << "Ошибка! Загаданное число не может быть 0 или больше 50!" << endl;
           return 0;
       }
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
               min = computerNumber - 1;
           }

           else if (user_conceive == BIG)
           {
               cout << "Число слишком большое" << endl;
               max = computerNumber + 1;

           }
           else if (user_conceive == CORRECT)
           {
               cout << "Компьютер угадал ваше число и оно = " << computerNumber <<
                   " и на это ушло " << tries << " попыток" << endl;
               return 1;
           }
           else
           {
               cout << "Ошибка! Неверно введённое число!" << endl;
               return 0;
           }
       
       } 
       
    }   while (user_conceive != CORRECT); 
}

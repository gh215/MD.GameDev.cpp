﻿#include "gtn.h"

/* Тест-кейсы для нормального пользователя

1. П задумал число на нижней границе:
   - К должен продолжать предлагать числа, пока не угадает нижнюю границу.

2. П задумал число на верхней границе:
   - К должен продолжать предлагать числа, пока не угадает верхнюю границу.

3. П задумал число на середине:
   - Сужает диапазон. Число меньше - ставит меньшую границу диапазона
   - Число больше - ставит большую границу диапазона
   - К должен продолжать предлагать числа, пока не угадает.

    Тест-кейсы для ненормального пользователя

1. За диапазоном:
   - Если П задумал число вне диапазона 1-50, К должен выдать предупреждение.

2. Недопустимый ответ:
   - Если П вводит что-то кроме 1, 2 или 3, К должен выдать сообщение о неверном вводе и запросить ввод снова.

3. Пользователь меняет загаданное число за пределы установленного К диапазона во время игры:
   - П задумывает число в пределах диапазона и отвечает корректно 1 или 2
   - К сужает диапазон согласно ответам П
   - Когда число почти угадано, но затем П меняет загаданное число на число за пределами установленного К диапазона
     К сообщает, что число не может быть меньше/больше min/max


За разумное количество попыток, компьютер должен угадать число.
*/

void game()
{
    greeting();
    int min = border_min;
    int max = border_max;
    do
    {
        int comp_num = num_gen(min, max);
        int user_cons = ask_user(comp_num, min, max);
        if (user_cons == CORRECT)
        {
            tell_guessed(comp_num);
            break;
        }
        bord_reduct(comp_num, user_cons, min, max);
        if (min == max)
        {
            tell_guessed(min);
            break;
        }

    } while (true);
}

int main()
{
    setlocale(0, "Russian");
    srand(static_cast<unsigned int>(time(0)));
    game();
}


﻿#include <iostream>
#include <cmath>

using namespace std;

/* Тест-кейсы
    1. Если сумма очков 0 - средне арифметическое будет = 0
    2. Если сумма очков 1 - средне арифметическое будет = 1
    3. Если сумма очков 4 - средне арифметическое будет = 1.33333
    4. Если сумма очков 5 - средне арифметическое будет = 1.66667
    5. Если сумма очков 7 - средне арифметическое будет = 2.33333
    6. Если сумма очков 8 - средне арифметическое будет = 2.66667
    7. Если сумма очков 10 - средне арифметическое будет = 3.33333
*/

int main()
{
    setlocale(LC_ALL, "Russian");

    float a, b, c;
    float score = 0;
    float arithmetic_mean_number = 3;

    cout << "Добро пожаловать в нашу игру по вычислению средне арифметического Ваших очков" << endl;

    cout << "Введите первую сумму очков: " << endl;
    cin >> a;

    cout << "Введите первую сумму очков: " << endl;
    cin >> b;

    cout << "Введите первую сумму очков: " << endl;
    cin >> c;

    score = (a + b + c) / arithmetic_mean_number;

    cout << "Средне арифметическое очков = " << score << endl;;
}
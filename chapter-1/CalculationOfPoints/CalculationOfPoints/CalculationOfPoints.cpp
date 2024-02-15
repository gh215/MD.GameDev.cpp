#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int a, b, c;
    int score = 0;
    int arithmetic_mean_number = 3;

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

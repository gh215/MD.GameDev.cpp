#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    enum difficulty { EASY = 1, NORMAL, HARD };
    int choice;
    cout << "Ваш выбор сложности от " << EASY << " до " << HARD << ", где "
        << EASY << " - Легкий, " << NORMAL << " - Средний, " << HARD << " - Тяжёлый" << endl;
    cin >> choice;

    switch (choice)
    {
    case EASY:
        cout << "Вы выбрали лёгкий уровень сложности" << endl;
        break;
    case NORMAL:
        cout << "Вы выбрали средний уровень сложности" << endl;
        break;
    case HARD:
        cout << "Вы выбрали тяжёлый уровень сложности" << endl;
        break;
    default:
        cout << "Неверная цифра ввода" << endl;
        break;
    }

    return 0;
}

#include <iostream>
#include <string>

/*
С помощью аргументов, задаваемых по умолчанию, напишите функцию, которая запрашивает у пользователя число и возвращает это число. 
Функция должна принимать строковое приглашение от вызывающего кода. Если вызывающий код не предоставляет такого приглашения, 
то функция должна использовать обобщённое приглашение. Затем с помощью перегрузки напишите функцию, обеспечивающую такой же результат.*/

/*  Псевдокод
    Function getNumberFromUser(prompt): 
    ЕСЛИ подсказка не предоставлена: 
        prompt = "Введите число: " 
    Вывести подсказку 
    Считать введенные пользователем данные в переменную 
    Вернуть переменную 

    Function getNumberFromUser(prompt, dataType): 
    ЕСЛИ подсказке не предоставлена: 
        prompt = "Enter a " + dataType + ": " 
    Вывести подсказку 
    Считать введенные пользователем данные в переменную 
    Вернуть переменную 

    Main: запросить пользователя с помощью getNumberFromUser(), используя подсказку по умолчанию 
    Сохранить результат в переменной 
    Вывести переменную 

    Предоставить пользовательскую подсказку для getNumberFromUser() 
    Чохраните результат в другой переменной 
    Вывести вторую переменную  

    Вызвать перегруженную функцию getNumberFromUser() с типом данных 
    Сохраните результат в третьей переменной 
    Вывести третью переменную
*/


using namespace std;

int getNumberFromUser(string prompt = "Введите число: ") 
{
    int num;
    cout << prompt;
    cin >> num;
    return num;
}

int getNumberFromUser(string prompt, string dataType) 
{
    if (prompt.empty()) 
    {
        prompt = "Введите " + dataType + ": ";
    }
    int num;
    cout << prompt;
    cin >> num;
    return num;
}

int main() 
{
    setlocale(0, "Russian");

    int num1 = getNumberFromUser();
    cout << "Вы ввели: " << num1 << std::endl;

    int num2 = getNumberFromUser("Введите ваш возраст: ");
    cout << "Вы ввели: " << num2 << std::endl;

    int num3 = getNumberFromUser("", "integer");
    cout << "Вы ввели: " << num3 << std::endl;

    return 0;
}
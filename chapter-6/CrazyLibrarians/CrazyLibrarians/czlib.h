#pragma once
#include <iostream>
#include <string>
using namespace std;

string askText(const char* prompt)
{
	string text;
	do
	{
		cout << prompt;
		cin >> text;
		if (text.empty())
		{
			cout << "Введенное значение пустое. Пожалуйста, повторите попытку.\n";
		}
	} while (text.empty());
	return text;
}

int askNumber(const char* prompt)
{
	int num;
	do {
		cout << prompt;
		cin >> num;
		if (cin.fail()) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введенное значение не является числом. Пожалуйста, повторите попытку.\n";
		}
	} while (cin.fail());
	return num;

}

void tellStory(string& name, string& noun, int number, string& bodyPart, string& verb)
{

	cout << "\nВот ваша история:\n";
	cout << "Известный путешественник ";
	cout << name;
	cout << " почти отказался от поисков\n";
	cout << " Затерянного города ";
	cout << noun;
	cout << " , когда в один прекрасный день ";
	cout << noun;
	cout << " нашел исследователя. \n";
	cout << "Окруженный ";
	cout << number;
	cout << " " << noun;
	cout << ". а слеза попала в ";
	cout << name << "'s ";
	cout << bodyPart << ". \n";
	cout << "После стольких лет поиски наконец-то закончились. ";
	cout << "И тогда. ";
	cout << noun << "\n";
	cout << "быстро сожрали";
	cout << name << ". ";
	cout << "Мораль сей истории? Будте осторожны в ";
	cout << verb;
	cout << ". \n";
}

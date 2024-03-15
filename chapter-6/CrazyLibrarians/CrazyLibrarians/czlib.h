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
			cout << "��������� �������� ������. ����������, ��������� �������.\n";
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
			cout << "��������� �������� �� �������� ������. ����������, ��������� �������.\n";
		}
	} while (cin.fail());
	return num;

}

void tellStory(string& name, string& noun, int number, string& bodyPart, string& verb)
{

	cout << "\n��� ���� �������:\n";
	cout << "��������� �������������� ";
	cout << name;
	cout << " ����� ��������� �� �������\n";
	cout << " ����������� ������ ";
	cout << noun;
	cout << " , ����� � ���� ���������� ���� ";
	cout << noun;
	cout << " ����� �������������. \n";
	cout << "���������� ";
	cout << number;
	cout << " " << noun;
	cout << ". � ����� ������ � ";
	cout << name << "'s ";
	cout << bodyPart << ". \n";
	cout << "����� �������� ��� ������ �������-�� �����������. ";
	cout << "� �����. ";
	cout << noun << "\n";
	cout << "������ �������";
	cout << name << ". ";
	cout << "������ ��� �������? ����� ��������� � ";
	cout << verb;
	cout << ". \n";
}

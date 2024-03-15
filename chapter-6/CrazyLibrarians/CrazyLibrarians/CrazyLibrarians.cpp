#include "czlib.h"

int main()
{

	setlocale(0, "Russian");

	cout << "\nДобро пожаловать в игру 'Безумные библиотекари' ";
	cout << "\nОтветьте на следующие вопросы, чтобы помочь создать новую историю.";
	string name = askText("\nПожалуйста, введите имя: ");
	string noun = askText("\nПожалуйста, укажите существительное во множественном числе: ");

	int number = askNumber("\nПожалуйста, введите число: ");

	string bodyPart = askText("\nПожалуйста, укажите часть тела: ");
	string verb = askText("\nПожалуйста, введите глагол: ");

	tellStory(name, noun, number, bodyPart, verb);

	return 0;
}
#include "czlib.h"

string askText(const char* prompt, istream& input , ostream& output)
{
	string text;
	while (true)
	{
		output << prompt;
		input >> text;
		bool isValid = true;
		for (char c : text) 
		{
			if (!isalpha(c)) 
			{
				isValid = false;
				break;
			}
		}

		if (isValid) 
		{
			break;
		}
		output << "The entered value is not a letter. Please try again.\n";
		input.clear();
		input.ignore(numeric_limits<streamsize>::max(), '\n');
	} 
	return text;
}

int askNumber(const char* prompt, istream& input, ostream& output)
{
	int num;
	while(true) 
	{
		output << prompt;
		input >> num;
		if (!input.fail())
		{
			input.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		input.clear();
		input.ignore(numeric_limits<streamsize>::max(), '\n');
		output << "The entered value is not a number. Please try again.\n";
		
	} 
	return num;

}

void tellStory(string& name, string& noun, int number, string& bodyPart, string& verb)
{
	cout << "\nHere's your story:\n\n";
	cout << "The famous explorer ";
	cout << name;
	cout << " had nearly given up a life-long quest to find\n";
	cout << "The Lost City of ";
	cout << noun;
	cout << " when one day. The ";
	cout << noun;
	cout << " found the explorer. \n";
	cout << "Surrounded by ";
	cout << number;
	cout << " " << noun;
	cout << ", a tear came to ";
	cout << name << "'s ";
	cout << bodyPart << ". \n";
	cout << "After all this time, the quest was finally over. ";
	cout << "And then, the ";
	cout << noun << "\n";
	cout << "promptly devoured ";
	cout << name << ". ";
	cout << "The moral of the story? Be careful what you ";
	cout << verb;
	cout << " for. ";
}

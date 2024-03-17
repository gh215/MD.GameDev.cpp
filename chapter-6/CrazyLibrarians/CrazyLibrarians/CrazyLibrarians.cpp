#include "czlib.h"

istream* input = &cin;
ostream* output = &cout;

void set_io_streams(istream* i = &cin, ostream* o = &cout)
{
	input = i;
	output = o;
}

string askText(const char* prompt)
{
	string text;
	while (true)
	{
		(*output) << prompt;
		(*input) >> text;
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
		(*output) << "The entered value is not a letter. Please try again.\n";
		(*input).clear();
		(*input).ignore(numeric_limits<streamsize>::max(), '\n');
	} 
	return text;
}

int askNumber(const char* prompt)
{
	int num;
	while(true) 
	{
		(*output) << prompt;
		(*input) >> num;
		if (!(*input).fail())
		{
			(*input).ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		(*input).clear();
		(*input).ignore(numeric_limits<streamsize>::max(), '\n');
		(*output) << "The entered value is not a number. Please try again.\n";
		
	} 
	return num;

}

void tellStory(string& name, string& noun, int number, string& bodyPart, string& verb)
{
	(*output) << "\nHere's your story:\n\n";
	(*output) << "The famous explorer ";
	(*output) << name;
	(*output) << " had nearly given up a life-long quest to find\n";
	(*output) << "The Lost City of ";
	(*output) << noun;
	(*output) << " when one day. The ";
	(*output) << noun;
	(*output) << " found the explorer. \n";
	(*output) << "Surrounded by ";
	(*output) << number;
	(*output) << " " << noun;
	(*output) << ", a tear came to ";
	(*output) << name << "'s ";
	(*output) << bodyPart << ". \n";
	(*output) << "After all this time, the quest was finally over. ";
	(*output) << "And then, the ";
	(*output) << noun << "\n";
	(*output) << "promptly devoured ";
	(*output) << name << ". ";
	(*output) << "The moral of the story? Be careful what you ";
	(*output) << verb;
	(*output) << " for. ";
}

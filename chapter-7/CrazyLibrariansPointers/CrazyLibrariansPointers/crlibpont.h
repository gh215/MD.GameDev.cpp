#pragma once
#include <iostream>
#include <string>
#include <locale>

using namespace std;

string askText(const char* prompt, istream& in = cin, ostream& out = cout);
int askNumber(const char* prompt, istream& in = cin, ostream& out = cout);
void tellStory(const string* name, string* noun, int number, string* bodyPart, string* verb);
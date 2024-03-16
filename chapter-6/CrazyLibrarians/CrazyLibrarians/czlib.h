#pragma once
#include <iostream>
#include <string>
#include <locale>

using namespace std;

string askText(const char* prompt);
int askNumber(const char* prompt);
void tellStory(string& name, string& noun, int number, string& bodyPart, string& verb);

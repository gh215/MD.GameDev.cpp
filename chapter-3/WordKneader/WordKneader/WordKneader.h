#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

const int scoreHint = 3;

void intro(string jumble, int score);
string get_user_answer();
int get_user_guess(string& theWord, string& theHint, bool& usedHint, int& score_used_hint, int& score);
string permute(string jumble);
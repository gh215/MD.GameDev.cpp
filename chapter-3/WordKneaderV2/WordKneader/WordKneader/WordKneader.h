#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

const int scoreHint = 3;
const int NUM_WORDS = 5;

enum fields { WORD, HINT, NUM_FIELDS };

const string WORDS[NUM_WORDS][NUM_FIELDS] =
{
     {"wall", "Чувствуешь ли ты, что бьёшься головой о что-то?"},
     {"glasses", "Это поможет вам увидеть ответ на вопрос."},
     {"labored", "Слишком медленно, не так ли?"},
     {"persistent", "Продолжайте в том же духе!"},
     {"jumble", "В этом и заключается смысл игры."}
};

string permute(string jumble);
void greetings(string jumble);
string get_user_answer(istream& in = cin, ostream& out = cout);
void print_hint(string theHint, int score, bool& usedHint, ostream& out = cout);
void penalty(int score, int& score_used_hint);
void try_again(ostream& out = cout);
int action(string theWord, string theHint, istream& in = cin, ostream& out = cout);
void farewell(int score, ostream& out = cout);
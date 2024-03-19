#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;

const int Ã¿’_WRONG = 8;

void rn_seed_gen();
string get_word();
string get_init_soFar(string word);
void display_game_stat(string soFar, string used, int wrong, ostream& out = cout);
char get_user_var(string used, istream& in = cin, ostream& out = cout);
string get_upd_SoFar(string word, string soFar, char guess);
void game_start(string word, ostream& out = cout);

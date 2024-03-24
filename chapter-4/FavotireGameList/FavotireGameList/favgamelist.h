#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

enum actions { HELP, WATCH, ADD, DELETE, DELETE_ALL, QUIT };

void print_help();
string ask_user_game(string prompt, istream& input, ostream& output);
bool game_listed(vector<string>& gameList, string& game);
bool real_add_game(vector<string>& gameList, string& game);
bool real_delete_game(vector<string>& gameList, string& game);
void delete_all_games(vector<string>& gameList);
void add_game(vector<string>& gameList, istream& input = cin, ostream& output = cout);
void delete_game(vector<string>& gameList, istream& input = cin, ostream& output = cout);
void print_game_list(vector<string>& gameList, ostream& output = cout);

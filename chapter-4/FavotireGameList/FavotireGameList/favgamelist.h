#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

enum actions { WATCH = 1, ADD, DELETE, DELETE_ALL, HELP, QUIT };

void print_help();
void print_game_list(vector<string>gameList);
void add_game(vector<string>& gameList);
void delete_game(vector<string>& gameList);
void delete_all_games(vector<string>& gameList);

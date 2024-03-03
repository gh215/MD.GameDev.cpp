#pragma once
#include <iostream>

using namespace std;

enum answers { SMALL = 1, BIG, CORRECT };
const int border_min = 1;
const int border_max = 50;

void greeting();
int num_gen(int min, int max);
int ask_user(int cn, int min, int max);
void tell_guessed(int cn);
void bord_reduct(int cn, int uc, int &min, int &max);




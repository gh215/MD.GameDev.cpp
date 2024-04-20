#pragma once
#include <iostream>
using namespace std;

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0);
    void Talk(ostream& out = cout);
    int GetBoredom() const;
    int GetHunger() const;
    void Wait(ostream& out = cout);
    void ShowHunger(ostream& out = cout);
    void ShowBoredom(ostream& out = cout);
    void Eat(ostream& out = cout, int food = 4);
    void Play(ostream& out = cout, int fun = 4);
private:
    int m_Hunger;
    int m_Boredom;
    int GetMood() const;
    void PassTime(int time = 1);
};

void player_choice(Critter& crit, istream& in = cin, ostream& out = cout);
void help(ostream& out = cout);
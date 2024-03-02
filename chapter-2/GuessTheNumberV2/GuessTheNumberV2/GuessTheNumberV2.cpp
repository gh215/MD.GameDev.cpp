#include <iostream>
#include "gtn.h"

using namespace std;
void game()
{
    greeting();
    int min = border_min;
    int max = border_max;
    int comp_num;
    do
    {
        comp_num = num_gen(min, max);
        int user_cons = ask_user(comp_num);
        corr_check(user_cons, comp_num, min, max);
        if (user_cons == CORRECT)
        {
            break;
        }
        bord_reduct(comp_num, user_cons, min, max);
        if (min == max)
        {
            break;
        }

    } while (true);

    tell_guessed(comp_num);
}

int main()
{
    //Init random numbers
    game();
}


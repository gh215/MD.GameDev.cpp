#include "gtn.h"

using namespace std;
void game()
{
    greeting();
    int min = border_min;
    int max = border_max;
    do
    {
        int comp_num = num_gen(min, max);
        int user_cons = ask_user(comp_num, min, max);
        if (user_cons == CORRECT)
        {
            tell_guessed(comp_num);
            break;
        }
        bord_reduct(comp_num, user_cons, min, max);
        if (min == max)
        {
            tell_guessed(min);
            break;
        }

    } while (true);
}

int main()
{
    setlocale(0, "Russian");
    srand(static_cast<unsigned int>(time(0)));
    game();
}


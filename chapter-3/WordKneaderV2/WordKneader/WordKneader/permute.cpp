#include "WordKneader.h"
/* ����-�����
    1. ���� ������������ ������ ����� ��� ��������� - �� �������� ���������� �����, ������ ����� �����
    2. ���� ������������ ������ ����� � ����� ���������� - ����������, ������ ����� ����� ����� 3
    3. ���� ������ � ����������� ����������� - ����� ����������, ������ ����� ����� ����� 3
    4. ���� �� ������ - ��� ���������� �� ��� ���, ���� �� �� ����� quit
    */


int main()
{
    setlocale(0, "Russian");

    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];
    int score = 0;
    string jumble = theWord;
    jumble = permute(jumble);
    int score_used_hint = 0;
    bool usedHint = false;

    greetings(jumble, score);
    action(theWord, theHint, score, score_used_hint, usedHint);
    farewell(score);
    return 0;
}
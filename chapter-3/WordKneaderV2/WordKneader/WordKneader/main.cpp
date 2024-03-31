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
    string jumble = theWord;
    jumble = permute(jumble);

    greetings(jumble);
    int score = action(theWord, theHint);
    farewell(score);
    return 0;
}
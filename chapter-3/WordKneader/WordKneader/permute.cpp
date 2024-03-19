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

    enum fields { WORD, HINT, NUM_FIELDS };
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
         {"wall", "���������� �� ��, ��� ������� ������� � ���-��?"},
         {"glasses", "��� ������� ��� ������� ����� �� ������."},
         {"labored", "������� ��������, �� ��� ��?"},
         {"persistent", "����������� � ��� �� ����!"},
         {"jumble", "� ���� � ����������� ����� ����."}
    };

    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];
    int score = 0;
    string jumble = theWord;

    jumble = permute(jumble);
    int score_used_hint = 0;
    bool usedHint = false;

    intro(jumble, score);

    get_user_guess(theWord, theHint, usedHint, score_used_hint, score);

    cout << "������� �� ����! ��� ��� �����!";

    return 0;
}
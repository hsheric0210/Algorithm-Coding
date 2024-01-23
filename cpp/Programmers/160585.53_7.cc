#include <string>
#include <vector>
#include <iostream>

using namespace std;
string board;
vector<string>discreteCombination;

void initDiscreteTable()
{
    discreteCombination.push_back("OOOXXX...");
    discreteCombination.push_back("OOO...XXX");
    discreteCombination.push_back("...OOOXXX");
    discreteCombination.push_back("XXXOOO...");
    discreteCombination.push_back("XXX...OOO");
    discreteCombination.push_back("...XXXOOO");
    discreteCombination.push_back("OX.OX.OX.");
    discreteCombination.push_back("O.XO.XO.X");
    discreteCombination.push_back(".OX.OX.OX");
    discreteCombination.push_back("XO.XO.XO.");
    discreteCombination.push_back("X.OX.OX.O");
    discreteCombination.push_back(".XO.XO.XO");
}

// 1. '(O 개수) - (X 개수)'가 0 미만이거나 1 초과이면 트리거
bool checkCount()
{
    int o = 0, x = 0;
    for (auto c : board)
    {
        if (c == 'O')
            o++;
        else if (c == 'X')
            x++;
    }
    int delta = (o - x);
    return delta >= 0 && delta <= 1;
}

// 2. 전체를 검사하여 어느 쪽이라도 '서로 독립된(겹치는 부분 없는)' 3목 2개가 만들어졌다면 트리거
bool checkGameFinish()
{
    for (auto disc : discreteCombination)
    {
        for (int i = 0; i < 9; i++)
        {
            if (disc[i] != '.' && disc[i] != board[i])
            {
                goto next;
            }
        }
        return false;
        next: ;
    }
    return true;
}

int solution(vector<string> _board) {
    initDiscreteTable();
    string buf;
    buf.reserve(9);
    for (string s : _board)
        buf += s;
    board = buf;
    cout << "board is " << board << '\n';
    
    return checkCount() && checkGameFinish();
}
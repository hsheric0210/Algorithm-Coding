#include <string>
#include <vector>
#include <iostream>

using namespace std;
string board;
vector<string>cmb;

void initCombinations()
{
    cmb.push_back("XXX......");
    cmb.push_back("...XXX...");
    cmb.push_back("......XXX");
    cmb.push_back("X..X..X..");
    cmb.push_back(".X..X..X.");
    cmb.push_back("..X..X..X");
    cmb.push_back("X...X...X");
    cmb.push_back("..X.X.X..");
}

pair<int, int> countBoard()
{
    int o = 0, x = 0;
    for (auto c : board)
    {
        if (c == 'O')
            o++;
        else if (c == 'X')
            x++;
    }
    return make_pair(o, x);
}

bool checkWin(char ch)
{
    for (auto disc : cmb)
    {
        for (int i = 0; i < 9; i++)
        {
            if (disc[i] == 'X' && board[i] != ch)
            {
                goto nextcomb;
            }
        }
        return true;
        nextcomb: ;
    }
    return false;
}

int solution(vector<string> _board) {
    initCombinations();
    string buf;
    buf.reserve(9);
    for (string s : _board)
        buf += s;
    board = buf;
    cout << "board is " << board << '\n';
    
    auto cnt = countBoard();
    int delta = cnt.first - cnt.second;
    if (delta < 0 || delta > 1)
        return 0;
    
    int o = checkWin('O'), x = checkWin('X');
    cout << "O:" << o << ", X:" << x <<'\n';
    if (o && x) return 0; // 동시에 이길 수 없음
    
    if (o && delta != 1) return 0; // 'O'가 이길 경우, 개수 차이는 1
    if (x && delta != 0) return 0; // 'X'가 이길 경우, 개수 차이는 0
    return 1;
}
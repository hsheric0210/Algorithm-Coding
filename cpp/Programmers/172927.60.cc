#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> exhaustTable;
deque<int> minerals;

int parseMineral(string &mineral)
{
    if (mineral == "diamond")
        return 0;
    if (mineral == "iron")
        return 1;
    return 2;
}

int measureExhaustness(int pickType)
{
    int exhaust = 0;
    for (int i = 0, j = min<int>(5, minerals.size()); i < j; i++)
    {
        exhaust += exhaustTable[pickType][minerals[i]];
    }
    return exhaust;
}

// RGB거리식 다이나믹 또는 그냥 그리디
int solution(vector<int> picks, vector<string> _minerals) {
    // build exhaust table
    vector<int> diamondTbl;
    diamondTbl.push_back(1); // diamond pickaxe mine diamond
    diamondTbl.push_back(1); // diamond pickaxe mine iron
    diamondTbl.push_back(1); // diamond pickaxe mine stone
    vector<int> ironTbl;
    ironTbl.push_back(5); // iron pickaxe mine diamond
    ironTbl.push_back(1); // iron pickaxe mine iron
    ironTbl.push_back(1); // iron pickaxe mine stone
    vector<int> stoneTbl;
    stoneTbl.push_back(25); // stone pickaxe mine diamond
    stoneTbl.push_back(5); // stone pickaxe mine iron
    stoneTbl.push_back(1); // stone pickaxe mine stone
    exhaustTable.push_back(diamondTbl);
    exhaustTable.push_back(ironTbl);
    exhaustTable.push_back(stoneTbl);
    
    // convert mineral string to int
    for (string min : _minerals) minerals.push_back(parseMineral(min));
    
    int totalExhaust = 0;
    while(!minerals.empty())
    {
        vector<pair<int, int>>pairs;
        if (picks[2] > 0) // stone pickaxe avail.
            pairs.push_back({2, measureExhaustness(2)});
        if (picks[1] > 0) // iron pickaxe avail.
            pairs.push_back({1, measureExhaustness(1)});
        if (picks[0] > 0) // diamond pickaxe avail.
            pairs.push_back({0, measureExhaustness(0)});
        
        if (pairs.empty()) break; // 사용할 수 있는 곡괭이가 없다면 break
        // Find best pickaxe
        auto best = min_element(pairs.begin(), pairs.end(), [](auto a, auto b){ return a.second < b.second; });
        cout << "using pick=" << best->first << " exh=" << best->second << '\n';
        picks[best->first]--;
        totalExhaust += best->second;
        // 곡괭이 사용할 수 없을 때까지 사용
        for (int i = 0, j = min<int>(5, minerals.size()); i < j; i++) minerals.pop_front();
    }
    return totalExhaust;
}
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

vector<vector<int>> exhaustTable;
deque<vector<int>> mineralChunks;

int parseMineral(string &mineral)
{
    if (mineral == "diamond")
        return 0;
    if (mineral == "iron")
        return 1;
    return 2;
}

int solution(vector<int> picks, vector<string> mineralStrings) {
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
    
    int totalPickCount = accumulate(picks.begin(), picks.end(), 0); // 8번 테스트 케이스 : 전체 청크 수보다 곡괭이 수가 부족할 때
    
    // convert mineral string to int & split into 5-chunk's
    for (int chunkStart = 0, j = mineralStrings.size();
         chunkStart < j;
         chunkStart += 5)
    {
        vector<int> exhaust(3);
        for (int chunkIndex = 0;
             chunkIndex < 5 && chunkStart + chunkIndex < j;
             chunkIndex++)
        {
            auto min = parseMineral(mineralStrings[chunkStart + chunkIndex]);
            //cout << "chunk-index " << chunkStart + chunkIndex << '\n';
            for (int l = 0; l < 3; l++)
                exhaust[l] += exhaustTable[l][min];
        }
        cout << "chunk with exhaust 0=" << exhaust[0] << " 1=" << exhaust[1] << " 2=" << exhaust[2] << " with " << totalPickCount << "-th pick\n";
        mineralChunks.push_back(exhaust);
        if (!(--totalPickCount)) break; // 8번 테스트 케이스 : 전체 청크 수보다 곡괭이 수가 부족할 때
    }
    
    sort(mineralChunks.begin(), mineralChunks.end(), [](auto a, auto b){ return a[2] > b[2]; });
    
    int totalExhaust = 0;
    for (int pickType = 0; pickType < 3; pickType++) // dia, iron, stone 곡괭이 순서
    {
        for (int pickCount = 0, l = picks[pickType]; pickCount < l; pickCount++)
        {
            totalExhaust += mineralChunks.front()[pickType];
            mineralChunks.pop_front();
            if (mineralChunks.empty())
                goto end;
        }
    }
    end:
    
    return totalExhaust;
}
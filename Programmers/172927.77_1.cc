#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

struct MineralChunk {
    int cost, exhaust[3];
};

vector<vector<int>> exhaustTable;
deque<MineralChunk> mineralChunks;

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
    
    // convert mineral string to int & split into 5-chunk's
    for (int chunkStart = 0, j = mineralStrings.size();
         chunkStart < j;
         chunkStart += 5)
    {
        int score = 0;
        int exhaust[3] = {0};
        for (int chunkIndex = 0;
             chunkIndex < 5 && chunkStart + chunkIndex < j;
             chunkIndex++)
        {
            auto min = parseMineral(mineralStrings[chunkStart + chunkIndex]);
            //cout << "chunk-index " << i+k << '\n';
            score += 4 - min;
            for (int l = 0; l < 3; l++)
                exhaust[l] += exhaustTable[l][min];
        }
        //cout << "score " << score << " chunk with exhaust " << exhaust[2] << '\n';
        MineralChunk ch = {score, {exhaust[0], exhaust[1], exhaust[2]}};
        mineralChunks.push_back(ch);
    }
    
    sort(mineralChunks.begin(), mineralChunks.end(), [](auto a, auto b){ return a.cost > b.cost; });
    
    int totalExhaust = 0;
    for (int pickType = 0; pickType < 3; pickType++)
    {
        for (int pickCount = 0, l = picks[pickType]; pickCount < l; pickCount++)
        {
            auto &chunk = mineralChunks.front();
            mineralChunks.pop_front();
            //cout << "using score " << chunk.cost << " chunk with exhaustness " << chunk.exhaust[pickType] << " with pick " << pickType << '\n';
            totalExhaust += chunk.exhaust[pickType];
        }
    }
    
    return totalExhaust;
}
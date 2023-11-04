#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_map>

using namespace std;

int parseTime(string time)
{
    return stoi(time.substr(0, 2)) * 3600 + stoi(time.substr(3, 2));
}

vector<string> solution(vector<vector<string>> plans) {
    map<string, int> tt; // build a task-time mapping
    for (auto a : plans)
        tt.insert({a[0], parseTime(a[0])});
    
    // sort all tasks by time (ascending)
    sort(plans.begin(), plans.end(), [](auto a, auto b){return tt[a[0]] < tt[b[0]];});
    
    deque<vector<string>>q;
    deque<pair<string, int>>waitq;
    q.push_back(plans.front());
    while(!q.empty())
    {
        auto fr = q.front();
        int frS = tt[fr[0]]; // task_start
        int frD = stoi(fr[2]); // task_duration
        if (q.size() > 1)
        {
            auto next = q[1];
            auto nextS = tt[next[0]]; // next_task_start
            if (frS+frD < nextS && !waitq.empty()) // 이전 작업과 다음 작업 사이에 약간의 텀이 있고, 대기 중인 작업 존재
            {
                auto waitb = waitq.back();
                int term = nextS - (frS+frD); // 작업 사이 시간
                waitb.second -= term;
                if (waitb.second <= 0) // 만약 대기 중인 작업 완료했다면, pop
                    waitb.pop_back();
            }
            else if (frS+frD > next[1]) // 이전 작업 종료 전에 새로운 작업 실행 필요
            {
                waitq.push_back(fr[0], frS+frD - nextS); // 대기 큐에 작업명과 남은 시간 push
            }
        }
    }
    vector<string> answer;
    return answer;
}

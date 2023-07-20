#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_map>
#include <tuple>
#include <iostream>

using namespace std;

#define PTUPLE tuple<string, int, int>
#define PNAME get<0>
#define PSTART get<1>
#define PDURATION get<2>

#define WQTUPLE tuple<string, int>
#define WQNAME get<0>
#define WQDURATION get<1>

int parseTime(string time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

vector<string> solution(vector<vector<string>> _plans) {
    // parse and rebuild
    deque<PTUPLE> plans; // note that this is FIFO (not LILO!) queue
    for (auto a : _plans)
        plans.push_back({a[0], parseTime(a[1]), stoi(a[2])});
    
    // sort all tasks by time (ascending)
    sort(plans.begin(), plans.end(), [](auto a, auto b){return PSTART(a) < PSTART(b);});
    plans.push_back({"dummy",1440,0}); // dummy last element
    
    PTUPLE next;
    vector<string> answer;
    deque<WQTUPLE>waitq;
    while(!plans.empty())
    {
        auto prev = plans.front();
        plans.pop_front();
        if (plans.size()>0)
        {
            next = plans.front();
            cout << "prev=" << PNAME(prev) << " next=" << PNAME(next) << '\n';
            cout << "next_start=" << PSTART(next) << " prev_end=" << (PSTART(prev) + PDURATION(prev)) <<'\n';
            int td = PSTART(next) - (PSTART(prev) + PDURATION(prev)); // time_delta: 이전 작업 완료 시간과 다음 작업 시작 시간 사이 텀
            if (td >= 0) // 작업이 겹치지 않을 경우, 이전 작업 완료 처리
                answer.push_back(PNAME(prev));
            
            if (td > 0) // 자투리 시간 발생
            {
                cout << "term between prev=" << PNAME(prev) << " next=" << PNAME(next) << " is " << td << '\n';
                while(!waitq.empty() && td>0) // 대기열에 있는 작업들 남는 시간동안 실행
                {
                    auto wf = waitq.front();
                    int tRemDura = WQDURATION(wf) - td; // task_remaining_duration: 작업의 남은 처리 시간 (음수일 수 있음)
                    if (tRemDura <= 0) // 만약 작업이 완료되었다면 대기열에서 제거
                    {
                        cout << "finished " << WQNAME(wf) << " @ term between prev=" << PNAME(prev) << " and next=" << PNAME(next) << '\n';
                        answer.push_back(WQNAME(wf));
                        waitq.pop_front();
                        cout << "rem_termDura -= " << WQDURATION(wf) << " => td=" << td << '\n';
                    }
                    else
                    {
                        cout << "work on " << WQNAME(wf) << " @ term between prev=" << PNAME(prev) << " and next=" << PNAME(next) << '\n';
                        WQDURATION(wf) = tRemDura; // 남은 텀 시간 안에 완료하지 못했다면, 다시 남은 처리 시간 업데이트
                        cout << "Rem_time of " << WQNAME(wf) << " is " << tRemDura << " and term is end.\n";
                    }
                    td -= WQDURATION(wf);
                }
            }
            else if (td < 0) // 다음 작업이 이전 작업 완료 전에 시작
            {
                cout << "unfinished prev=" << PNAME(prev) << " next=" << PNAME(next) << " prev_remain=" << -td << '\n';
                waitq.push_front({PNAME(prev), -td}); // '-td': 이전 작업의 남은 작업 시간
            }
        }
    }
    
    while(!waitq.empty())
    {
        auto fr = waitq.front();
        waitq.pop_front();
        answer.push_back(WQNAME(fr));
    }
    return answer;
}

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Machine {
    long long EndTime;
    int Index;

    bool operator<(const Machine& other) const
    {
        if (EndTime == other.EndTime) return Index > other.Index;
        return EndTime > other.EndTime;
    }
};


vector<int> solution(int N, vector<int> coffee_times) {
    vector<int> answer;

    priority_queue<Machine> PQ;

    for (int i = 0; i < min(N, (int)coffee_times.size()); ++i)
    {
        PQ.push({ coffee_times[i], i + 1 });
    }

    int CurrentOrder = N;
    while (PQ.empty() == false)
    {
        Machine Current = PQ.top();
        PQ.pop();
        answer.push_back(Current.Index);

        if (CurrentOrder < coffee_times.size())
        {
            PQ.push({ Current.EndTime + coffee_times[CurrentOrder], CurrentOrder + 1 });
            ++CurrentOrder;
        }
    }

    return answer;
}
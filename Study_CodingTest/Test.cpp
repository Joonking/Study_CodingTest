#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    // 각 건물에 먼저 지어야 할 건물들
    vector<vector<int>> BuildNet(N + 1);
    // 건물 각각의 건설 시간
    vector<int> SelfBuild(N + 1);
    // 위상정렬에 사용할 진입 차수
    vector<int> Degree(N + 1);
    // 각 건물이 완성되는 시간을 기록할 배열
    vector<int> Ans(N + 1);

    // 입력 처리
    for (int i = 1; i <= N; i++)
    {
        int Time;
        cin >> Time;
        SelfBuild[i] = Time;

        while (true)
        {
            int NeedBuilding;
            cin >> NeedBuilding;
            if (NeedBuilding == -1)
                break;

            BuildNet[NeedBuilding].push_back(i);
            Degree[i]++;
        }
    }

    // 큐를 사용한 위상 정렬
    queue<int> Queue;
    for (int i = 1; i <= N; i++)
    {
        if (Degree[i] == 0)
        {
            Queue.push(i);
            Ans[i] = SelfBuild[i]; // 처음에는 자기 자신의 건설 시간을 초기값으로 설정
        }
    }

    // 위상정렬 진행
    while (!Queue.empty())
    {
        int Front = Queue.front();
        Queue.pop();

        for (int i : BuildNet[Front])
        {
            Degree[i]--;
            // i번 건물의 완료 시간을 갱신 (이전 건물의 완료 시간 + 현재 건물의 건설 시간)
            Ans[i] = max(Ans[i], Ans[Front] + SelfBuild[i]);
            if (Degree[i] == 0)
            {
                Queue.push(i);
            }
        }
    }

    // 최종 결과 출력
    for (int i = 1; i <= N; i++)
    {
        cout << Ans[i] << "\n";
    }

    return 0;
}

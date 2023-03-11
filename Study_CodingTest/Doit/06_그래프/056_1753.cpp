//056_1753 최단 경로 구하기

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //V: 노드 개수, E: 에지 개수, K:출발 노드
    int V, E, K;
    cin >> V >> E >> K;

    typedef pair<int, int> edge;

    //mlist : 그래프 정보 저장 인접 리스트
    vector<vector<edge>> mlist(V + 1);
    //mdistance : 최단거리 정보 저장.
    vector<int> mdistance(V+1, INT_MAX);
    //visited : 방문 여부
    vector<bool> visited(V + 1, false);

    // 가중치가 있는 인접 리스트 초기화
    for(int i=0;i<E;i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mlist[u].push_back({v,w});
    }

    //자동으로 거리가 최소인 노드를 선택하게끔 우선순위 큐를 사용.
    priority_queue<edge, vector<edge>, greater<edge>> q;

	//큐에 첫번째 출발 노드를 넣어줌.
    q.push({0,K});
    //K번째 최단거리 0으로 만들기
    mdistance[K] = 0;

    while (!q.empty()) {
        edge current = q.top();
        q.pop();
        int c_v = current.second;
        if (visited[c_v]) continue; // 기 방문 노드는 다시 큐에 넣지 않습니다.
        visited[c_v] = true;
        for (int i = 0; i < mlist[c_v].size(); i++) {
            edge tmp = mlist[c_v][i];
            int next = tmp.first;
            int value = tmp.second;
            if (mdistance[next] > mdistance[c_v] + value) { // 최소 거리로 업데이트
                mdistance[next] = value + mdistance[c_v];
                q.push(make_pair(mdistance[next], next));
            }
        }
    }

    for (int i = 1; i <= V; i++) { // 거리 배열 출력
        if (visited[i])
            cout << mdistance[i] << "\n";
        else
            cout << "INF" << "\n";
    }

}







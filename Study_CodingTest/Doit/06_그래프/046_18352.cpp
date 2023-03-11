//046A_18352 특정 거리의 도시 찾기

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void BFS(vector<vector<int>> &nodes, vector<int> &visited, int node)
{
	queue<int> Queue;
	//시작 지점 노드를 우선 큐에 넣어줌.
	Queue.push(node);
	visited[node]++;  //시작 지점 방문 기록 ++

	while (!Queue.empty())  //Queue가 빌때까지 while
	{
		//현재 탐색할 노드는 큐의 제일 앞에 노드
		int now_node = Queue.front();
		Queue.pop(); //제일 앞에 노드 빼주기

		//현재 노드에 연결되어 있는 애들을 확인
		for (int i : nodes[now_node])
		{
			//연결되어 있는 노드가 방문한 적이 없던 노드라면
			if (visited[i] == -1)
			{
				Queue.push(i);
				//이전 노드의 방문 값에 +1 한 값을 방문에 넣어줌.
				visited[i] = visited[now_node] + 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//N : 도시 수, M : 에지 수, K : 거리, X : 시작 도시
	int N, M, K, X;
	cin >> N >> M >> K >> X;

	//Nodes : 도시의 인접 리스트를 담은 배열
	vector<vector<int>> Nodes(N+1);
	//Visited : 도시의 방문 기록 배열
	//(시작 지점으로 부터의 거리를 담을거임)
	vector<int> Visited(N + 1);

	for (int i = 0; i < N + 1; i++)
	{
		Visited[i] = -1;  //모두 -1로 초기화
	}

	for (int i = 0; i < M; i++)
	{
		int tempA, tempB;
		cin >> tempA >> tempB;
		Nodes[tempA].push_back(tempB);
	}

	BFS(Nodes, Visited, X);

	vector<int> answer;

	for (int i =1; i<Visited.size();i++)
	{
		if (Visited[i] == K)
		{
			answer.push_back(i);
		}
	}

	sort(answer.begin(), answer.end());

	if (answer.empty())
		cout << -1 << "\n";
	else
	{
		for (int i : answer)
			cout << i << "\n";
	}
	

}

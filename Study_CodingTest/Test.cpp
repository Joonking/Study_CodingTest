#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void BFS(const vector<vector<int>>& List, vector<bool>& VisitedList, int Num)
{
	queue<int> Queue;
	Queue.push(Num);

	while (Queue.empty() == false)
	{
		int Front = Queue.front();
		Queue.pop();
		
		for (int i : List[Front])
		{
			if (VisitedList[i] == false)
			{
				VisitedList[i] = true;
				Queue.push(i);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> NodeList(N+1);

	for (int i = 0; i < M; i++)
	{
		int TempA, TempB;
		cin >> TempA >> TempB;
		NodeList[TempA].push_back(TempB);
		NodeList[TempB].push_back(TempA);
	}

	vector<bool> Visited(N + 1, false);

	int Count = 0;
	for (int i = 1; i <= N; i++)
	{
		if (Visited[i] == false)
		{
			BFS(NodeList, Visited, i);
			Count++;
		}
	}

	cout << Count;

	return 0;
}
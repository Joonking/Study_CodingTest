#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Now[3];
bool Answer[201];
bool Visited[201][201];

//A,B,C의 이동을 표현
// [0, 1] : 보내는쪽 A(0) -> 받는쪽 B(1)
// [0, 2] : 보내는쪽 A(0) -> 받는쪽 C(2)
// [1, 0] : 보내는쪽 B(1) -> 받는쪽 A(0)
// [1, 2] : 보내는쪽 B(1) -> 받는쪽 C(2)
// [2, 0] : 보내는쪽 C(2) -> 받는쪽 A(0)
// [2, 1] : 보내는쪽 C(2) -> 받는쪽 B(1)
int Sender[] = { 0,0,1,1,2,2 };  //보내는쪽
int Receiver[] = { 1,2,0,2,0,1 };  //받는 쪽

void BFS()
{
	queue<pair<int, int>> Queue;
	Queue.push({ 0,0 });
	Visited[0][0] = true;
	Answer[Now[2]] = true;

	while (Queue.empty() == false)
	{
		pair<int, int> front = Queue.front();
		Queue.pop();
		int A = front.first;
		int B = front.second;
		int C = Now[2] - A - B;

		for (int i = 0; i < 6; i++)
		{
			int Next[] = { A, B, C };
			Next[Receiver[i]] += Next[Sender[i]];
			Next[Sender[i]] = 0;

			if (Next[Receiver[i]] > Now[Receiver[i]])
			{
				Next[Sender[i]] = Next[Receiver[i]] - Now[Receiver[i]];
				Next[Receiver[i]] = Now[Receiver[i]];
			}

			if (Visited[Next[0]][Next[1]] == false)
			{
				Visited[Next[0]][Next[1]] = true;
				Queue.push({ Next[0], Next[1]});
				if (Next[0] == 0)
					Answer[Next[2]] = true;
			}

		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> Now[0] >> Now[1] >> Now[2];
	BFS();

	for (int i = 0; i < 201; i++)
	{
		if (Answer[i])
			cout << i << " ";
	}

	return 0;
}
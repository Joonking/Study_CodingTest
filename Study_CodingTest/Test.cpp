#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

static vector<vector<int>> tree;
static vector<bool> visited;
static int answer = 0;
static int deleteNode = 0;

void DFS(int num);

int main()
{
	//cin, cout 시간단축
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	tree.resize(N);
	visited.resize(N);

	int root = 0;

	for(int i=0; i<N;i++)
	{
		int p;
		cin >> p;

		if(p==-1)
		{
			root = i;
		}
		else
		{
			tree[i].push_back(p);
			tree[p].push_back(i);
		}
	}

	cin >> deleteNode;

	if (deleteNode == root)
		cout << 0;
	else
	{
		DFS(root);
		cout << answer;
	}
}

void DFS(int num)
{
	visited[num] = true;

	int cNode = 0;

	for(int i : tree[num])
	{
		if (!visited[i] && deleteNode != i)
		{
			cNode++;
			DFS(i);
		}
	}
	if (cNode == 0)
		answer++;
}



//디버깅 설정
//<input.txt>output.txt


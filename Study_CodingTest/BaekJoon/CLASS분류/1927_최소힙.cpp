#include <iostream>
#include <queue>

using namespace std;

int N;

priority_queue<int, vector<int>, greater<int>> P_Queue;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		if (temp == 0)
		{
			if (P_Queue.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << P_Queue.top() << "\n";
				P_Queue.pop();
			}
		}
		else
		{
			P_Queue.push(temp);
		}
	}


}
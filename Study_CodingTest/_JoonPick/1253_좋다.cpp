#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	int count = 0;

	for (int i = 0; i < N; i++)
	{
		int val = arr[i];
		int left = 0, right = N - 1;
		while (left < right)
		{
			int sum = arr[left] + arr[right];
			if (sum == val)
			{
				if (left != i && right != i)
				{
					count++;
					break;
				}
				else if (left == i) left++;
				else if (right == i) right--;
			}
			else if (sum < val) left++;
			else if (sum > val) right--;
		}
	}

	cout << count << "\n";
}





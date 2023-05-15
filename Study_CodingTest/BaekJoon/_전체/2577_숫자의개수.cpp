#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	long long sum = A * B * C;
	string an = to_string(sum);

	int answer[10] = { 0 };

	for (char a : an)
	{
		answer[a - '0']++;
	}

	for (int i = 0;i<=9;i++)
	{
		cout << answer[i] << endl;
	}
}





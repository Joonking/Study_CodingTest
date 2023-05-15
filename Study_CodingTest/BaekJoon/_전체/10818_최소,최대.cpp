#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, Min = INT_MAX, Max = INT_MIN, t;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		if (t < Min) Min = t;
		if (t > Max) 	Max = t;
	}
	cout << Min << " " << Max;
}
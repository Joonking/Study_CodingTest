//02. 10871번 문제 (X보다 작은 수)

#include <iostream>
using namespace std;
int main()
{
	int N, X, A;
	cin >> N >> X;

	for (int i = 0; i < N; i++)
	{
		cin >> A;
		if (A < X)
			cout << A << " ";
	}
}
//04. 25304번 문제 (영수증)

#include <iostream>
using namespace std;
int main()
{
	int X, N, a, b, sum=0;
	cin >> X >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		sum += a * b;
	}
	X == sum ? cout << "Yes" : cout << "No";
}
//09. 2439번 문제 (별 찍기-2)

#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int k = N-i; k > 0; k--)
			cout << " ";
		for (int j = 1; j <= i; j++)
			cout << "*";
		cout << endl;
	}
}
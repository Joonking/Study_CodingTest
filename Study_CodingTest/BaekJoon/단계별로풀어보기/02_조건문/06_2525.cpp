//06. 2525번 문제 (오븐 시계)

#include <iostream>
using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	B += C;
	A += B / 60;
	cout << A % 24 << " " << B % 60;
}
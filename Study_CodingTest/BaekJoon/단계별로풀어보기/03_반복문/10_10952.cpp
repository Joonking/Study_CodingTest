//10. 10952번 문제 (A+B-5)

#include <iostream>
using namespace std;
int main()
{
	int A, B;

	while (true)
	{
		cin >> A >> B;
		if (A == 0 && B == 0)
			break;
		cout << A + B << "\n";
	}
}
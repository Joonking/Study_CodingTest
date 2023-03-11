//03. 2753번 문제 (윤년)

#include <iostream>
using namespace std;

int main()
{
	int y;
	cin >> y;
	if ((y%4 == 0 && y%100 != 0) || y%400 == 0)
		cout << 1;
	else
		cout << 0;
}
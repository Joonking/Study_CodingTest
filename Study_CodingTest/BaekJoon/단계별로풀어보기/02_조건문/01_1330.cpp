//01. 1330번 문제 (두 수 비교하기)

#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	a > b ? cout << ">" : a < b ? cout << "<" : cout << "==";
}
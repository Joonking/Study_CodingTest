#include <iostream>
using namespace std;

static int num[5];

void gum()
{
	int a=0;
	for (int i : num)
	{
		a += i * i;
	}
	cout << a % 10;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++)
	{
		int temp;
		cin >> temp;
		num[i] = temp;
	}
	gum();


}
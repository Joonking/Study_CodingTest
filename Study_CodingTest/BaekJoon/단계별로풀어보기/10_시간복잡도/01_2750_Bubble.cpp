//01_2750_Bubble 수 정렬하기(버블정렬)

#include <iostream>
using namespace std;

int main() {

	int n, a[1000], t;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
}
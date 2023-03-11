//01_2750_Sort 수 정렬하기(sort)

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, v[1000];
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v, v + n);

	for (int i=0;i<n;i++)
		cout << v[i] << endl;

}

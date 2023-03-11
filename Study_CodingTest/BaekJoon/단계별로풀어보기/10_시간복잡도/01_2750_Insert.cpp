//01_2750_Insert 수 정렬하기(삽입정렬)

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, t;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		v.push_back(t);
	}

	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1] <= v[i])
			continue;

		int temp = v[i];

		for (int k = 0; k < i; k++)
		{
			if (v[k] > temp)
			{
				v.erase(v.begin()+i);   //i번째 요소 삭제
				v.insert(v.begin() + k, temp);  //k번째에 temp 값 삽입
				break;
			}
		}
	}

	for (int i=0;i<n;i++)
		cout << v[i] << endl;

}

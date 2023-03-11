#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void heapSort(vector<int>& arr)
{
	priority_queue<int> h;
	//오름차순으로 정렬하려면 
	//push, top 할때 앞에 -를 붙여줘야함.
	for (int i = 0; i < arr.size(); i++)
		h.push(-arr[i]);

	while (!h.empty())
	{
		cout << -h.top() << "\n";
		h.pop();
	}
}


int main() 
{
	int N;
	cin >> N;
	
	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	heapSort(arr);
}




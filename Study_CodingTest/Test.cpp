#include <iostream>
#include <string>

using namespace std;
int main() {

	string N, M;
	cin >> N >> M;

	int a = stoi(N, nullptr, 16);
	int b = stoi(M, nullptr, 16);

	int sum = a + b;

	cout << hex << sum;
}
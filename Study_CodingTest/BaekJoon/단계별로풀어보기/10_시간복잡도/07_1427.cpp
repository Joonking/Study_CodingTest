//07_1427 소트인사이드

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string str;
	cin >> str;
	
	sort(str.begin(), str.end(), greater<char>());

	for (char c : str)
		cout << c;


}
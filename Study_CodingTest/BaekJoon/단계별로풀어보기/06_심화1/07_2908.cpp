//07_2908 상수

#include <iostream>
#include <string>

using namespace std;

int main() {

	string s, t, s2, t2;
	cin >> s >> t;

	for (int i= s.size() -1; i>=0;i--)
		s2.push_back(s[i]);

	for (int i = t.size() - 1; i >= 0; i--)
		t2.push_back(t[i]);

	if (stoi(s2) > stoi(t2))
		cout << s2;
	else
		cout << t2;
}
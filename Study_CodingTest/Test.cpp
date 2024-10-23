#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<string> Ans;
	while (true)
	{
		string s;
		getline(cin, s);
		if (s.empty())
			break;
		Ans.push_back(s.substr(0, 5));
	}

	for (string s : Ans)
		cout << s << "\n";


	return 0;
}
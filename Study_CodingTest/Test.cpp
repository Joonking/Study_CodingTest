#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    map<string, string, greater<string>> StrMap;

    while (n--)
    {
        string Name;
        string Check;
        cin >> Name >> Check;
        StrMap[Name] = Check;
    }

    for (auto s : StrMap)
    {
        if (s.second == "enter")
            cout << s.first << "\n";
    }

    return 0;
}
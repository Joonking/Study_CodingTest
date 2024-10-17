#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<int, int> UnOrderMap;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        UnOrderMap[temp]++;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        cout << UnOrderMap[temp] << " ";
    }

    return 0;
}
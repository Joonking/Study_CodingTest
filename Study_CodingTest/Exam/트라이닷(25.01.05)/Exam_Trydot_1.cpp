#include <string>
#include <vector>

using namespace std;

vector<vector<int>> DP;

int Count(int n, int m, int Open, int Close)
{
    if (Open == n && Close == m) return 1;

    if (Open > n || Close > m)return 0;

    if (DP[Open][Close] != -1) return DP[Open][Close];

    int AddOpen = Count(n, m, Open + 1, Close);
    int AddClose = Count(n, m, Open, Close + 1);

    DP[Open][Close] = AddOpen + AddClose;
    return DP[Open][Close];
}

int solution(int n, int m) {
    int answer = 0;

    DP.assign(n + 1, vector<int>(m + 1, -1));

    answer = Count(n, m, 0, 0);

    return answer;
}
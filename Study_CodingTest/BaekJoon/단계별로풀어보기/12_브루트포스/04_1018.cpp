//04_1018 체스판 다시 칠하기

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};

string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

string board[50];

int WB_Count(int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int k = 0; k < 8; k++)
        {
            if (board[x + i][y + k] != WB[i][k])
                count++;
        }
    }
    return count;
}

int BW_Count(int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int k = 0; k < 8; k++)
        {
            if (board[x + i][y + k] != BW[i][k])
                count++;
        }
    }
    return count;
}

int main()
{
    int size[2];
    int cnt;
    int min_val = 12345;
    pair<int, int> p1;
    cin >> p1.first >> p1.second;
    for (int i = 0; i < p1.first; i++)
        cin >> board[i];
    for (int i = 0; i + 8 <= p1.first; i++)
    {
        for (int j = 0; j + 8 <= p1.second; j++)
        {
            int tmp;
            tmp = min(WB_Count(i, j), BW_Count(i, j));
            if (tmp < min_val) {
                min_val = tmp;
            }
        }
    }
    cout << min_val;
    return 0;
}
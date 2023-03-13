#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

int n = 3;
vector<vector<int>> facility = {{1,3,1},{3,1,1}};
int map[101][101]; // 각 칸의 접근 비용을 저장할 배열

// 두 점 사이의 거리를 계산하는 함수
int calcDist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {

    // 시설이 있는 칸의 접근 비용 계산
    for (int i = 0; i < n * n; i++) {
        int row = i / n + 1;
        int col = i % n + 1;

        int max_cost = 0;
        for (int j = 0; j < facility.size(); j++) {
            int facility_row = facility[j][0];
            int facility_col = facility[j][1];
            int facility_importance = facility[j][2];

            int dist = calcDist(row, col, facility_row, facility_col);
            int cost = dist * facility_importance;
            max_cost = max(max_cost, cost);
        }
        map[row][col] = max_cost;
    }

    // 최소 접근 비용을 가지는 칸 찾기
    int min_cost = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] < min_cost) {
                min_cost = map[i][j];
            }
        }
    }

    cout << min_cost << endl;
    return 0;
}
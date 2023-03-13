#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int solution(vector<string> board) {
    int answer = 0;
    int n = board.size();

    while (true) {
        bool removed = false;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        // BFS를 사용하여 제거할 블록을 찾음
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != ' ' && !visited[i][j]) {
                    vector<pair<int, int>> blocks;
                    char color = board[i][j];

                    q.push(make_pair(i, j));
                    visited[i][j] = true;

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        blocks.push_back(make_pair(x, y));

                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                            if (board[nx][ny] != color) continue;
                            if (visited[nx][ny]) continue;

                            q.push(make_pair(nx, ny));
                            visited[nx][ny] = true;
                        }
                    }

                    // 제거할 블록이 있는 경우
                    if (blocks.size() >= 2) {
                        removed = true;

                        for (auto p : blocks) {
                            board[p.first][p.second] = ' ';
                        }
                    }
                }
            }
        }

        // 제거할 블록이 없는 경우 반복문 탈출
        if (!removed) break;

        // 제거된 블록 자리를 빈 칸으로 채움
        for (int j = 0; j < n; j++) {
            vector<char> colors;

            for (int i = n - 1; i >= 0; i--) {
                if (board[i][j] != ' ') {
                    colors.push_back(board[i][j]);
                    board[i][j] = ' ';
                }
            }

            int idx = n - 1;

            for (auto color : colors) {
                board[idx--][j] = color;
            }
        }
    }

    // 빈 칸 개수 세기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == ' ') answer++;
        }
    }

    return answer;
}


int main()
{
    vector<string> board1= { "ABBBBC", "AABAAC", "BCDDAC", "DCCDDE", "DCCEDE", "DDEEEB" };
    vector<string> board2 = { "DDCCC", "DBBBC", "DBABC", "DBBBC", "DDCCC" };

    cout << solution(board1) << "\n";
    cout << solution(board2) << "\n";

}
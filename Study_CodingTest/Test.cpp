#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string M;
    cin >> M;

    int Q;
    cin >> Q;

    // 매듭 쌍 찾기
    vector<pair<int, int>> starRanges;
    stack<int> starStack;

    for (int i = 0; i < N; i++) {
        if (M[i] == '*') {
            if (!starStack.empty()) {
                int start = starStack.top(); starStack.pop();
                starRanges.emplace_back(start, i);
            }
            else {
                starStack.push(i);
            }
        }
    }

    // Prefix Sum 구성
    vector<int> prefixSum(N + 1, 0);
    for (int i = 0; i < N; i++) {
        if (M[i] >= '0' && M[i] <= '9') {
            prefixSum[i + 1] = prefixSum[i] + (M[i] - '0');
        }
        else {
            prefixSum[i + 1] = prefixSum[i];
        }
    }

    // 쿼리 처리
    for (int q = 0; q < Q; q++) {
        int S, E;
        cin >> S >> E;

        int sum = 0;
        for (auto& p : starRanges) {
            if (p.first >= S && p.second <= E) {
                sum += prefixSum[p.second] - prefixSum[p.first + 1];
            }
        }
        cout << sum << '\n';
    }

    return 0;
}

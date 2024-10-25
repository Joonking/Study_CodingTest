#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    vector<int> jumps(N);
    
    for (int i = 0; i < N; i++) 
    {
        cin >> jumps[i];
    }

    int Sum = 0;
    int MinSum = 0;

    for (int i : jumps)
    {
        Sum += i;
        MinSum = min(MinSum, Sum);
    }

    cout << 1 - MinSum;

    return 0;
}

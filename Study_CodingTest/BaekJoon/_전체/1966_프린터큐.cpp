#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M;
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        
        queue<pair<int, bool>> Queue;   //프린트 큐
        vector<int> arr(N);                     //중요도를 담을 배열
        vector<pair<int, bool>> answer;

        for (int j = 0; j < N; j++)
        {
            int tempA;
            cin >> tempA;
            arr[j] = tempA;         //중요도 배열에 넣기
            if (j == M)
                Queue.push(make_pair(tempA, true));         //찾을 숫자.
            else
                Queue.push(make_pair(tempA, false));
        }

        sort(arr.begin(), arr.end(), greater<int>());   //중요도 내림차순 정렬

        for (int k = 0; k < arr.size(); k++)
        {
            while(!Queue.empty())
            {
                if (Queue.front().first == arr[k])
                {
                    answer.push_back(Queue.front());
                    Queue.pop();
                    break;
                }
                else
                {
                    Queue.push(Queue.front());
                    Queue.pop();
                }
            }
        }

        for (int t = 0; t < answer.size(); t++)
        {
            if (answer[t].second)
                cout << t+1 << endl;
        }
        
    }

   
}

// 최신 코드
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> PrintQueue;
        priority_queue<int> PQ;

        for (int i = 0; i < N; i++)
        {
            pair<int, int> Node;
            cin >> Node.first;
            Node.second = i;

            PrintQueue.push(Node);
            PQ.push(Node.first);
        }
        int Order = 0;
        while (PrintQueue.empty() == false)
        {
            pair<int, int> FrontNode = PrintQueue.front();
            PrintQueue.pop();
            if (FrontNode.first < PQ.top())
            {
                PrintQueue.push(FrontNode);
            }
            else if (FrontNode.first == PQ.top())
            {
                if (FrontNode.second == M)
                {
                    cout << ++Order << "\n";
                    break;
                }
                else
                {
                    PQ.pop();
                    Order++;
                }
            }
        }

    }

    return 0;
}






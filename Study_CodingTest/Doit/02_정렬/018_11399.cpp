//018_11399 ATM 인출 시간 계산하기(삽입정렬)

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);     //사람들의 각 인출 시간을 저장
    vector<int> S(N, 0);    //A의 합배열 S[i] = S[i-1] + A[i]

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    //삽입정렬
    for (int i = 1; i < N; i++)
    {
        int insert_point = i;
        int insert_value = A[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (A[j] < A[i])
            {
                insert_point = j + 1;
                break;
            }
            if (j == 0)
            {
                insert_point = 0;
            }
        }
        for (int j = i; j > insert_point; j--)
        {
            A[j] = A[j - 1];
        }
        A[insert_point] = insert_value;
    }

    //합 배열 만들기
    S[0] = A[0];
    for (int i = 1; i < N; i++)
        S[i] = S[i - 1] + A[i];

    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += S[i];

    cout << sum;
}





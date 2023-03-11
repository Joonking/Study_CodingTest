//011_1874 스택 수열

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;                      //수열 개수
    vector<int> A(N, 0);        //수열 저장 배열
    vector<char> resultV;    //결과 저장 배열

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    stack<int> myStack;
    int num = 1;  //오름차순 수
    bool result = true;

    for (int i = 0; i < A.size(); i++)
    {
        int su = A[i];   //현재 수열의 수

        //현재 수열값 >= 오름차순 자연수 : 값이 같아질때까지 push() 수행
        if (su >= num)
        {
            while (su >= num)
            {
                myStack.push(num++);
                resultV.push_back('+');  //결과 값에 + 추가
            }
            myStack.pop();  //맨 위에꺼 하나 출력
            resultV.push_back('-');  //출력하기 위한 - 결과 값에 추가.
        }
        //현재 수열값 < 오름차순 자연수 : pop()을 수행해서 수열 원소를 꺼냄.
        else
        {
            int n = myStack.top();
            myStack.pop();
            //스택의 가장 위의 수가 만들어야 하는 수열의 수보다 크다면 수열 출력 불가
            if (n > su)
            {
                cout << "NO";
                result = false;
                break;
            }
            else
            {
                resultV.push_back('-');
            }
        }
    }
    if (result)
    {
        for (int i = 0; i < resultV.size(); i++)
        {
            cout << resultV[i] << "\n";
        }
    }
}
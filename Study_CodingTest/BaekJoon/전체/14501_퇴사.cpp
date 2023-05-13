//D[i]  : i번째 날부터 퇴사일까지 벌 수 있는 최대 수입
//D[i] = D[i+1]   -> 오늘 시작되는 상담을 했을때 퇴사일까지 끝나지 않는 경우
//D[i] = MAX(D[i+1], D[i+T[i]] + P[i] )   -> 오늘 시작되는 상담을 했을때 퇴사일 안에 끝나는 경우
//					ex> D[5] = Max(D[6], D[5 + T[5]] + P[5] )
//						 D[6]은 5일차의 일을 시작 안했을경우임. 이 경우와
//						 D[5 + T[5]] + P[5] 은 
//							5일차 일 했을때 끝나는 날의 수입에다가
//							    *  T[5] : 5일차 일이 걸리는 날 
//							P[5] : 5일차일을 했을때의 수입을 더한 경우와 비교
//						그러면 5일 차 일을 안하는게 이득인지 하는게 이득인지를 알 수 있음.


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static int N;
static vector<int> D, Ti, Pi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	D.resize(N + 2);
	Ti.resize(N + 1);
	Pi.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> Ti[i] >> Pi[i];
	}

	for (int i = N; i > 0; i--)
	{
		if (i + Ti[i] > N + 1)    //i번째 상담을 퇴사일까지 끝낼 수 없는 경우
		{
			// i : 현재날짜 + Ti[i] : 상담이 걸리는 기간 > N+1 : 퇴사날
			D[i] = D[i + 1];  
		}
		else						//i 번째 상담을 퇴사일까지 끝낼 수 있는 경우
		{
			D[i] = max(D[i + 1], D[i + Ti[i]] + Pi[i]);
		}
	}
	cout << D[1];

}
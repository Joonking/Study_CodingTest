//10814 나이순정렬 - 대현이형 코드

/*
문제
온라인 저지에 가입한 사람들의 나이와 이름이 
가입한 순서대로 주어진다.이때, 회원들을 나이가 증가하는 순으로, 
나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 
정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100, 000)
둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 
구분되어 주어진다.나이는 1보다 크거나 같으며, 200보다 작거나 
같은 정수이고, 이름은 알파벳 대소문자로 이루어져 있고, 
길이가 100보다 작거나 같은 문자열이다.
입력은 가입한 순서로 주어진다.

입력 예제
3
21 Junkyu
21 Dohyun
20 Sunyoung

출력예제
20 Sunyoung
21 Junkyu
21 Dohyun
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Account
{
	int ID;
	int Age;
	string Name;
};

bool operator<(Account const& left, Account const& right)
{
	if (left.Age == right.Age)
	{
		return left.ID < right.ID;
	}
	return left.Age < right.Age;
}

bool operator>(Account const& left, Account const& right)
{
	if (left.Age == right.Age)
	{
		return left.ID > right.ID;
	}
	return left.Age > right.Age;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<Account> v;

	for (int i = 0; i < N; i++)
	{
		Account tempAccount;
		tempAccount.ID = i;
		cin >> tempAccount.Age >> tempAccount.Name;
		v.push_back(tempAccount);
	}

	sort(v.begin(), v.end());

	for (Account i : v)
	{
		cout << i.Age << ' ' << i.Name << "\n";
	}
}
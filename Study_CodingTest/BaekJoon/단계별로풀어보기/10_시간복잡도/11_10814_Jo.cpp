//11_10814 대현이형림 코드

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

bool operator>(Account const& Left, Account const& Right)
{
    if (Left.Age == Right.Age)
        return Left.ID > Right.ID;
    return Left.Age > Right.Age;
}
bool operator<(Account const& Left, Account const& Right)
{
    if (Left.Age == Right.Age)
        return Left.ID < Right.ID;
    return Left.Age < Right.Age;
}

vector<Account> Arr{};

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        Account elem{};
        elem.ID = i;
        cin >> elem.Age >> elem.Name;
        Arr.push_back(elem);
    }
    sort(Arr.begin(), Arr.end());

    for (auto const& elem : Arr)
    {
        cout << elem.Age << " " << elem.Name << "\n";
    }

    return 0;
}
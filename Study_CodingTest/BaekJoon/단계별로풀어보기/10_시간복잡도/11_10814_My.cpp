//11_10814 나이순 정렬(내 코드)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int ID;
    int Age;
    string Name;
};

bool operator>(node const& Left, node const& Right)
{
    if (Left.Age == Right.Age)
        return Left.ID > Right.ID;
    return Left.Age > Right.Age;
}

bool operator<(node const& Left, node const& Right)
{
    if (Left.Age == Right.Age)
        return Left.ID < Right.ID;
    return Left.Age < Right.Age;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<node> arr;

    for (int i = 0; i < n; i++)
    {
        node tempNode;
        tempNode.ID = i;
        cin >> tempNode.Age >> tempNode.Name;
        arr.push_back(tempNode);
    }

    sort(arr.begin(), arr.end());

    for (node a : arr)
    {
        cout << a.Age << " " << a.Name << '\n';
    }

    return 0;
}



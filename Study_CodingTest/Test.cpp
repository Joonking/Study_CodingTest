#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;


int main()
{
    
    map<string, int> hash;
    unordered_map<string, int> hash2;

    
    hash.insert(make_pair("97674223", 2));
    hash.insert(make_pair("119", 1));
    hash.insert(make_pair("1195524421", 3));

    hash2.insert(make_pair("97674223", 2));
    hash2.insert(make_pair("119", 1));
    hash2.insert(make_pair("1195524421", 3));

    for (auto i : hash)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << "---------------" << endl;

    for (auto i : hash2)
    {
        cout << i.first << " " << i.second << endl;
    }
}
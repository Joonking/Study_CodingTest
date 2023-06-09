#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int k = 0; // k는 IOI의 길이. IOI면 1 , IOIOI면 2
        // O가 나오면 pass
        if (s[i] == 'O')
            continue;
        // s[i] == 'I'일 때
        else
        {
            while (s[i + 1] == 'O' && s[i + 2] == 'I')
            {
                k++;
                if (k == n)
                {
                    k--; // 중복 카운트를 막기 위해 -1 해준다.
                    ans++;
                }
                i += 2; // O를 건너 뛴다.
            }
            k = 0;
        }
    }
    cout << ans;

    return 0;
}
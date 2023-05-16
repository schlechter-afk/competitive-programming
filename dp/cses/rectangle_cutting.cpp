#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pa;
typedef vector<pa> vp;
#define pb push_back
#define sz(a) (int)(a.size())
#define endl "\n"
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

void solve()
{
    ll a, b;
    cin >> a >> b;
    ll maxc = max(a, b);
    vvi grid(maxc + 1, vi(maxc + 1, 0));
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i == j)
            {
                grid[i][j] = 0;
            }
            else
            {
                grid[i][j] = INT_MAX;
                for (int k = 1; k < i; k++)
                {
                    grid[i][j] = min(grid[i][j], grid[k][j] + grid[i - k][j] + 1);
                }
                for (int k = 1; k < j; k++)
                {
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[i][j - k] + 1);
                }
            }
        }
    }
    cout << grid[a][b] << endl;
}

int main()
{
    speed;
    ll tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
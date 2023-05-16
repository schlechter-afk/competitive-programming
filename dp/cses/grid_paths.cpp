#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
#define mod 1000000007
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

ll recurse(int x, int y, vvc &grid, vvi &dp)
{
    if (x == 0 && y == 0) return 1;
    if (x < 0 || y < 0) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    ll val = 0;
    if (y >= 1 && grid[x][y - 1] != '*')
    {
        dp[x][y - 1] = recurse(x, y - 1, grid, dp);
        val += dp[x][y - 1];
        val %= mod;
    }
    if (x >= 1 && grid[x - 1][y] != '*')
    {
        dp[x - 1][y] = recurse(x - 1, y, grid, dp);
        val += dp[x - 1][y];
        val %= mod;
    }
    return dp[x][y] = val;
}

void solve()
{
    ll n;
    cin >> n;
    vvc inp(n + 1, vc(n + 1));
    vvi dp(n + 1, vi(n + 1, -1));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> inp[i][j];  
    if (inp[n - 1][n - 1] == '*' || inp[0][0] == '*')
    {
        cout << "0" << endl;
        return;
    }
    ll val = recurse(n - 1, n - 1, inp, dp);
    cout << val << endl;
}

int main()
{
    speed;
    ll tc = 1;
    while (tc--)
    {
        solve();
    }
    return 0;
}
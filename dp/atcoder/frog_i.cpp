#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
typedef long long int ll;

int height[1000050];
int dp[1000050];

int recurse(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int cost = INT_MAX;
    cost = min((recurse(n - 1) + abs(height[n] - height[n - 1])), cost);
    if (n > 1)
    {
        cost = min((recurse(n - 2) + abs(height[n] - height[n - 2])), cost);
    }
    return dp[n] = cost;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    cout << recurse(n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tc = 1;
    // cin >> tc;
    while (tc--)
    {
        memset(dp, -1, sizeof(dp));
        solve();
    }
    return 0;
}
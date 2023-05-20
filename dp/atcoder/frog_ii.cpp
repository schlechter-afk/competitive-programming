#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
typedef long long int ll;

int height[100050];
int dp[100050];

int recurse(int n, int k)
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
    for (int i = 1; i <= k; i++)
    {
        if (n > i - 1)
        {
            cost = min((recurse(n - i, k) + abs(height[n] - height[n - i])), cost);
        }
    }
    return dp[n] = cost;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    cout << recurse(n - 1, k);
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
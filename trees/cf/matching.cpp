#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back

vi adj[200005];
int dp[200005][2];

void dfs(int v, int p)
{
    for (auto vert : adj[v])
    {
        if (vert != p)
        {
            dfs(vert, v);
            dp[v][0] += max(dp[vert][0], dp[vert][1]);
        }
    }
    for (auto vert : adj[v])
    {
        if (vert != p)
        {
            dp[v][1] = max(dp[v][1], dp[vert][0] + 1 + dp[v][0] - max(dp[vert][0], dp[vert][1]));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << '\n';
}
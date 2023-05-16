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

vi adjlist[100005];
vi vis(100005);
vi weights(100005);
pa dp[2][100005]; // dp[1][v] : {good nodes in subtree of v, weight till now} , dp[0][v] : {bad nodes in subtree of v, weight till now}

void dfs(int node)
{
    vis[node] = 1;
    for (auto vert : adjlist[node])
    {
        if (vis[vert])
            continue;
        dfs(vert);
        dp[1][node].first += dp[0][vert].first;
        dp[1][node].second += dp[0][vert].second;
        if (dp[0][vert].first > dp[1][vert].first)
        {
            dp[0][node].first += dp[0][vert].first;
            dp[0][node].second += dp[0][vert].second;
        }
        else if (dp[0][vert].first < dp[1][vert].first)
        {
            dp[0][node].first += dp[1][vert].first;
            dp[0][node].second += dp[1][vert].second;
        }
        else
        {
            dp[0][node].first += dp[0][vert].first;
            dp[0][node].second += min(dp[0][vert].second, dp[1][vert].second);
        }
    }
    dp[1][node].first += 1;
    dp[1][node].second += adjlist[node].size();
    dp[0][node].second += 1;
    // cout << node << " " << dp[0][node].first << " " << dp[0][node].second << " " << dp[1][node].first << " " << dp[1][node].second << " **\n";
} 

void dfs2(int node, int flag)
{
    vis[node] = 1;
    if (!flag)
        weights[node] = 1;
    else
        weights[node] = adjlist[node].size();
    for (auto vert : adjlist[node])
    {
        if (vis[vert])
            continue;
        if (flag)
            dfs2(vert, 0);
        else
        {
            if (dp[0][vert].first > dp[1][vert].first)
            {
                dfs2(vert, 0);
            }
            else if (dp[0][vert].first < dp[1][vert].first)
            {
                dfs2(vert, 1);
            }
            else
            {
                if (dp[0][vert].second < dp[1][vert].second)
                {
                    dfs2(vert, 0);
                }
                else
                {
                    dfs2(vert, 1);
                }
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].pb(v);
        adjlist[v].pb(u);
    }
    if (n == 2)
    {
        cout << 2 << " " << 2 << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }
    dfs(1);
    vis.assign(n + 1, 0);
    if (dp[0][1].first > dp[1][1].first)
    {
        cout << dp[0][1].first << " " << dp[0][1].second << endl;
        dfs2(1, 0);
    }
    else if (dp[0][1].first < dp[1][1].first)
    {
        cout << dp[1][1].first << " " << dp[1][1].second << endl;
        dfs2(1, 1);
    }
    else
    {
        if (dp[0][1].second < dp[1][1].second)
        {
            cout << dp[0][1].first << " " << dp[0][1].second << endl;
            dfs2(1, 0);
        }
        else
        {
            cout << dp[1][1].first << " " << dp[1][1].second << endl;
            dfs2(1, 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << weights[i] << " ";
    }
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
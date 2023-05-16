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

vi adjlist[200005];
vi vis(200005);
vi subtree(200005);
vi dp(200005);
int ans;
int n;

void dfs(int node)
{
    vis[node] = 1;
    subtree[node] = 1;
    for (auto adjvert : adjlist[node])
    {
        if (!vis[adjvert])
        {
            dfs(adjvert);
            subtree[node] += subtree[adjvert];
            dp[node] += dp[adjvert];
        }
    }
    dp[node] += subtree[node];
}

void calcsum(int node, int val)
{
    vis[node] = 1;
    ans = max(ans, val);
    for (auto adjvert : adjlist[node]) 
        if (!vis[adjvert]) calcsum(adjvert, val + n - 2 * subtree[adjvert]);
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].pb(v);
        adjlist[v].pb(u);
    }
    dfs(1);
    vis.assign(n + 2, 0);
    calcsum(1, dp[1]);
    cout << ans << endl;
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
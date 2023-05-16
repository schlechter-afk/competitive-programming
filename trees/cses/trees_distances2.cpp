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
#define int long long int
vector<int> adjlist[200005];
std::vector<int> vis = std::vector<int>(200005);
std::vector<int> ans = std::vector<int>(200005);
std::vector<int> subtree_sz = std::vector<int>(200005, 1);
int N;

void dfs(int node)
{
    vis[node] = 1;
    for (auto vert : adjlist[node])
    {
        if (!vis[vert])
        {
            dfs(vert);
            ans[node] += ans[vert] + subtree_sz[vert];
            subtree_sz[node] += subtree_sz[vert];
        }
    }
}

void dfs2(int node)
{
    vis[node] = 1;
    for (auto vert : adjlist[node])
    {
        if (!vis[vert])
        {
            ans[vert] = ans[node] + N - 2 * subtree_sz[vert];
            dfs2(vert);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    N = n;
    dfs(1);
    vis.assign(n + 2, 0);
    dfs2(1);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}

signed main()
{
    speed;
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
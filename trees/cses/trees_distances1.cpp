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
int farthest1;
int d = 0; // stores temp depth

int dist[2][200005];

void dfs(int node, int depth, int i)
{
    vis[node] = 1;
    dist[i][node] = depth;
    for (auto vert : adjlist[node])
    {
        if (!vis[vert])
        {
            dfs(vert, depth + 1, i);
        }
    }
    if (depth > d)
    {
        d = depth;
        farthest1 = node;
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
    dfs(1, 0, 0);
    vis.assign(vis.size(), 0);
    d = 0;
    dfs(farthest1, 0, 0);
    vis.assign(vis.size(), 0);
    d = 0;
    dfs(farthest1, 0, 1);
    for (int i = 1; i <= n; i++)
    {
        cout << max(dist[0][i], dist[1][i]) << " ";
    }
}

int main()
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
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

void dfs(int node, int depth)
{
    vis[node] = 1;
    for (auto vert : adjlist[node])
    {
        if (!vis[vert])
        {
            dfs(vert, depth + 1);
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
    dfs(1, 0);
    vis.assign(vis.size(), 0);
    d = 0;
    dfs(farthest1, 0);
    cout << d << "\n";
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
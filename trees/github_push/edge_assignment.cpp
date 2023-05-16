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
vi dist(100005);

int minfval[2];
int maxfval;
int root;
// int leaves;

void dfs(int vert)
{
    vis[vert] = 1;
    int sub_leaves = 0;
    if(adjlist[vert].size() == 1) minfval[(dist[vert] % 2)] = 1;
    for (auto nbr : adjlist[vert])
    {
        if (!vis[nbr])
        {
            if(adjlist[nbr].size() == 1) sub_leaves++;
            dist[nbr] = dist[vert] + 1;
            dfs(nbr);
        }
    }
    // cout << vert << " " << sub_leaves << " &&\n";
    if (vert != root && adjlist[vert].size() >= 2) maxfval++;
    if (sub_leaves != 0) maxfval++;
    // cout << vert << " " << maxfval << " **\n";
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
    for (int i = 1; i <= n; i++)
    {
        if (adjlist[i].size() != 1)
        {
            root = i;
            break;
        }
    }
    dist[root] = 0;
    dfs(root);
    // leaves++;
    int minf = 1;
    if(minfval[0] & minfval[1]) minf = 3;
    cout << minf << " " << maxfval << "\n";
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
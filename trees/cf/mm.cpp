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
vi depth(200005);
vi store(200005);
int cnt;

void dfs(int vert)
{
    vis[vert] = 1;
    for (auto nbr : adjlist[vert])
    {
        if (!vis[nbr])
        {
            depth[nbr] = depth[vert] + 1;
            dfs(nbr);
        }
    }
}

void dfs2(int vert, int par, int height)
{
    store[vert] = depth[vert];
    for (auto nbr : adjlist[vert])
    {
        if (par != nbr)
        {
            dfs2(nbr, vert, height);
            store[vert] = max(store[vert], store[nbr]);
        }
    }
    if (par > 1 && store[vert] - depth[vert] == height - 1)
    {
        cnt++;
        store[vert] = 0;
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    adjlist[1].clear();
    depth.clear();
    store.clear();
    for (int i = 2; i <= n; i++)
    {
        adjlist[i].clear();
        int v;
        cin >> v;
        adjlist[v].pb(i);
        adjlist[i].pb(v);
    }
    int lo = 1, hi = n - 1, ans = n - 1;
    vis.assign(n + 1, 0);
    dfs(1);
    while (hi - lo >= 1)
    {
        int mid = (lo + hi) / 2;
        // vis.assign(n + 1, 0);
        cnt = 0;
        dfs2(1, 0, mid);
        // cout << cnt << " " << mid << " **\n";
        if (cnt <= k)
        {
            hi = mid;
            ans = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main()
{
    speed;
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
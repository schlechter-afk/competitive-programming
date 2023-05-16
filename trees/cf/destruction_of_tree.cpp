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
vi subtree_size(200005);
vi delverts;

void dfs(int vert, int par)
{
    subtree_size[vert] = 1;
    for (auto nbr : adjlist[vert])
    {
        if (nbr != par)
        {
            dfs(nbr, vert);
            subtree_size[vert] += subtree_size[nbr];
        }
    }
}

void dfs2(int vert, int par)
{
    for (auto nbr : adjlist[vert])
    {
        if (nbr != par && subtree_size[nbr] % 2 == 0)
        {
            dfs2(nbr, vert);
        }
    }
    delverts.pb(vert);
    for (auto nbr : adjlist[vert])
    {
        if (nbr != par && subtree_size[nbr] % 2 != 0)
        {
            dfs2(nbr, vert);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    int root;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        if (v)
        {
            adjlist[i].pb(v);
            adjlist[v].pb(i);
        }
        else root = i;
    }
    if (n == 1)
    {
        cout << "YES\n";
        cout << "1";
        return;
    }
    if (n % 2 == 0) cout << "NO\n";
    else
    {
        cout << "YES\n";
        dfs(root, -1);
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << subtree_size[i] << " *\n";
        // }
        dfs2(root, -1);
        for (auto it : delverts)
        {
            cout << it << "\n";
        }
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
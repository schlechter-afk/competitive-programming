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

vi vis(200005);
vi depth(200005);
vi adjlist[200005];
int up[200005][21] = {0}; // up[i][j] : 2^jth ancestor of i.

void dfs(int node)
{
    vis[node] = 1;
    for (auto vert : adjlist[node])
    {
        if (!vis[vert])
        {
            up[vert][0] = node;
            for (int j = 1; j <= 20; j++)
            {
                up[vert][j] = up[up[vert][j - 1]][j - 1];
            }
            depth[vert] = depth[node] + 1;
            dfs(vert);
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    // int up[n + 2][21] = {0}; // up[i][j] : 2^jth ancestor of i.
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    dfs(1);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        int storea, storeb;
        storea = a;
        storeb = b;
        if (depth[a] < depth[b])
            swap(a, b);

        // cout << depth[a] << " " << depth[b] << "\n";

        int K = depth[a] - depth[b];
        for (int j = 0; j < 20; j++)
        {
            if (K & (1 << j))
            {
                a = up[a][j];
            }
        }
        if (a == b)
        {
            cout << K << "\n";
        }
        else
        {
            for (int j = 20; j >= 0; j--)
            {
                if (up[a][j] != up[b][j])
                {
                    a = up[a][j];
                    b = up[b][j];
                }
            }
            cout << depth[storea] - 2 * depth[up[a][0]] + depth[storeb] << "\n";
        }
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
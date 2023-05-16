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

void dfs(int node)
{
    vis[node] = 1;
    for (auto vert : adjlist[node])
    {
        if (!vis[vert])
        {
            depth[vert] = depth[node] + 1;
            dfs(vert);
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    int up[n + 2][21] = {0}; // up[i][j] : 2^jth ancestor of i.
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        adjlist[a].push_back(i + 2);
        adjlist[i + 2].push_back(a);
        up[i + 2][0] = a;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    dfs(1);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
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
            cout << a << "\n";
        }
        else
        {
            for (int j = 20; j >= 0; j--)
            {
                if(up[a][j]!=up[b][j])
                {
                    a = up[a][j];
                    b = up[b][j];
                }
            }
            cout << up[a][0] << "\n";
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
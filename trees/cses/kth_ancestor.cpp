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

void solve()
{
    int n, q;
    cin >> n >> q;
    int up[n + 2][21] = {0}; // up[i][j] : 2^jth ancestor of i.
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        up[i + 2][0] = a;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    for (int i = 0; i < q; i++)
    {
        int node, k;
        cin >> node >> k;
        for (int j = 0; j < 20; j++)
        {
            if (k & (1 << j))
            {
                node = up[node][j];
            }
        }
        if(node == 0)
        {
            cout << "-1" << "\n";
        }
        else
        cout << node << "\n";
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
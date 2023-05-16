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
vi subtree(200005);
vi vis(200005);

int calc(int node)
{
    vis[node] = 1;
    if (adjlist[node].size() == 1 && node != 1)
    {
        return 1;
    }
    for (auto vert : adjlist[node])
    {
        if (!vis[vert])
        {
            subtree[node] += calc(vert);
        }
    }
    return subtree[node] + 1;
}

void solve()
{
    int n;
    cin >> n;
    vi dir_boss(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> dir_boss[i];
        adjlist[i + 2].push_back(dir_boss[i]);
        adjlist[dir_boss[i]].push_back(i + 2);
    }
    calc(1);
    for (int i = 1; i <= n; i++)
    {
        cout << subtree[i] << " ";
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
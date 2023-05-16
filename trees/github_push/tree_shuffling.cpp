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
vi cost(200005);
vi curr(200005);
vi expec(200005);
vi reqone(200005);
vi reqzero(200005);
ll retval;

void dfs(int vert, int par)
{
    cost[vert] = min(cost[vert],cost[par]);
    if (curr[vert] != expec[vert] && expec[vert]) reqone[vert]++;
    if (curr[vert] != expec[vert] && !expec[vert]) reqzero[vert]++;
    for (auto nbr : adjlist[vert])
    {
        if (nbr != par)
        {
            dfs(nbr, vert);
            reqone[vert] += reqone[nbr];
            reqzero[vert] += reqzero[nbr];
        }
    }
    // cout << vert << " " << reqone[vert] << " " << reqzero[vert] << " ***\n";
    int resolved = min(reqzero[vert], reqone[vert]);
    reqone[vert] -= resolved;
    reqzero[vert] -= resolved;
    retval += (2 * resolved * cost[vert]);
    // cout << vert << " " << retval << " &&\n";
}

void solve()
{
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i] >> curr[i] >> expec[i];
        if (curr[i] != expec[i] && expec[i]) cnt1++;
        if (curr[i] != expec[i] && !expec[i]) cnt2++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].pb(v);
        adjlist[v].pb(u);
    }
    if(cnt1 != cnt2)
    {
        cout << "-1";
        return;
    }
    dfs(1,1);
    cout << retval;
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
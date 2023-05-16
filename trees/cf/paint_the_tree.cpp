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
vi deg(100005);
vi assign(100005);

void dfs(int node,int par)
{
    for (auto vert : adjlist[node])
    {
        if(vert == par)
            continue;
        assign[vert] = 6 - assign[node] - assign[par];
        dfs(vert, node);
    }
}

void solve()
{
    int n;
    cin >> n;
    vi col1(n);
    vi col2(n);
    vi col3(n);
    for (int i = 0; i < n; i++)
    {
        cin >> col1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> col2[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> col3[i];
    }
    int fl = 0;
    int pa1, pa2;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].pb(v);
        adjlist[v].pb(u);
        deg[u]++;
        deg[v]++;
        if (deg[u] >= 3 || deg[v] >= 3) fl = 1;
    }
    if (fl) cout << "-1\n";
    else
    {
        for(int i = 1 ; i <= n;i++)
        {
            if(deg[i] == 1)
            {
                pa1 = i;
                pa2 = adjlist[i][0];
                // cout << pa1 << ' ' << pa2 << endl;
                // return;
                break;
            }
        }
        vp poss;
        poss.pb({1,2});
        poss.pb({1,3});
        poss.pb({2,1});
        poss.pb({2,3});
        poss.pb({3,1});
        poss.pb({3,2});
        ll ans = 1e15;
        int ptr = 0;
        vi out(n+1);
        while(ptr < poss.size())
        {
            assign[pa1] = poss[ptr].first;
            assign[pa2] = poss[ptr].second;
            dfs(pa2,pa1);
            ll cost = 0;
            for(int i = 1;i<=n;i++)
            {
                if(assign[i] == 1) cost += col1[i-1];
                else if(assign[i] == 2) cost += col2[i-1];
                else cost += col3[i-1];  
            }
            if(cost < ans)
            {
                ans = cost;
                // out = assign;
                for(int i=1;i<=n;i++)
                {
                    out[i] = assign[i];
                }
            }
            assign.clear();
            ptr++;
        }
        cout << ans << endl;
        for(int i = 1;i<=n;i++)
        {
            cout << out[i] << ' ';
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
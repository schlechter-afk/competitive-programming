// Codeforces Round 764 Div-3 Problem-G
// By Swayam Agrawal
// Tags: DSU , Minimum Spanning Tree , Graphs , Bitmasks
// Problem : https://codeforces.com/contest/1624/problem/G
// Submission ID: https://codeforces.com/contest/1624/submission/198388260

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
    
const int N = (int)2e5 + 2;
int n;
int par[N];
int sets[N];

void init(int _size)
{
    n = _size;
    for (int x = 1; x <= n; ++x)
    {
        par[x] = x;
        sets[x] = 1;
    }
}

int getPar(int v)
{
    if (v == par[v]) return v;
    return par[v] = getPar(par[v]);
}

void Union(int u, int v)
{
    u = getPar(u);
    v = getPar(v);
    if (u == v)
        return;
    if (sets[u] > sets[v])
        swap(u, v);
    par[u] = v;
    sets[v] += sets[u];
}

struct Edge
{
    ll u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};

map<int,set<int>>mp;
vector<bool> vis(32);

void solve()
{
    string str;
    getline(cin, str);
    ll n, m;
    vis.assign(31,0);
    cin >> n >> m;
    ll cost = 0;
    vector<Edge> edges(m);
    mp.clear();
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Iterate over all bits from 0 to 31 and first obtain the edge indexes
    // which have this bit on in their weights. Maintain a vis array of all
    // bits which is true for all of them, it signifies that this bit is on in
    // the final ans.

    for (int i = 0; i <= 31; i++)
    {
        ll wt = 1LL << i;
        for (int j = 0; j < m; j++)
        {
            if (edges[j].weight & wt) mp[i].insert(j);
        }
        vis[i] = 1;
    }

    for (int i = 31; i >= 0; i--)
    {
        int tot_edges = 0;
        init(n);

        // We try to off this bit as it will be beneficial to us, as we want minimum
        // OR of all weights, thus iterating from MSB to LSB. Maintain a choose array
        // which is true for all edge indexes, signifies which edge can be considered
        // in building the spanning tree.

        vis[i] = 0;
        vector<bool> choose(m + 1, 1);
        for (int j = 31; j >= 0; j--)
        {
            if(!vis[j])
            {
                // If the bit is off, we dont want the edges to be included which have
                // this bit on because then the result will contain this bit contribution
                // because it is OR of edge weights.

                for (auto edge_idx: mp[j]) choose[edge_idx] = 0;
            }
        }

        // Now simply iterate over all edge indexes and consider those edges which can be
        // taken into consideration i.e. choose[j] = 1, and build the spanning tree by 
        // Union of the vertexes connected by this edge.

        for (int j = 0; j < m; j++)
        {
            if(choose[j])
            {
                if(getPar(edges[j].u) != getPar(edges[j].v))
                {
                    Union(edges[j].u, edges[j].v);
                    tot_edges++;
                }
            }
        }
        // At last check if total number of edges count upto n-1 or not, if not then it
        // implies that we cannot turn this ith bit off thus this bit will be on in the
        // final OR result, hence add 2^i to cost.

        if(tot_edges != n - 1)
        {
            vis[i] = 1;
            cost += (1 << i);
        }
    }
    cout << cost << endl;
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
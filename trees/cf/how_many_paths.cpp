#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef vector<ll> vi;
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
const ll INF = 1e15 + 21;
const ll MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353;
#define read(vec)                        \
    for (int i = 0; i < vec.size(); i++) \
    {                                    \
        cin >> vec[i];                   \
    }
#define output(vec)                      \
    for (int i = 0; i < vec.size(); i++) \
    {                                    \
        cout << vec[i] << " ";           \
    }
template <typename T1, typename T2>
pair<T1, T2> operator+(pair<T1, T2> &l, pair<T1, T2> &r)
{
    return {l.first + r.first, l.second + r.second};
}

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // order_of_key, find_by_order
// use x.erase(find_by_order(order_of_key(val))) to erase val from x (ordered_multiset)
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; // order_of_key, find_by_order

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
// https://gist.github.com/Chillee/3bd6ee4429abb4a2e7c19959fb1490ae#file-hash-table-cpp
struct chash
{
    // const int RANDOM = rng(); // use if collisions not an issue.
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x) ^ RANDOM; }
};

typedef cc_hash_table<ll, ll, hash<ll>> ht;
typedef gp_hash_table<int, int, chash> gptable;

vi adjlist[400005];
vi cols(400005);
vi type1,type2;
vi vis_type1(400005),vis_type2(400005);
vi group1,group2;
vi reachable(400005);

void dfs(int node)
{
    cols[node] = 1;
    reachable[node] = 1;
    for (auto adjvert : adjlist[node])
    {
        if(cols[adjvert]==1) type1.pb(adjvert);
        if(cols[adjvert]==2) type2.pb(adjvert);
        if(!cols[adjvert])
        {
            dfs(adjvert);
        }
    }
    cols[node] = 2;
}

void dfs_type1(int node)
{
    vis_type1[node] = 1;
    group1.push_back(node);
    for(auto adjvert : adjlist[node])
    {
        if(!vis_type1[adjvert])
        {
            dfs_type1(adjvert);
        }
    }
}

void dfs_type2(int node)
{
    vis_type2[node] = 1;
    group2.push_back(node);
    for(auto adjvert : adjlist[node])
    {
        if(!vis_type2[adjvert])
        {
            dfs_type2(adjvert);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        adjlist[i].clear();
    }
    cols.assign(n+1,0);
    vis_type1.assign(n+1,0);
    vis_type2.assign(n+1,0);
    reachable.assign(n+1,0);
    type1.clear();
    type2.clear();
    group1.clear();
    group2.clear();
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
    }
    dfs(1);
    // for(int i=1;i<=n;i++) cout << reachable[i] << " ";
    // cout << endl;
    // for(auto ele:type2) cout << ele << " ";
    // cout << endl;
    for(auto it:type1) if(!vis_type1[it]) dfs_type1(it);
    for(auto it:type2) if(!vis_type2[it]) dfs_type2(it);
    // for(auto ele:group1) cout << ele << " ";
    // cout << endl;
    unordered_map<int,int> mp1,mp2;
    for(auto it:group1) mp1[it] += 1;
    for(auto it:group2) mp2[it] += 1;
    vi ans(n+1);
    for(int i=1;i<=n;i++)
    {
        if(!reachable[i]) ans[i] = 0;
        else if(mp1[i]) ans[i] = -1;
        else if(mp2[i] && mp1[i] == 0) ans[i] = 2;
        else if(mp1[i] == 0 && mp2[i] == 0) ans[i] = 1;
        else continue;
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    speed;
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        string str;
        getline(cin, str);
        solve();
    }
    return 0;
}
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
        cout << vec[i] << " ";                  \
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

class SegTree{

    struct node{
        int full = 0;
        int open = 0;
        int close = 0;
    };
    vector<node> segarr;
    public: SegTree(int n)
    {
        segarr.resize(4*n+1);
    }
    node merge(node a, node b)
    {
        node ans;
        ans.full = a.full + b.full + 2*min(a.open,b.close);
        ans.open = a.open + b.open - min(a.open,b.close);
        ans.close = a.close + b.close - min(a.open,b.close);
        return ans;
    }
    void build(int l, int r, int idx, string &str)
    {
        int mid = (l + r)/2;
        if (l == r){
            if(str[mid] == '(') segarr[idx].open = 1,segarr[idx].close = 0,segarr[idx].full = 0;
            else segarr[idx].open = 0,segarr[idx].close = 1,segarr[idx].full = 0;
            return;
        }
        build(l,mid,2*idx+1,str);
        build(mid+1,r,2*idx+2,str);
        segarr[idx] = merge(segarr[2*idx+1],segarr[2*idx+2]);
    }
    node query(int l, int r, int minrange, int maxrange, int idx)
    {
        node result;
        result.full = 0,result.open = 0,result.close = 0;
        if(r < minrange || l > maxrange) return result;
        if(l >= minrange && r <= maxrange) return segarr[idx];
        int mid = (l + r)/2;
        node lquery = query(l,mid,minrange,maxrange,2*idx+1);
        node rquery = query(mid+1,r,minrange,maxrange,2*idx+2);
        return merge(lquery,rquery);
    }  
};

void solve()
{
    string str;
    int queries;
    cin >> str;
    cin >> queries;
    int n = str.length();
    SegTree Tree(n);
    Tree.build(0,n-1,0,str);
    while(queries--)
    {
        int l,r;
        cin >> l >> r;
        cout << Tree.query(0,n-1,l-1,r-1,0).full << endl;
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
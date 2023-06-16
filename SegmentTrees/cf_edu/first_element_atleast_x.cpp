#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define int long long int
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

// struct node{
//     int seg, pref,suff,sum_all;
// };

typedef int node;

vector<int> arr;
vector<node> segarr;
void init(int n)
{
    segarr.resize(4*n+1);
}
node single(int val)
{
    return val;
}
node merge(node a, node b)
{
    return max(a,b);
}
void setval(int idx, int value,int segidx,int l, int r)
{
    if(l == r){
        arr[idx] = value;
        segarr[segidx] = single(value);
        return;
    }
    int mid = (l+r)/2;
    if(idx <= mid) setval(idx,value,2*segidx+1,l,mid);
    else setval(idx,value,2*segidx+2,mid+1,r);
    segarr[segidx] = merge(segarr[2*segidx+1],segarr[2*segidx+2]);
}
void build(int l, int r, int idx)
{
    int mid = (l + r)/2;
    if (l == r){
        segarr[idx] = single(arr[l]);
        return;
    }
    build(l,mid,2*idx+1);
    build(mid+1,r,2*idx+2);
    segarr[idx] = merge(segarr[2*idx+1],segarr[2*idx+2]);
}
node query(int l, int r, int minrange, int maxrange, int idx)
{
    if(r < minrange || l > maxrange) return INT_MIN;
    if(l >= minrange && r <= maxrange) return segarr[idx];
    int mid = (l + r)/2;
    node lquery = query(l,mid,minrange,maxrange,2*idx+1);
    node rquery = query(mid+1,r,minrange,maxrange,2*idx+2);
    return merge(lquery,rquery);
}  

node first_above(int k,int l, int r, int idx)
{
    if(segarr[idx]<k) return -1;
    if(l==r) return l;
    int mid = (l+r)/2;
    int res = first_above(k,l,mid,2*idx+1);
    if(res == -1)
    {
        res = first_above(k,mid+1,r,2*idx+2);
    }
    return res;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    arr.resize(n+1);
    for(int i=0;i<n;i++) cin >> arr[i];
    init(n+1);
    build(0,n-1,0);
    while(m--)
    {
        int op;
        cin >> op;
        if(op==1)
        {
            int idx,val;
            cin >> idx >> val;
            setval(idx,val,0,0,n-1);
        }
        else
        {
            int val;
            cin >> val;
            cout << first_above(val,0,n-1,0) << endl;
        }
    }
}

signed main()
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
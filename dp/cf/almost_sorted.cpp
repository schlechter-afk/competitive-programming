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

void solve()
{
    int n, k;
    cin >> n >> k;
    if(n < 64 && k > (1LL << (n - 1))) {
        cout << "-1\n";
        return;
    }
    // generate a bitstream of the number k - 1;
    int gennum = k-1;
    vi bits;
    while(gennum)
    {
        bits.pb(gennum%2);
        gennum /= 2;
    }
    reverse(bits.begin(),bits.end());
    int bitsize = bits.size();

    vi vec;
    for(auto it:bits) vec.pb(it);
    vec.pb(0);
    // for(auto it:vec) cout << it;
    int rem_bits = n - vec.size();
    reverse(vec.begin(),vec.end());
    while(rem_bits > 0) 
    {
        vec.push_back(0);
        rem_bits--;
    }
    reverse(vec.begin(),vec.end());
    // if(k == 2)
    // {
    //     for(int i=1;i<=n-2;i++)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << n << " " << n-1 << endl;
    // }
    // else{
    int curr = 1;
    int sz = 1;
    vi ans;
    for (int i = 0; i < n; i++)
    {
        if (vec[i] == 0)
        {
            for (int j = curr + sz - 1; j >= curr; j--)
            {
                ans.pb(j);
            }
            curr += sz;
            sz = 1;
        }
        else sz++;
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}

signed main()
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
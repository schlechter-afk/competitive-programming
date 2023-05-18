#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using namespace __gnu_pbds;
#define int long long int
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pa;
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
    ll n,x;
    cin >> n >> x;
    vi vec(n);
    read(vec);
    ll exhausted[n] = {0};
    ll dp[n][2] = {0};
    dp[0][0] = vec[0];
    dp[0][1] = x*vec[0];
    ll ans = max((ll)exhausted[0],max((ll)dp[0][0],(ll)dp[0][1]));
    for(int i=1;i<n;i++)
    {
        dp[i][0] = max(1LL*vec[i],(ll)(vec[i] + dp[i-1][0]));
        dp[i][1] = max((ll)x*vec[i],(ll)(x*vec[i] + max((ll)dp[i-1][0],(ll)dp[i-1][1])));
        exhausted[i] = max(1LL*vec[i], (ll) (vec[i] + max(dp[i-1][1],exhausted[i-1])));
        ans = max((ll)ans, max((ll)exhausted[i],max((ll)dp[i][0],(ll)dp[i][1])));
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);                
    cout.tie(nullptr);
    solve();
}
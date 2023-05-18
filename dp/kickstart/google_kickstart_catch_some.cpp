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

vector<int> assign[1001];
int dp[1001][1001][2];

int func(int colour, int rem_observe, int two_way)
{
    if (rem_observe <= 0)
        return 0;
    if (colour > 1000)
        return 1e16;
    if (dp[colour][rem_observe][two_way] != -1)
        return dp[colour][rem_observe][two_way];
    int ans = 1e16;
    int cnt = 0;
    for (auto pos : assign[colour])
    {
        if (!two_way)
            ans = min(ans, pos + func(colour + 1, rem_observe - (cnt + 1), 1));
        ans = min(ans, 2 * pos + func(colour + 1, rem_observe - (cnt + 1), two_way));
        cnt++;
    }
    ans = min(ans, func(colour + 1, rem_observe, two_way));
    return dp[colour][rem_observe][two_way] = ans;
}

void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    vi pos(n), colours(n);
    read(pos);
    read(colours);
    for (int i = 0; i <= 1000; i++)
        assign[i].clear();
    for (int i = 0; i < n; i++)
    {
        assign[colours[i]].pb(pos[i]);
    }
    for (int i = 0; i <= 1000; i++)
        sort(assign[i].begin(), assign[i].end());
    memset(dp, -1, sizeof(dp));
    cout << "Case #" << tc << ": ";
    cout << func(1, k, 0) << endl;
}

signed main()
{
    speed;
    ll tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }
    return 0;
}
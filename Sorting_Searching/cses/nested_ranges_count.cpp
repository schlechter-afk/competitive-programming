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

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // order_of_key, find_by_order
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

bool cmp(pair<pa, int> &p1, pair<pa, int> &p2)
{
    if (p1.first.first < p2.first.first)
    {
        return true;
    }
    if (p1.first.first == p2.first.first)
    {
        return p1.first.second > p2.first.second;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<pa, int>> ranges(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ranges[i].first.first >> ranges[i].first.second;
        ranges[i].second = i;
    }
    sort(ranges.begin(), ranges.end(), cmp);
    ordered_set<pa> inferior, superior;
    vector<int> infvec(n), supvec(n);
    int i = 0, j = n - 1;
    while (i < n)
    {
        // cout << ranges[i].second << " " << ranges[j].second << " **\n";
        // pushing pair with -1 in second argument in ordered_set as to ensure comparison occurs based on first value only.
        // cout << inferior.order_of_key({ranges[i].first.second, -1}) << " ))\n";
        
        infvec[ranges[i].second] = i - inferior.order_of_key({ranges[i].first.second, -1});
        supvec[ranges[j].second] = superior.order_of_key({ranges[j].first.second + 1, -1});
        inferior.insert({ranges[i].first.second, i});
        superior.insert({ranges[j].first.second, i});
        i++;
        j--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << supvec[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << infvec[i] << " ";
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
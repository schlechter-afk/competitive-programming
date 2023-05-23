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
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
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

const int Fact_Length = 5e5 + 100; // Max length

// Takes a&b as input and Returns : The power (a,b), (a^b)%mod
int Power(int base, int expo)
{
    int $result = 1;
    base %= MOD;
    while (expo)
    {
        if (expo % 2 == 1)
            $result = ($result * base) % MOD;
        base = (base * base) % MOD;
        expo /= 2;
    }
    return $result;
}

// It give the modulo inverse of a, (1/a)%mod
int Mod_Inv(int $a) { return Power($a, MOD - 2); }

int Factorial[Fact_Length];
// It makes the above Factorial[i] = i! array
int Make_Factorial()
{
    Factorial[0] = 1;
    for (int i = 1; i < Fact_Length; i++)
    {
        Factorial[i] = (i * Factorial[i - 1]) % MOD;
    }
    return 0;
}
int Implement_Make_Factorial = Make_Factorial(); // To Implement Make_Factorial

// Takes n&r as input and Returns : choose%mod
int ncr(int $n, int $r)
{
    if ($n < $r || $n < 0 || $r < 0)
        return 0;
    // if($n>Fact_Length) { cout<<"Error"<<endl; return; }
    int $ans = (((Factorial[$n] * Mod_Inv(Factorial[$r])) % MOD) + MOD) % MOD;
    $ans = ((($ans * Mod_Inv(Factorial[$n - $r])) % MOD) + MOD) % MOD;
    return $ans;
}

typedef cc_hash_table<ll, ll, hash<ll>> ht;
typedef gp_hash_table<int, int, chash> gptable;

void solve()
{
    ll n, m;
    cin >> n >> m;
    unordered_map<int, int> mp;
    set<int> si;
    vi vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        mp[vec[i]]++;
        si.insert(vec[i]);
    }
    vec.clear();
    for(auto it:si) vec.pb(it);
    if (vec.size() < m) cout << "0\n";
    else
    {
        int ptr = 0;
        map<int, int> ump;
        ll var = 1;
        for (int i = 0; i < m; i++)
        {
            var *= mp[vec[i]];
            var %= MOD;
        }
        ump[0] = var;
        for(int i=m;i<vec.size();i++)
        {
            ll var = ump[i-m]*mp[vec[i]];
            var %= MOD;
            var *= Mod_Inv(mp[vec[i-m]]);
            var %= MOD;
            ump[i-m+1] = var;
        }
        ll ans = 0;
        while (ptr + m <= vec.size())
        {
            if(vec[ptr+m-1]-vec[ptr] < m)
            {
                ans += ump[ptr];
                ans %= MOD;
            }   
            ptr+=1;
        }
        cout << ans << endl;
    }
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
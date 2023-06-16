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

namespace Primes
{
    int N_MAX;
    vector<int> primes, sp;
    void sieve(int N)
    {
        N_MAX = N;
        sp.resize(N_MAX + 1);
        for (int i = 2; i <= N_MAX; i++)
        {
            if (!sp[i])
            {
                sp[i] = i;
                primes.push_back(i);
            }
            for (int p : primes)
            {
                if (i * p > N_MAX)
                    break;
                sp[i * p] = p;
                if (i % p == 0)
                    break;
            }
        }
    }

    vector<pair<int, int>> factorize(int x)
    {
        vector<pair<int, int>> fact;
        for (int k = 0; k < primes.size() && x > N_MAX && primes[k] * primes[k] <= x; k++)
            if (x % primes[k] == 0)
            {
                x /= primes[k];
                fact.emplace_back(primes[k], 1);
                while (x % primes[k] == 0)
                    fact.back().second++, x /= primes[k];
            }
        if (x > N_MAX)
        {
            fact.emplace_back(x, 1);
            x = 1;
        }
        while (int k = sp[x])
        {
            fact.emplace_back(k, 1);
            x /= k;
            while (x % k == 0)
                x /= k, fact.back().second++;
        }
        return fact;
    }
    vector<int> divisors(int x)
    {
        auto fact = factorize(x);
        vector<int> div;
        auto bkt = [&](auto self, int curr, int k)
        {
            if (k == fact.size())
                return div.push_back(curr);
            for (int i = 0; i <= fact[k].second; i++)
            {
                self(self, curr, k + 1);
                curr *= fact[k].first;
            }
        };
        bkt(bkt, 1, 0);
        return div;
    }
    vector<int> ordered_divisors(int x)
    {
        auto div = divisors(x);
        sort(div.begin(), div.end());
        return div;
    }
    vector<int> ordered_divisors_sqrt(int x)
    {
        vector<int> div;
        for (int i = 1; i * i <= x; i++)
            if (x % i == 0)
                div.push_back(i);
        for (int i = div.size() - 1; i >= 0; i--)
            if (i != x / i)
                div.push_back(x / i);
        return div;
    }
    bool is_prime(int x)
    {
        if (x > N_MAX)
            return sp[x] == x;
        for (int p : primes)
            if (x % p == 0)
                return false;
        return true;
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vi vec(n);
    read(vec);
    vi viscount(m + 1, 0);
    sort(vec.begin(), vec.end());
    vector<int> divs[n + 1];
    for(int i=0;i<n;i++)
    {
        divs[i] = Primes::ordered_divisors(vec[i]);
    }
    int covered = 0;
    ll minval = INT_MAX;
    int ptr2 = -1;
    for(int i=0;i<n;i++)
    {
        while(covered < m && ptr2 < n-1)
        {
            ptr2++;
            for(auto ele: divs[ptr2])
            {
                if(ele <= m)
                {
                    if(!viscount[ele]) covered++;
                    viscount[ele]++;
                }
                else break;
            }
        }
        if(covered >= m) minval = min(minval,vec[ptr2]-vec[i]);
        for(auto ele: divs[i])
        {
            if(ele <= m)
            {
                if(viscount[ele] == 1) covered--; 
                viscount[ele]--;
            }
        }
    }
    if(minval == INT_MAX) cout << "-1\n";
    else cout << minval << "\n";
}

int main()
{
    speed;
    Primes :: sieve(100005);
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
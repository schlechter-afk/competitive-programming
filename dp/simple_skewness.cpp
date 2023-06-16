#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define int long long int
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

double calc_mean(vi &vec, vi &pref, int index, int k)
{
    int n = vec.size();
    if(!k) return vec[index];
    // cout << pref[index+1] << " " << pref[index-k] << " " << pref[n] << " " << pref[n-k] <<" ))\n";
    double sum = (pref[index+1]-pref[index-k]) + (pref[n] - pref[n-k]);
    // cout << sum << "!!!\n";
    // pv[2] - pv[0] + pv[4] - pv[3];
    return sum/(2*k+1);
}

void solve()
{
    int n;
    cin >> n;
    vi vec(n);
    read(vec);
    sort(vec.begin(),vec.end());
    vi pref(n+1);
    pref[0] = 0;
    for(int i=1;i<=n;i++) pref[i] = pref[i-1]+vec[i-1];
    long double bestK=0,bestMed=0;
    long double ans = -1;
    for(int i=0;i<n;i++)
    {
        int window = min(i,n-1-i);
        int lo = 0,hi = window;
        while(hi-lo > 0)
        {
            int mid = (lo+hi)/2;
            double curr_mean = calc_mean(vec,pref,i,mid);
            // cout << i << " " << curr_mean <<  " " << lo << " " << hi << "**\n";
            int upd_mid = mid+1;
            int a = vec[n-upd_mid];
            int b = vec[i-upd_mid];
            // cout << a << " " << " " << b << " &&\n";
            if(double(a+b)/2 <= curr_mean)
            {
                hi = max(lo,mid);
            }
            else lo = min(mid+1,hi);
            // cout << i << " " << lo <<  " " << hi << "***\n";
        }
        double fin_mean = calc_mean(vec,pref,i,lo);
        if(fin_mean - vec[i] > ans)
        {
            ans = fin_mean-vec[i];
            bestK = lo;
            bestMed = i;
        }
        // cout << i << " " << fin_mean << " " << bestK << " " << bestMed << " " << ans << " ~\n";
    }
    cout << 2*bestK + 1 << endl;
    for(int i = 0; i < bestK; i++){
        cout << vec[n-1-i] << " ";
    }
    
    for(int j = 0; j < bestK+1; j++){
        cout << vec[bestMed-j] << " ";
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
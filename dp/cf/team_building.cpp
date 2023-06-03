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
int aud_rat[100002];
bool cmp(int x,int y)
{
    return (aud_rat[x] > aud_rat[y]);
}

void solve()
{
    int n, p, k;
    cin >> n >> p >> k;
    // int aud_rat[n+1];
    // indices array is to store the indexes of the the people with the highest rating first.
    int indices[n+1];
    for(int i=1;i<=n;i++)
    {
        cin >> aud_rat[i];
        indices[i]=i;
    }
    int strengths[n+1][p];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < p; j++)
            cin >> strengths[i][j];
    sort(indices+1,indices+n+1,cmp);
    // dp[i][mask] denotes the max strength possible till index i with mask denoting the selected players bitstream.
    // Transition: dp[i][mask] = dp[i-1][mask ^ (pow(2,j))] + strength[i][j] where j is the position for which the ith person is selected to play.
    int bitsize = (1LL << p);
    int dp[n+1][bitsize];
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int idx = indices[i];
        for(int mask = 0;mask<bitsize;mask++)
        {
            int cnt = 0;
            for(int j=0;j<p;j++)
            {
                if(mask&(1<<j)) cnt++;
            }
            int free_players = i-1-cnt;
            if(free_players<k)
            {
                if(dp[i-1][mask]!=-1)
                {
                    dp[i][mask] = dp[i-1][mask] + aud_rat[idx]; 
                }
            }
            else
            {
                if(dp[i-1][mask]!=-1)
                {
                    dp[i][mask] = dp[i-1][mask];
                }
            }
            for(int j=0;j<p;j++)
            {
                if((mask&(1<<j)) && dp[i-1][mask^(1<<j)] != -1)
                {
                    dp[i][mask] = max(dp[i][mask],dp[i-1][mask^(1<<j)]+strengths[idx][j]);
                }
            }
        }
    }
    cout<<dp[n][(1<<p)-1]<<"\n";
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
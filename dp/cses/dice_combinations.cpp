#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pa;
typedef vector<pa> vp;
#define pb push_back
#define sz(a) (int)(a.size())
#define endl "\n"
#define mod 1000000007
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

ll n;
vi dp(n + 1);

ll recurse(ll n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = ((recurse(n - 1) + recurse(n - 2) + recurse(n - 3) + recurse(n - 4) + recurse(n - 5) + recurse(n - 6)) % mod);
}

void solve()
{
    ll n;
    cin >> n;
    dp.assign(n + 1, -1);
    ll val = recurse(n);
    cout << val;
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
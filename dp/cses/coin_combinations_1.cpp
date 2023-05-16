#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
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

ll x;
vi dp(x + 1);

ll recurse(ll target, ll n, vi &values)
{
    if (target < 0)
    {
        return 0;
    }
    if (target == 0)
    {
        return 1;
    }
    if (dp[target] != -1)
    {
        return dp[target];
    }
    ll val = 0;
    for (int i = 0; i < n; i++)
    {
        val += recurse(target - values[i], n, values);
        val %= mod;
    }
    return dp[target] = val;
}

void solve()
{
    ll n;
    cin >> n >> x;
    vi values(n + 1);
    dp.assign(x + 1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    ll val = recurse(x, n, values);
    cout << val << endl;
    return;
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
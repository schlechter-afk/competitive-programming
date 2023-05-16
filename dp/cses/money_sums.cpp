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
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

int recurse(ll target, vi &coins)
{
    dp[target] =
}

void solve()
{
    ll n;
    cin >> n;
    vi coins(n);
    ll maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
        maxsum += coins[i];
    }

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = 0; j <= maxsum; j++)
        {
            dp[j] = dp[j - 1] dp[j] = dp[j - 1] + j - coins[i];
        }
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
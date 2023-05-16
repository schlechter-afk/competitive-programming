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
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

// using multiset approach below

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vi vec(n + 1, 0);
    vi prefsum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
        prefsum[i] = prefsum[i - 1] + vec[i];
    }
    multiset<ll> ms;
    ll ans = -2e18;
    for (int i = a; i <= n; i++)
    {
        if (i > b)
        {
            ms.erase(ms.find(prefsum[i - b - 1]));
        }
        ms.insert(prefsum[i - a]);
        ans = (ll)max(ans, (ll)prefsum[i] - *ms.begin());
    }
    cout << ans << endl;
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
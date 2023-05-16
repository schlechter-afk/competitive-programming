#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pa;
typedef vector<pa> vp;
#define pb push_back
#define sz(a) (int)(a.size())
// #define endl "\n"
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

vi prefsum(200005, 0);

ll check(int x)
{
    cout << "? " << x << " ";
    for (int j = 1; j <= x; j++)
        cout << j << " ";
    cout << endl;
    ll val;
    cin >> val;
    return (val != prefsum[x]);
}

void solve()
{
    int n;
    cin >> n;
    vi piles(n + 1);
    prefsum.assign(n + 1,0);
    for (int i = 1; i <= n; i++)
    {
        cin >> piles[i];
        prefsum[i] = prefsum[i - 1] + piles[i];
    }
    int lo = 1, hi = n;
    int ans = n;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        // cout << check(mid) << "**\n";
        if (check(mid))
        {
            hi = mid - 1;
            ans = mid;
        }
        else lo = mid + 1;
    }
    cout << "! " << ans << endl;
}

int main()
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
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

void solve()
{
    ll n, k;
    cin >> n >> k;
    vi vec(n);
    ll sum = 0;
    ll maxval = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        sum += vec[i];
        maxval = max(maxval, vec[i]);
    }
    ll lo = maxval, hi = sum, ans = 0;
    while (hi >= lo)
    {
        ll mid = (lo + hi) / 2;
        bool flag = false;
        bool err = false;
        ll tsum = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            if (vec[i] > mid) err = true;
            tsum += vec[i];
            if (tsum > mid)
            {
                tsum = vec[i];
                count++;
            }
        }
        count++;
        if (count <= k && !err) flag = true;
        if (flag)
        {
            hi = mid - 1;
            ans = mid;
        }
        else lo = mid + 1;
    }
    cout << ans;
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
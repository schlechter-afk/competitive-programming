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

vi genseq(vi &arr, int idx, int offset, int mod)
{
    vi vec;
    for (int mask = 0; mask < (1LL << idx); mask++)
    {
        ll sum = 0;
        for (int j = 0; j < idx; j++)
        {
            if ((1LL << j) & mask)
            {
                sum += arr[j + offset];
                sum %= mod;
            }
        }
        vec.push_back(sum);
    }
    return vec;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll fhalf = n / 2;
    ll lhalf = n - fhalf;
    vi fh = genseq(arr, fhalf, 0, m);
    vi lh = genseq(arr, lhalf, fhalf, m);
    sort(fh.begin(), fh.end());
    sort(lh.begin(), lh.end());
    ll ans = INT_MIN;
    for (auto ele : fh)
    {
        int idx = lower_bound(lh.begin(), lh.end(), m - ele) - lh.begin();
        idx--;
        ans = max(ans, ele + lh[idx]);
    }
    cout << ans << "\n";
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
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

void solve()
{
    ll n;
    cin >> n;
    vp times(n);
    for (int i = 0; i < n; i++)
    {
        cin >> times[i].second >> times[i].first;
    }
    sort(times.begin(), times.end());
    int curr = -1;
    int cnt = 0;
    for (auto time : times)
    {
        if (time.second >= curr)
        {
            curr = time.first;
            cnt++;
        }
    }
    cout << cnt << "\n";
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
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
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vi pref(n + 2, 0);
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + (str[i] == '0');
    }
    int lo = 0, hi = n;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        int win = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '0')
            {
                int up_idx = min(i + mid + 1, n);
                int lo_idx = max(i - mid, 0);
                int val = pref[up_idx] - pref[lo_idx];
                // cout << i << " " << mid << "**\n";
                // cout << val << "*\n";
                win = max(win, val);
            }
        }
        if (win > k) hi = mid;
        else lo = mid;
    }
    cout << hi << endl;
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
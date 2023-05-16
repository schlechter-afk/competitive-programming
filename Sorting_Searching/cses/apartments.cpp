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
    int n, m, k;
    cin >> n >> m >> k;
    vi reqs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> reqs[i];
    }
    vi sizes(m);
    for (int i = 0; i < m; i++)
    {
        cin >> sizes[i];
    }
    sort(reqs.begin(), reqs.end());
    sort(sizes.begin(), sizes.end());
    int ptr1 = 0, ptr2 = 0, ans = 0;
    while (ptr1 < n && ptr2 < m)
    {
        // req - siz <= k || siz - req <= k or req <= size + k or siz <= req + k 
        if ((reqs[ptr1] >= sizes[ptr2] - k) && (reqs[ptr1] <= sizes[ptr2] + k))
        {
            ptr1++;
            ptr2++;
            ans++;
        }
        else if (sizes[ptr2] + k < reqs[ptr1])
        {
            ptr2++;
        }
        else ptr1++;
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
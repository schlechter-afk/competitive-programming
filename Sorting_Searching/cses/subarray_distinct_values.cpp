#include <bits/stdc++.h>

using namespace std;
#define int long long int
typedef int ll;
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
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    map<ll, int> freq;
    int left = 0, right = 0, ans = 0, distinct = 0;
    while(left < n)
    {
        while(right < n)
        {
            if(!freq[vec[right]] && distinct == k) break;
            if(!freq[vec[right]]) distinct++;
            freq[vec[right]] += 1;
            right++;
        }
        ans += (right - left);
        if (freq[vec[left]] == 1) distinct--,freq.erase(vec[left]);
        else freq[vec[left]] -= 1;
        left++;
    }
    cout << ans << "\n";
}

signed main()
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
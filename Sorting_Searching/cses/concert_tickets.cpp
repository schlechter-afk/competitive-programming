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

void solve(int &ans)
{
    ll n, m;
    cin >> n >> m;
    multiset<int> si;
    vi limit(m);
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        si.insert(v);
    }
    for (int i = 0; i < m; i++)
    {
        int v;
        cin >> v;
        auto it = si.upper_bound(v);
        if(it == si.begin())
        {
            ans = -1;
        }
        else
        {
            ans = *(--it);
            si.erase(it);
        }
        cout << ans << endl;
    }
    return;
}

int main()
{
    speed;
    ll tc = 1;
    // cin >> tc;
    while (tc--)
    {
        int ans = 0;
        solve(ans);
    }
    return 0;
}
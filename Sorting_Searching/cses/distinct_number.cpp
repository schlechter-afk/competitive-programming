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
    int n;
    cin >> n;
    vi vec(n);
    unordered_set<int> si;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        if (si.find(vec[i]) == si.end())
        {
            si.insert(vec[i]);
            res++;
        }
    }
    cout << res;
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
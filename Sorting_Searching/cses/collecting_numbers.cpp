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
    vi vec(n+1);
    vi ind(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
        ind[vec[i]] = i;
    }
    int cnt = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        cnt += (ind[i] > ind[i + 1]);
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
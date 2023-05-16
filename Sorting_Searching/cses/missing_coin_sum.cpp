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
    ll n;
    cin >> n;
    vi vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    ll nf = 1;
    for (int i = 0; i < n; i++)
    {
        if(vec[i] > nf)
        {
            cout << nf << "\n";
            return;
        }
        nf += vec[i];
    }
    cout << nf << "\n";
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
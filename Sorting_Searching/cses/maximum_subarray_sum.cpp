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
    vi vec(n);
    for(int i=0;i<n;i++)
    {
        cin >> vec[i];
    }
    ll summax = INT_MIN;
    ll sum = 0;
    for(auto v:vec)
    {
        sum = max(sum+v,(ll)v);
        summax = max(sum,summax);
    }
    cout << summax;
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
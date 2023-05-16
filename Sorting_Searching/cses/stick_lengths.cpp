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
    int n;
    cin >> n;
    vi vec(n);
    for(int i=0;i<n;i++) cin >> vec[i];
    sort(vec.begin(),vec.end());
    ll sum = 0;
    if(n%2)
    {
        for(auto v:vec)
        {
            sum += abs(v-vec[n/2]);
        }
    }
    else
    {
        ll sum1=0,sum2=0;
        for(auto v:vec)
        {
            sum1 += abs(v-vec[(n-1)/2]);
            sum2 += abs(v-vec[(n+1)/2]);
            sum = min(sum1,sum2);
        }
    }
    cout << sum;
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
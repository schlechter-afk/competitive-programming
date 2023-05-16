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
    vi vec(n + 1);
    vi store(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
        store[i]=vec[i];
    }
    sort(vec.begin(),vec.end());
    if(vec[1]!=1)
    {
        cout << "NO\n";
        return;
    }
    ll sum=1;
    for(int i=2;i<=n;i++)
    {
        // cout << sum << " " << vec[i] << "*\n";
        if(sum<vec[i])
        {
            cout << "NO\n";
            return;
        }
        sum+=vec[i];
    }
    cout << "YES\n";
}

int main()
{
    speed;
    ll tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}

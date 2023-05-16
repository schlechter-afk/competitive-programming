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
    ll n, x;
    cin >> n >> x;
    vi vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    int ptr1 = 0, ptr2 = n - 1;
    int ans = 0;
    while (ptr1 < ptr2)
    {
        if (vec[ptr1] + vec[ptr2] <= x)
        {
            ptr1++;
            ptr2--;
            ans++;
        }
        else
        {
            ptr2--;
            ans++;
        }
    }
    if(ptr1 == ptr2) ans++;
    cout << ans << "\n";
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